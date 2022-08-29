#include "analyzer.hpp"
#include "logger.hpp"
#include "translator/language.hpp"
#include "translator/translator.hpp"

TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra::System)

ModuleAnalyzer::ModuleAnalyzer(const ApplicationData& appData)
{
    __tegra_safe_instance(appDataPtr, ApplicationData);
    {
        languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());
        appDataPtr->path = appData.path;
    }
}

ModuleAnalyzer::~ModuleAnalyzer()
{
    __tegra_safe_delete(appDataPtr);
}

namespace fileSystem = std::filesystem;

__tegra_no_discard bool ModuleAnalyzer::isExist(const std::string& moduleName) __tegra_noexcept
{
    const std::string currentPath(fileSystem::current_path());
    std::string lastMessage{__tegra_null_str};
    if(isset(std::filesystem::exists(currentPath + "/" + CONFIG::SYSTEM_MODULES_FOLDER.data() + "/" + moduleName)))
    {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR("modules", "initialized"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(moduleName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Success);
        m_isExist = true;
    } else {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR("modules", "no_initialized"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(moduleName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Critical);
        m_isExist = false;
    }
    if(isset(lastMessage)){
        m_message = lastMessage;
    }
    return m_isExist;
}

__tegra_no_discard OptionalString ModuleAnalyzer::result() __tegra_noexcept
{
    return m_message;
}

PluginAnalyzer::PluginAnalyzer(const ApplicationData& appData)
{
    __tegra_safe_instance(appDataPtr, ApplicationData);
    {
        languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());
        appDataPtr->path = appData.path;
    }
}

PluginAnalyzer::~PluginAnalyzer()
{
    __tegra_safe_delete(appDataPtr);
}

__tegra_no_discard bool PluginAnalyzer::isExist(const std::string& pluginName) __tegra_noexcept
{
    const std::string currentPath(fileSystem::current_path());
    std::string lastMessage{__tegra_null_str};
    if(isset(std::filesystem::exists(currentPath + "/" + CONFIG::SYSTEM_PLUGINS_FOLDER.data() + "/" + pluginName)))
    {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR("plugins", "initialized"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(pluginName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Success);
        m_isExist = true;
    } else {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR("plugins", "no_initialized"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(pluginName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Critical);
        m_isExist = false;
    }
    if(isset(lastMessage)){
        m_message = lastMessage;
    }
    return m_isExist;
}

__tegra_no_discard OptionalString PluginAnalyzer::result() __tegra_noexcept
{
    return m_message;
}


TEGRA_NAMESPACE_END
