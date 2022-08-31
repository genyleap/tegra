#include "setup.hpp"
#include "core/core.hpp"
#include "core/system.hpp"
#include <filesystem>

TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra::Installer)

namespace fs = std::filesystem;

Setup::Setup(const ApplicationData& appData, const InstallerData& installerData)
{
    __tegra_safe_instance(m_installerDataPtr, InstallerData);
    __tegra_safe_instance(appDataPtr, ApplicationData);
    {
        m_installerDataPtr->requirements    = installerData.requirements;
        m_installerDataPtr->eula            = installerData.eula;
        m_installerDataPtr->application     = installerData.application;
        m_installerDataPtr->serverDertail   = installerData.serverDertail;
        m_installerDataPtr->customization   = installerData.customization;
        m_installerDataPtr->installation    = installerData.installation;
        m_installerDataPtr->finished        = installerData.finished;
        m_installerDataPtr->level           = installerData.level;
    }
    
    // Default services that are enabled always.
    m_installableApps = defaultBaseApps();
    appDataPtr->path = appData.path.value();
    requiresList();
}

Setup::~Setup()
{
    __tegra_safe_delete(m_installerDataPtr);
    __tegra_safe_delete(appDataPtr);
}

const std::map<std::string, bool> Setup::defaultBaseApps() __tegra_noexcept
{
    std::map<std::string, bool> defApps;
    {
        defApps.insert(std::pair<std::string, bool>("core", true));
        defApps.insert(std::pair<std::string, bool>("cms", true));
        defApps.insert(std::pair<std::string, bool>("statics", true));
        defApps.insert(std::pair<std::string, bool>("blog", true));
    }
    return defApps;
}

std::map<std::string, bool> Setup::defaultAppsList() __tegra_noexcept
{
    m_defaultAppsList.insert(std::pair<std::string, bool>("core", true));
    m_defaultAppsList.insert(std::pair<std::string, bool>("cms", true));
    m_defaultAppsList.insert(std::pair<std::string, bool>("statics", true));
    m_defaultAppsList.insert(std::pair<std::string, bool>("blog", true));
    m_defaultAppsList.insert(std::pair<std::string, bool>("news", false));
    m_defaultAppsList.insert(std::pair<std::string, bool>("sendfeedback", false));
    m_defaultAppsList.insert(std::pair<std::string, bool>("conversation", false));
    m_defaultAppsList.insert(std::pair<std::string, bool>("commerce", false));
    m_defaultAppsList.insert(std::pair<std::string, bool>("clubs", false));
    m_defaultAppsList.insert(std::pair<std::string, bool>("forums", false));

    return m_defaultAppsList;
}

std::map<std::string, bool> Setup::installableApps()
{
    return m_installableApps;
}

RequireList Setup::requiresList()
{
    //! Compiler
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    if (fs::exists("/usr/bin/clang") || fs::exists("/usr/bin/gcc")) {
        m_requireList.compiler = true;
    } else {
        m_requireList.compiler = false;
    }
#elif defined(PLATFORM_WINDOWS)
    std::string username{SystemInfo::getHostUserName()};
    if (fs::exists("c:/..."))
    /// ToDo...
    {
        m_requireList.compiler = true;
    } else {
        m_requireList.compiler = false;
    }
#endif
    //! OpenSSL
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    if (fs::exists("/usr/bin/openssl")) {
        m_requireList.openssl = true;
    } else {
        m_requireList.openssl = false;
    }
#elif defined(PLATFORM_WINDOWS)
    if (fs::exists("c:/..."))
    /// ToDo...
    {
        m_requireList.openssl = true;
    } else {
        m_requireList.openssl = false;
    }
#endif
    //! cUrl
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    if (fs::exists("/usr/bin/curl")) {
        m_requireList.curl = true;
    } else {
        m_requireList.curl = false;
    }
#elif defined(PLATFORM_WINDOWS)
    if (fs::exists("c:/...")) {
        m_requireList.curl = true;
    } else {
        m_requireList.curl = false;
    }
#endif
    //! Framework
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    if (fs::exists("/usr/local/bin/drogon_ctl")) {
        m_requireList.framework = true;
    } else {
        m_requireList.framework = false;
    }
#elif defined(PLATFORM_WINDOWS)
    std::string filePath{};
    filePath.append("c:\\Users\\");
    filePath.append(SystemInfo::getHostUserName());
    filePath.append("\\drogon");
    if(fs::exists(filePath)
            ///ToDo...
    {
        m_requireList.framework = true; } else {
        m_requireList.framework = false; }
#endif
    //! PostgreSQL
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    if (fs::exists("/opt/homebrew/bin/psql")) {
        m_requireList.postgresql = true;
    } else {
        m_requireList.postgresql = false;
    }
#elif defined(PLATFORM_WINDOWS)
            if(fs::exists("c:/..."))
            ///ToDo...
    {
        m_requireList.postgresql = true; } else {
        m_requireList.postgresql = false; }
#endif
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    if (fs::exists("/opt/homebrew/bin/psql")) {
        m_requireList.mysql = true;
    } else {
        m_requireList.mysql = false;
    }
#elif defined(PLATFORM_WINDOWS)
            if(fs::exists("c:/..."))
            ///ToDo...
    {
        m_requireList.mysql = true; } else {
        m_requireList.mysql = false; }
#endif
    return m_requireList;
}

SetupLevelInfo Setup::setupLevelInfo()
{
    return m_setupLevelInfo;
}

bool Setup::checkRequire() __tegra_noexcept
{   
    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());

    m_setupLevelInfo.name           =   "check";
    m_setupLevelInfo.title          =   TEGRA_TRANSLATOR("setup", "step_initialization");
    m_setupLevelInfo.description    =   TEGRA_TRANSLATOR("setup", "wizard_message");
    m_setupLevelInfo.details        =   TEGRA_TRANSLATOR("setup", "installer_quide_message");
    m_setupLevelInfo.message        =   TEGRA_TRANSLATOR("setup", "installer_resource_message");

    RquireTypes rlist{};
    if (m_installerDataPtr->level == SetupLevel::Requirements) {
        if (m_requireList.compiler.value()) {
            rlist.insert(RquireTypesPair("compiler", true));
        } else {
            rlist.insert(RquireTypesPair("compiler", false));
        }
        if (m_requireList.openssl.value()) {
            rlist.insert(RquireTypesPair("openssl", true));
        } else {
            rlist.insert(RquireTypesPair("openssl", false));
        }
        if (m_requireList.curl.value()) {
            rlist.insert(RquireTypesPair("curl", true));
        } else {
            rlist.insert(RquireTypesPair("curl", false));
        }
        if (m_requireList.framework.value()) {
            rlist.insert(RquireTypesPair("framework", true));
        } else {
            rlist.insert(RquireTypesPair("framework", false));
        }
        if (m_requireList.postgresql.value()) {
            rlist.insert(RquireTypesPair("postgresql", true));
        } else {
            rlist.insert(RquireTypesPair("postgresql", false));
        }
        if (m_requireList.mysql.value()) {
            rlist.insert(RquireTypesPair("mysql", true));
        } else {
            rlist.insert(RquireTypesPair("mysql", false));
        }
        registerRequires(rlist);
        return true;
    } else {
        return false;
    }
}

