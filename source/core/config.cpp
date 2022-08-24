#include "core/core.hpp"
#include "config.hpp"
#include "logger.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra)

Configuration::Configuration(const ConfigType& configType)
{
    m_dataConfig = new DataConfig();
    m_dataConfig->configType = configType;
    switch (configType) {
    case ConfigType::File:
        try {
            std::string cfile { __tegra_null_str };
            cfile = CONFIG::SYSTEM_CONFIG_FILE.data();
            m_dataConfig->configFile = cfile;
            if(!isset(jsonFile().empty())){
                std::ifstream in(cfile);
                m_dataConfig->json = JSon::parse(in);
            }
        }
        catch (const JSon::exception& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Cannot open the file [" + m_dataConfig->configFile + "]", eLogger::LoggerType::Critical);
                eLogger::Log("Error details: " + FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Info);
            }
        }
        break;
    case ConfigType::Database:
        try {
            ///ToDo...
        }
        catch (const Exception& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Configuration Error: " + FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        break;
    }
}

Configuration::Configuration(const ConfigType& configType, const std::string& customFile)
{
    m_dataConfig = new DataConfig();
    m_dataConfig->configType = configType;
    switch (configType) {
    case ConfigType::File:
        try {
            std::string cfile { customFile };
            m_dataConfig->configFile = cfile;
            if(!isset(jsonFile().empty())){
                std::ifstream in(cfile);
                m_dataConfig->json = JSon::parse(in);
            }
        }
        catch (const JSon::exception& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Configuration Error: " + FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case ConfigType::Database:
        try {
            ///ToDo...
        }
        catch (const Exception& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Configuration Error: " + FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        break;
    }
}

Configuration::Configuration(const ConfigType& configType, const SectionType& sectionType)
{
    m_dataConfig = new DataConfig();
    m_dataConfig->configType = configType;
    switch (configType) {
    case ConfigType::File:
        try {
            std::string cfile { __tegra_null_str };
            switch (sectionType) {
            case SectionType::SystemCore:
                cfile = System::CONFIG::SYSTEM_CONFIG_FILE;
                break;
            case SectionType::Database:
                cfile = System::CONFIG::SYSTEM_DATABASE_FILE;
                break;
            default:
                break;
            }
            m_dataConfig->configFile = cfile;
            if(!isset(jsonFile().empty())){
                std::ifstream in(cfile);
                m_dataConfig->json = JSon::parse(in);
            }
        }
        catch (const JSon::exception& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Configuration Error: " + FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case ConfigType::Database:
        try {

        }
        catch (const Exception& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Configuration Error: " + FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        break;
    }
}

Configuration::~Configuration()
{
    __tegra_safe_delete(m_dataConfig);
}

bool Configuration::create(const FileType& fileType)
{
  ///ToDo...
}

void Configuration::init(const SectionType sectionType)
{
    Json::Reader reader{};
    std::ifstream file{};
    switch (sectionType) {
    case SectionType::SystemCore:
        file.open(CONFIG::SYSTEM_CONFIG_FILE.data(), std::ifstream::binary);
        break;
    case SectionType::Database:
        file.open(CONFIG::SYSTEM_DATABASE_FILE.data(), std::ifstream::binary);
        break;
    case SectionType::Interface:
        file.open(CONFIG::SYSTEM_INTERFACE_FILE.data(), std::ifstream::binary);
        break;
    case SectionType::Framework:
        file.open(CONFIG::FRAMEWORK_CONFIG_FILE.data(), std::ifstream::binary);
        break;
    case SectionType::Custom:
        file.open(CONFIG::SYSTEM_CUSTOM_FILE.data(), std::ifstream::binary);
        break;
    default:
        file.open(CONFIG::SYSTEM_CONFIG_FILE.data(), std::ifstream::binary);
        break;
    }
    if (reader.good())
    {
        if(file.is_open())
            reader.parse(file, GET);
    }
    file.close();
}

void Configuration::registerFile(const VectorString& files)
{
    m_files = files;
}

bool Configuration::status()
{
    std::ifstream file{};
    bool res {false};
    file.open(CONFIG::SYSTEM_CONFIG_FILE.data(), std::ifstream::binary);
    Json::Reader reader;
    file.is_open() ? res = true : res = false;
    return res;
}

VectorString Configuration::files()
{
    return m_files;
}

std::optional<VariableType> Configuration::get()
{
  ///ToDo...
}

void Configuration::write(const KeyValueType& variable)
{
  ///ToDo...
}

template<class> inline constexpr bool always_false_v = false;

void Configuration::update(const KeyValueType& variable)
{
  ///ToDo...
}

void Configuration::remove(const KeyValueType &variable)
{
  ///ToDo...
}

bool Configuration::reset()
{
  ///ToDo...
}

bool Configuration::lock()
{
  ///ToDo...
}

std::string Configuration::getBaseUrl() __tegra_noexcept
{
    std::string url {};
    if(!m_dataConfig->json["protocol"].is_null()) {
        url = m_dataConfig->json["protocol"];
    } else {
        eLogger::Log("Error config parsing: ", eLogger::LoggerType::Critical);
    }
    //url.append(m_dataConfig->setting->getOption("trusted_domains"));
    url.append("localhost");
    return url;
}

bool Configuration::isInstalled() __tegra_noexcept
{
    bool var { false };
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["installed"].is_null()) {
            var = m_dataConfig->json["installed"];
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
    return var;
}

void Configuration::lockInstall() __tegra_noexcept
{
    bool var { false };
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["installed"].is_null())
        {
            auto& object = m_dataConfig->json["installed"];
            object["installed"] = true;
            std::ofstream out(jsonFile());
            out << std::setw(4) << m_dataConfig->json;
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
}

std::string Configuration::jsonFile() __tegra_noexcept
{
    std::string file { __tegra_null_str };
    if(!isset(m_dataConfig->configFile.empty()))
    {
        file = m_dataConfig->configFile;
    } else {
        eLogger::Log("Please specify a config file and try again! ", eLogger::LoggerType::Critical);
    }
    return file;
}

void Configuration::system(const std::string &debug,
                           const std::string &cookiePrefix,
                           const std::string &tablePrefix,
                           const std::string &tableValueStruct,
                           const std::string &tableUnicode,
                           const std::string &defaultLanguage) __tegra_noexcept
{

}

void Configuration::database(const std::string &rdbms,
                             const std::string &host,
                             const std::string &name,
                             const std::string &username,
                             const std::string &password,
                             const std::string &port) __tegra_noexcept
{

    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["database"].is_null()) {
            auto& array = m_dataConfig->json.at("database");
            for (auto&& val:array){
                if(rdbms == "postgresql" && val["rdbms"]=="postgresql") {
                    val["host"]         = host;
                    val["name"]         = name;
                    val["username"]     = username;
                    val["password"]     = password;
                    val["port"]         = port;
                }
                if(rdbms == "mysql" && val["rdbms"]=="mysql") {
                    val["host"]         = host;
                    val["name"]         = name;
                    val["username"]     = username;
                    val["password"]     = password;
                    val["port"]         = port;
                }
            }
            std::ofstream out(jsonFile());
            out << std::setw(4) << m_dataConfig->json;
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
}

void Configuration::feature(const std::string &dynamic,
                            const std::string &crossMode) __tegra_noexcept
{
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["features"].is_null()) {
            auto& array = m_dataConfig->json.at("features");
            for (auto&& val:array){
                val["dynamic"]      = dynamic;
                val["crossMode"]    = crossMode;
            }
            std::ofstream out(jsonFile());
            out << std::setw(4) << m_dataConfig->json;
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
}

void Configuration::maintenance(const std::string &backupPath,
                                const std::string &experimentalUpdate,
                                const std::string &update,
                                const std::string &dbBackUpPath) __tegra_noexcept
{
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["maintenance"].is_null()) {
            auto& array = m_dataConfig->json.at("maintenance");
            for (auto&& val:array){
                val["backup_path"]          = backupPath;
                val["experimental_update"]  = experimentalUpdate;
                val["update"]               = update;
                val["db_bakup_path"]        = dbBackUpPath;
            }
            std::ofstream out(jsonFile());
            out << std::setw(4) << m_dataConfig->json;
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
}

void Configuration::debug(const std::string& debug) __tegra_noexcept
{
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["debug"].is_null()) {
            if(!debug.empty()) {
                auto& object = m_dataConfig->json.at("debug");
                object["debug"] = debug;
                std::ofstream out(jsonFile());
                out << std::setw(4) << m_dataConfig->json;
            }
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
}

RdbmsTypeList Configuration::rdbms() __tegra_noexcept
{
    RdbmsTypeList item{};
    if(!m_dataConfig->json["database"].is_null()){
        for(const auto& db : m_dataConfig->json.at("database"))
        {
            m_dataConfig->rdbmsInfo.codename = db["rdbms"];
            item.push_back(m_dataConfig->rdbmsInfo);
        }
    }
    return item;
}

std::string Configuration::getPrefix() __tegra_noexcept
{
    std::string pr{__tegra_null_str};
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["table_prefix"].is_null()) {
            if(!m_dataConfig->json.at("table_prefix").is_null()) {
                pr = m_dataConfig->json.at("table_prefix");
            }
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
    return pr;
}

std::string Configuration::currentRdbms()
{
    std::string rdbms{};
    if(!m_dataConfig->json["database"].is_null()) {
        for(const auto& db : m_dataConfig->json.at("database")) {
            if(db["status"]==true) {
                rdbms = db["rdbms"];
            }
        }
    } else {
        eLogger::Log("Error config parsing: ", eLogger::LoggerType::Critical);
    }
    return rdbms;
}

std::string Configuration::getDefaultUri() __tegra_noexcept
{
    std::string var{__tegra_null_str};
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["default_lang"].is_null()) {
            var = m_dataConfig->json.at("default_lang");
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
    return var;
}

std::vector<std::string> Configuration::getLanguageUris() __tegra_noexcept
{
    std::vector<std::string> luris{};
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["langs"].is_null()) {
            for(const auto& uri : m_dataConfig->json.at("langs")) {
                luris.push_back(uri["uri"]);
            }
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
    return luris;
}

void Configuration::programs(const std::string &pgDumpPath) __tegra_noexcept
{
    switch (m_dataConfig->configType) {
    case ConfigType::File:
        if(!m_dataConfig->json["programs"].is_null()) {
            auto& array = m_dataConfig->json.at("programs");
            for (auto& val:array){
                val["pg_dump"]["path"] = pgDumpPath;
            }
            std::ofstream out(jsonFile());
            out << std::setw(4) << m_dataConfig->json;
        } else {
            eLogger::Log("Error on reading variable: ", eLogger::LoggerType::Critical);
        }
        break;
    case ConfigType::Database:
        //ToDo...
        break;
    default:
        break;
    }
}

TEGRA_NAMESPACE_END
