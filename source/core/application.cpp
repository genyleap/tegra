//! Tegra's Application.
#ifdef __has_include
# if __has_include("application.hpp")
#   include "application.hpp"
#else
#   error "Tegra's application was not found!"
# endif
#endif

//! CMake's Config.
#ifdef __has_include
# if __has_include("config.hpp")
#   include "config.hpp"
#else
#   error "Tegra's config was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;
TEGRA_USING_NAMESPACE Tegra::Database;
TEGRA_USING_NAMESPACE Tegra::Abstracts;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Module;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Plugin;

TEGRA_NAMESPACE_BEGIN(Tegra)

Application::Application(const ApplicationData& appData)
{
    __tegra_safe_instance_rhs(language, Multilangual::Language, appData.path.value_or(__tegra_unknown));
    __tegra_safe_instance(translator, Translation::Translator);
    __tegra_safe_instance(appDataPtr, ApplicationData);
    __tegra_safe_instance(appInfoPtr, ApplicationInfo);
    __tegra_safe_instance(pageArchivePtr, PageArchive);
    ///!Smart Scopes
    {
        __tegra_smart_instance(engine, Engine);
        __tegra_smart_instance(version, Version);
    }
    ///!Inits
    {
        if(!appInfoPtr->systemInfo.license.has_value())
            appInfoPtr->systemInfo.license = SystemLicense::Free;
        if(!appInfoPtr->systemInfo.type.has_value())
            appInfoPtr->systemInfo.type = SystemType::Default;

        appInfoPtr->releaseType = Version::ReleaseType::Alpha;
        version->setVersion(appInfoPtr->semanticVersion, appInfoPtr->releaseType);
        appDataPtr->path = appData.path.value_or(__tegra_unknown);
        appDataPtr->page = appData.page;
        {
            systemInfo.name = appInfoPtr->systemInfo.name;
            systemInfo.codeName = appInfoPtr->systemInfo.codeName;
            systemInfo.compiledDate = appInfoPtr->systemInfo.compiledDate;
            systemInfo.license = appInfoPtr->systemInfo.license;
            systemInfo.type = appInfoPtr->systemInfo.type;
            systemInfo.version = appInfoPtr->systemInfo.version;
            systemInfo.version->PreRelease = appInfoPtr->systemInfo.version->PreRelease;
        }
    }
}

Application::~Application()
{
    __tegra_safe_delete(translator);
    __tegra_safe_delete(appDataPtr);
    __tegra_safe_delete(appInfoPtr);
    __tegra_safe_delete(pageArchivePtr);
    __tegra_safe_delete(language);
}
__tegra_no_discard SystemInfo Application::getSystemInfo() __tegra_const_noexcept
{
    auto semanticVersion = SemanticVersion();      ///< Semantic Version
    auto sysInfo = SystemInfo();                   ///< System Info
    // Configuration before use
    semanticVersion.Major = PROJECT_VERSION_MAJOR;
    semanticVersion.Minor = PROJECT_VERSION_MINOR;
    semanticVersion.Patch = PROJECT_VERSION_PATCH;
    semanticVersion.PreRelease = PROJECT_VERSION_TYPE;
    version->setVersion(semanticVersion, appInfoPtr->releaseType);
    sysInfo.version = systemInfo.version;
    sysInfo.version->PreRelease = systemInfo.version->PreRelease;
    sysInfo.codeName = "concept";
    sysInfo.developer = PROJECT_CREATOR;
    sysInfo.model = "basic";
    sysInfo.name = PROJECT_NAME;
    sysInfo.compiledDate = __tegra_compiled_date;
    sysInfo.license = SystemLicense::Free;
    sysInfo.type = SystemType::General;
    return sysInfo;
}
Application* Application::appPtr;

ApplicationData* Application::appDataPtr;

ApplicationInfo* Application::appInfoPtr;

//PageData* Application::pageDataPtr;

Application* Application::get(const ApplicationData& appData)
{
    if (!appPtr)
    {
        __tegra_safe_instance_rhs(appPtr, Application, appData);
        {
            appPtr->path() = appData.path.value_or(__tegra_unknown);
            appDataPtr->path = appData.path.value_or(__tegra_unknown);
            appDataPtr->page = appData.page;
        }
    }
    return appPtr;
}

