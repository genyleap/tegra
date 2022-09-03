//! Tegra's Application.
#ifdef __has_include
# if __has_include("application.hpp")
#   include "application.hpp"
#else
#   error "Tegra's application was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;
TEGRA_USING_NAMESPACE Tegra::Abstracts;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Module;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Plugin;

TEGRA_NAMESPACE_BEGIN(Tegra)

Application::Application(const ApplicationData& appData)
{
    __tegra_safe_instance_rhs(language, Multilangual::Language, appData.path.value_or(__tegra_unknown));
    __tegra_safe_instance(translator, Translation::Translator);
    __tegra_safe_instance(appDataPtr, ApplicationData);
    ///!Smart Scopes
    {
        __tegra_smart_instance(engine, Engine);
        __tegra_smart_instance(version, Version);
        __tegra_smart_instance(systemInfo, SystemInfo);
    }
    ///!Inits
    {
        version->setVersion(appData.semanticVersion, appData.releaseType);
        appDataPtr->path = appData.path.value_or(__tegra_unknown);
        {
            systemInfo->name = appData.systemInfo.name;
            systemInfo->codeName = appData.systemInfo.codeName;
            systemInfo->compiledDate = appData.systemInfo.compiledDate;
            systemInfo->license = appData.systemInfo.license;
            systemInfo->type = appData.systemInfo.type;
            systemInfo->version = appData.systemInfo.version;
        }
    }
}

Application::~Application()
{
    __tegra_safe_delete(translator);
    __tegra_safe_delete(appDataPtr);
    __tegra_safe_delete(language);
}

Application* Application::appPtr;

ApplicationData* Application::appDataPtr;

Application* Application::get(const ApplicationData& appData)
{
    if (!appPtr)
    {
        __tegra_safe_instance_rhs(appPtr, Application, appData);
        {
            appPtr->path() = appData.path.value_or(__tegra_unknown);
            appDataPtr->path = appData.path.value_or(__tegra_unknown);
            appDataPtr->semanticVersion = appData.semanticVersion;
            appDataPtr->releaseType = appData.releaseType;
        }
    }
    return appPtr;
}

void Application::start()
{
    if(System::DeveloperMode::IsEnable)
        Log("Engine started!", LoggerType::Info); ///< Engine Start...
    {
        Console::print << "Starting..." << newline;
        Console::print << "=================[Tegra System Info]=================\n";
        Console::print << newline;
        Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << __tegra_space << systemInfo->name.value() << ""
                       << " - compiled date on : "
                       << systemInfo->compiledDate.value() + " ]" << newline;
        Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " code name : "
                       << systemInfo->codeName.value() + " ]"<< " ⇙" << newline;
                                      Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " version : "
                       << version->getAsString() + " ]"
                       << " ⇙" << newline;
                                      Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " license type : "
                       << this->license().value() + " ]"
                       << " ⇙" << newline;
                                      Console::print << Terminal::NativeTerminal::Primary << " ⇨ ["
                       << " system type : "
                       << this->type().value() + " ]"
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
    return appDataPtr->systemInfo.name.value_or(__tegra_unknown);
}

OptionalString Application::codeName() __tegra_const_noexcept
{
    return appDataPtr->systemInfo.codeName.value_or(__tegra_unknown);
}

OptionalString Application::type() __tegra_const_noexcept
{
    std::string res{};
    switch (systemInfo->type.value()) {
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
    switch (systemInfo->license.value()) {
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
    return appDataPtr->systemInfo.codeName.value_or(__tegra_unknown);
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