void Setup::registerRequires(const RquireTypes& rlist)
{
    m_rlist = rlist;
}

RquireTypes Setup::requirementList()
{
    return m_rlist;
}

bool Setup::eula(const bool read) __tegra_noexcept
{
    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());
    
    m_setupLevelInfo.name           =   "eula";
    m_setupLevelInfo.title          =   TEGRA_TRANSLATOR("setup", "step_license");

    if (m_installerDataPtr->level == SetupLevel::Eula)
        return read ? true : false;
    return false;
}

bool Setup::application(const std::map<std::string, bool>& appList) __tegra_noexcept
{
    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());

    m_setupLevelInfo.name           =   "applications";
    m_setupLevelInfo.title          =   TEGRA_TRANSLATOR("setup", "step_applications");

    for(const auto & app : appList)
    {
        m_installableApps.insert(PairEnable(app.first, app.second));
    }
    return m_installerDataPtr->level == SetupLevel::Application ? true : false;
}

bool Setup::serverDertail(const ServerData& serverData) __tegra_noexcept
{
    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());

    m_setupLevelInfo.name       =   "serverinfo";
    m_setupLevelInfo.title      =   TEGRA_TRANSLATOR("setup", "step_server_info");

    m_serverData.hostName       =   serverData.hostName;
    m_serverData.dbname         =   serverData.dbname;
    m_serverData.dbpass         =   serverData.dbpass;
    m_serverData.driver         =   serverData.driver;
    m_serverData.cdn            =   serverData.cdn;
    m_serverData.dbPort         =   serverData.dbPort;
    m_serverData.username       =   serverData.username;
    m_serverData.password       =   serverData.password;
    m_serverData.firstName      =   serverData.firstName;
    m_serverData.lastName       =   serverData.lastName;
    m_serverData.dbCharset      =   serverData.dbCharset;
    m_serverData.tablePrefix    =   serverData.tablePrefix;

    // ToDo...
    // Database Manager...
    return m_installerDataPtr->level == SetupLevel::ServerDetail ? true : false;
}

bool Setup::customization() __tegra_noexcept
{   
    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());
    m_setupLevelInfo.name           =   "customization";
    m_setupLevelInfo.title          =   TEGRA_TRANSLATOR("setup", "step_customization");

    // ToDo...
    return m_installerDataPtr->level == SetupLevel::Customize ? true : false;
}

bool Setup::installation() __tegra_noexcept
{
    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());
    m_setupLevelInfo.name           =   "customization";
    m_setupLevelInfo.title          =   TEGRA_TRANSLATOR("setup", "step_finalizing");
    // ToDo...
    // Database Manager...
    // m_privateInstallerData.done = true; // if was success
    return m_installerDataPtr->level == SetupLevel::Install ? true : false;
}

bool Setup::finished() __tegra_noexcept
{
    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());

    m_setupLevelInfo.name           =   "finished";
    m_setupLevelInfo.title          =   TEGRA_TRANSLATOR("setup", "step_ready");

    if (m_installerDataPtr->level == SetupLevel::Finalize)
        return m_privateInstallerData.done ? true : false;
    return false;
}

TEGRA_NAMESPACE_END