void Application::start()
{
    auto appData = ApplicationData();              ///< Application Data
    auto version = Version();                      ///< Version
    auto semanticVersion = SemanticVersion();      ///< Semantic Version
    auto con = Connection();                       ///< Connection
    auto config = Configuration(ConfigType::File); ///< Configuration

         // Configuration before use
    config.init(SectionType::SystemCore);
    {   // Set from cmake config.hpp.in
        semanticVersion.Major = PROJECT_VERSION_MAJOR;
        semanticVersion.Minor = PROJECT_VERSION_MINOR;
        semanticVersion.Patch = PROJECT_VERSION_PATCH;
        semanticVersion.PreRelease = PROJECT_VERSION_TYPE;
        version.setVersion(semanticVersion, Tegra::Version::ReleaseType::Alpha);
    }
    // App Data
    {
        appData.path = __tegra_null_str;
        appData.module = "core";
        appInfoPtr->semanticVersion = semanticVersion;
        appInfoPtr->releaseType = Tegra::Version::ReleaseType::Alpha;
    }

    if(System::DeveloperMode::IsEnable)
        Log("Engine started!", LoggerType::Info); ///< Engine Start...
    {
        Console::print << "Starting..." << newline;
        Console::print << "=================[Tegra Core System Info]=================\n";
        Console::print << newline;
        Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << __tegra_space << getSystemInfo().name.value() << ""
                       << " - compiled date on : "
                       << getSystemInfo().compiledDate.value() + " ]" << newline;
        Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " code name : "
                       << getSystemInfo().codeName.value() + " ]"<< " ⇙" << newline;
                                      Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " core version : "
                       << version.getAsString() + " ]"
                       << " ⇙" << newline;
                                      Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " license type : "
                       << this->license().value_or(__tegra_unknown) + " ]"
                       << " ⇙" << newline;
                                      Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " system type : "
                       << this->type().value_or(__tegra_unknown) + " ]"
                       << " ⇙" << newline;
                                      Console::print << newline;
        Console::print << Terminal::NativeTerminal::Default;
        Console::print << "=================[--------------]=================\n";
        Console::print << newline;
    }
}

OptionalString Application::path() __tegra_const_noexcept
{
    if(appDataPtr->path == __tegra_unknown) {
        if(DeveloperMode::IsEnable)
            Log("No valid uri![Application::path()]", LoggerType::Critical);
        Log("[Application::path() == 'unknown' as ApplicationData]", LoggerType::Critical);
    }
    return appDataPtr->path.value_or(__tegra_unknown);
}

OptionalString Application::name() __tegra_const_noexcept
{
    return systemInfo.name.value_or(__tegra_unknown);
}

OptionalString Application::codeName() __tegra_const_noexcept
{
    return systemInfo.codeName.value_or(__tegra_unknown);
}

OptionalString Application::type() __tegra_const_noexcept
{
    std::string res{};
    switch (systemInfo.type.value()) {
    case SystemType::Private:
        res = "Private";
        break;
    case SystemType::General:
        res = "General";
        break;
    case SystemType::Professional:
        res = "Professional";
        break;
    case SystemType::Premium:
        res = "Premium";
        break;
    case SystemType::Default:
        res = "Default";
        break;
    default:
        res = "Default";
        break;
    }
    return res;
}

OptionalString Application::license() __tegra_const_noexcept
{
    std::string res{};
    switch (systemInfo.license.value()) {
    case SystemLicense::Commercial:
        res = "Commercial";
        break;
    case SystemLicense::Free:
        res = "Free";
        break;
    default:
        res = "Free";
        break;
    }
    return res;
}

OptionalString Application::model() __tegra_const_noexcept
{
    return systemInfo.codeName.value_or(__tegra_unknown);
}

__tegra_no_discard std::vector<ModuleInfo> Application::modules() __tegra_noexcept
{
    return m_moduleInfoList;
}

void Application::registerModules(const std::vector<ModuleInfo>& modulesList) __tegra_noexcept
{
    m_moduleInfoList = modulesList;
}

std::vector<PluginInfo> Application::plugins() __tegra_noexcept
{
    return m_pluginInfoList;
}

void Application::registerPlugins(const std::vector<PluginInfo>& pluginsList) __tegra_noexcept
{
    m_pluginInfoList = pluginsList;
}

OptionalString Application::module() __tegra_const_noexcept
{
    return appDataPtr->module.value_or(__tegra_unknown);
}

OptionalString Application::templateViewErrorId() __tegra_const_noexcept
{
    return appDataPtr->templateViewErrorId.value_or(__tegra_unknown);
}

OptionalString Application::templateViewId() __tegra_const_noexcept
{
    return appDataPtr->templateViewId.value_or(__tegra_unknown);
}

TEGRA_NAMESPACE_END
