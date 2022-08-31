#include "analyzer.hpp"
#include "core.hpp"
#include "logger.hpp"
#include "regex.hpp"
#include "modulemanager.hpp"

TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Regexation;
TEGRA_USING_NAMESPACE Tegra::eLogger;
TEGRA_USING_NAMESPACE Framework;

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
    std::string lastMessage{__tegra_null_str};
    const std::string currentPath(fileSystem::current_path());
    if(isset(std::filesystem::exists(currentPath + "/" + CONFIG::SYSTEM_MODULES_FOLDER.data() + "/" + moduleName)))
    {
        if(isSupported(moduleName))
            lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR(MODULES, "initialized"),
                                               TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(moduleName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Success);
        m_moduleAnalyzerData.isExist = true;
    } else {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR(MODULES, "not_found"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(moduleName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Critical);
        m_moduleAnalyzerData.isExist = false;
    }
    if(isset(lastMessage)) {
        m_moduleAnalyzerData.message = lastMessage;
    }
    return m_moduleAnalyzerData.isExist;
}

__tegra_no_discard bool ModuleAnalyzer::isOfficial(const std::string& moduleName) __tegra_noexcept
{
    std::string lastMessage{__tegra_null_str};
    m_moduleAnalyzerData.isOfficial = false;
    if(isset(lastMessage)) {
        m_moduleAnalyzerData.message = lastMessage;
    }
    return m_moduleAnalyzerData.isOfficial;
}

__tegra_no_discard bool ModuleAnalyzer::isSupported(const std::string& moduleName) __tegra_noexcept
{
    std::string lastMessage{__tegra_null_str};
    if(isset(fileSystem::path(moduleName).extension() != CONFIG::MODULE_FILE_SUFFIX.data()))
    {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR(MODULES, "not_supported"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(moduleName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Critical);
        m_moduleAnalyzerData.isOfficial = false;
    } else {
        m_moduleAnalyzerData.isOfficial = true;
        if(isset(lastMessage)){
            m_moduleAnalyzerData.message = lastMessage;
        }
    }
    return m_moduleAnalyzerData.isSupported;
}

__tegra_no_discard OptionalString ModuleAnalyzer::result() __tegra_noexcept
{
    return m_moduleAnalyzerData.message;
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
        if(isSupported(pluginName))
            lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR(PLUGINS, "initialized"),
                                               TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(pluginName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Success);
        m_moduleAnalyzerData.isExist = true;
    } else {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR(PLUGINS, "no_initialized"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(pluginName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Critical);
        m_moduleAnalyzerData.isExist = false;
    }
    if(isset(lastMessage)){
        m_moduleAnalyzerData.message = lastMessage;
    }
    return m_moduleAnalyzerData.isExist;
}

__tegra_no_discard bool PluginAnalyzer::isSupported(const std::string& moduleName) __tegra_noexcept
{
    std::string lastMessage{__tegra_null_str};
    if(isset(fileSystem::path(moduleName).extension() != CONFIG::PLUGIN_FILE_SUFFIX.data()))
    {
        lastMessage = TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR(PLUGINS, "not_supported"),
                                           TEGRA_FORMAT_ARG("name", FROM_TEGRA_STRING(moduleName)));
        if(System::DeveloperMode::IsEnable)
            Log(lastMessage, LoggerType::Critical);
        m_moduleAnalyzerData.isSupported = false;
    } else {
        m_moduleAnalyzerData.isSupported = true;
        if(isset(lastMessage)){
            m_moduleAnalyzerData.message = lastMessage;
        }
    }
    return m_moduleAnalyzerData.isSupported;
}

__tegra_no_discard OptionalString PluginAnalyzer::result() __tegra_noexcept
{
    return m_moduleAnalyzerData.message;
}

Checksum::Checksum(const CheckType& checkType)
{
    switch (checkType) {
    case CheckType::MD5:
        m_checkSumData.algorithm = "md5sum";
        break;
    case CheckType::SHA1:
        m_checkSumData.algorithm = "sha1sum";
        break;
    case CheckType::SHA256:
        m_checkSumData.algorithm = "sha256sum";
        break;
    case CheckType::SHA512:
        m_checkSumData.algorithm = "sha512sum";
        break;
    default:
        m_checkSumData.algorithm = "md5sum";
        break;
    }
}

Checksum::~Checksum()
{
}

bool Checksum::checkFile(const std::string& path) __tegra_noexcept
{
    //!ToDo for perfect tools by the system path.
    auto regex = Regex();
#if defined(PLATFORM_MAC)
    std::string tool = "/opt/homebrew/bin/"; //Fix for system path.
    tool.append(m_checkSumData.algorithm);
    m_checkSumData.message = command(tool.append(__tegra_space) + "-c" + __tegra_space + path + "/" + m_checkSumData.algorithm + CHECKSUMS_FILE);
#endif
#if defined(PLATFORM_LINUX)
    std::string tool = "/usr/bin/"; //Fix for system path.
    tool.append(m_checkSumData.algorithm);
    m_checkSumData.message = command(tool.append(__tegra_space) + "-c" + __tegra_space + path + "/" + m_checkSumData.algorithm + CHECKSUMS_FILE);
#endif
#if defined(PLATFORM_WINDOWS) //Fix for system path.
    m_checkSumData.message = command("certutil -hashfile " + "-c" + __tegra_space + path + "/" + m_checkSumData.algorithm + CHECKSUMS_FILE);
#endif
    setResult(m_checkSumData.message);
    return regex.findString(m_checkSumData.message, MESSAGE_OK) ? true : false;
    return regex.findString(m_checkSumData.message, MESSAGE_FAILED) ? true : false;
}

bool Checksum::generate(const std::string& file) __tegra_noexcept
{
#if defined(PLATFORM_MAC)
    std::string tool = "/opt/homebrew/bin/";
    tool.append(m_checkSumData.algorithm);
    m_checkSumData.message = command(tool.append(__tegra_space) + file);
#endif
#if defined(PLATFORM_LINUX)
    std::string tool = "/usr/bin/";
    tool.append(m_checkSumData.algorithm);
    m_checkSumData.message = command(tool.append(__tegra_space) + file);
#endif
#if defined(PLATFORM_WINDOWS)
    m_checkSumData.message = command("certutil -hashfile " + file + __tegra_space + m_checkSumData.algorithm);
#endif
    const std::string currentPath(fileSystem::current_path());
    size_t pos = __tegra_zero;
    std::string delim{__tegra_space};
    if(isset(std::filesystem::exists(file))) {
        while((pos = m_checkSumData.message.find(delim)) != std::string::npos)
        {
            m_checkSumData.message = m_checkSumData.message.substr(__tegra_zero, pos);
        }
        setResult(m_checkSumData.message);
        return true;
    } else {
        return false;
    }
}

void Checksum::setResult(const std::string& r) __tegra_noexcept
{
    m_checkSumData.message = r;
}
std::string Checksum::getResult() __tegra_noexcept
{
    return m_checkSumData.message;
}

TEGRA_NAMESPACE_END
