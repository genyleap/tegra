#include "database.hpp"
#include "core.hpp"
#include "application.hpp"
#include "translator/translator.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra::Database)

Manager::Manager(const ApplicationData& appData, const StructManager& structManager)
{
    auto app = Application(appData);
    __tegra_safe_instance(appDataPtr, ApplicationData);
    __tegra_safe_instance_rhs(structManagerPtr, StructManager, structManager);
    {
        structManagerPtr->database   = structManager.database;
        structManagerPtr->path       = structManager.path;
        structManagerPtr->types      = structManager.types;
        structManagerPtr->tables     = structManager.tables;
        structManagerPtr->username   = structManager.username;
        structManagerPtr->password   = structManager.password;

        setPath(structManagerPtr->path);
        setDb(structManagerPtr->database);
        setTypes(structManagerPtr->types);
        setTables(structManagerPtr->tables);
        setUsername(structManagerPtr->username);
        setPassword(structManagerPtr->password);
    }

    appDataPtr->path = appData.path;

}

Manager::~Manager()
{
    __tegra_safe_delete(appDataPtr);
    __tegra_safe_delete(structManagerPtr);
}

void Manager::setTypes(Database::DriverTypes type)
{
    structManagerPtr->types = type;
}

Database::DriverTypes Manager::types()
{
    return structManagerPtr->types;
}

std::string Manager::getRdbmsType()
{
    Scope<Configuration> config(new Configuration(ConfigType::File));
    config->init(SectionType::SystemCore);
    std::string res{};
    for(auto c : Configuration::GET["database"]) {
        for(const auto& d: Constants::drivers) {
            if(c["rdbms"] == d && c["status"] == true) {
                res = c["rdbms"].asString();
            }
        }
    }
    return res;
}

DatabaseList Manager::db() const
{
    return structManagerPtr->database;
}

void Manager::setUsername(const std::string& username)
{
    if(!username.empty()) structManagerPtr->username = username;
}

std::optional<std::string> Manager::username() const
{
    if (!structManagerPtr->username.empty()) {
        return structManagerPtr->username;
    } else {
        return std::nullopt;
    }
}

void Manager::setPassword(const std::string& pass)
{
    if(!structManagerPtr->password.empty()) structManagerPtr->password = pass;
}

std::optional<std::string> Manager::password() const
{
    if (!structManagerPtr->password.empty()) {
        return structManagerPtr->password;
    } else {
        return std::nullopt;
    }
}

void Manager::setDb(const DatabaseList& db)
{
    if(!structManagerPtr->database.empty()) structManagerPtr->database = db;
}

void Manager::setPath(const std::string& path)
{
    if(!structManagerPtr->path.empty()) structManagerPtr->path = path;
}

std::optional<std::string> Manager::path() const
{
    if (!structManagerPtr->path.empty()) {
        return structManagerPtr->path;
    } else {
        return std::nullopt;
    }
}

void Manager::createDatabase()
{
    auto clientPtr = AppFramework::application().getDbClient();
    VectorString database{};
    switch (types()) {
    case Database::DriverTypes::MySQL:
        for(const auto& t : db()) {
            database.push_back(FROM_TEGRA_STRING(DROP_DATABASE_IF_EXIST) + __tegra_space + "`" + t + "`");
            database.push_back(FROM_TEGRA_STRING(CREATE_DATABASE) + __tegra_space + t);
        }
        try
        {
            for(const auto& i : database) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case Database::DriverTypes::PostgreSQL:
        for(const auto& t : db()) {
            database.push_back(FROM_TEGRA_STRING(DROP_DATABASE_IF_EXIST) + __tegra_space + t);
            database.push_back(FROM_TEGRA_STRING(CREATE_DATABASE) + __tegra_space + t);
        }
        try
        {
            for(const auto& i : database) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }
}

void Manager::removeDatabase()
{    
    auto clientPtr = AppFramework::application().getDbClient();
    VectorString database{};
    switch (types()) {
    case Database::DriverTypes::MySQL:
        for(const auto& t : db()) {
            database.push_back(FROM_TEGRA_STRING(DROP_DATABASE) + __tegra_space + t);
        }
        try
        {
            for(const auto& i : database) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case Database::DriverTypes::PostgreSQL:
        for(const auto& t : db()) {
            database.push_back(FROM_TEGRA_STRING(DROP_DATABASE) + __tegra_space + t);
        }
        clientPtr->execSqlAsync(database.data()->c_str(),
            [&](const Framework::orm::Result &result) {

                if(DeveloperMode::IsEnable) {
                    eLogger::Log("Database Removed!", eLogger::LoggerType::Success);
                }
            },
            [&](const SqlException &e) {
                if(DeveloperMode::IsEnable) {
                    eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
                }
            });
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }
}

void Manager::backupDatabase(Database::DriverTypes type, const DatabaseList& db, const std::string& path, const std::string& u)
{    
    auto clientPtr = AppFramework::application().getDbClient();

    auto config = Configuration(ConfigType::File);

    config.init(SectionType::SystemCore);

    std::string p{Configuration::GET["maintenance"]["backup_path"].asString()};

    std::vector<std::string> database{};

    switch (type) {
    case Database::DriverTypes::MySQL:
#ifdef ENABLE_TODO_MODE
        eLogger::Log("This part of the code is not yet complete and using it may cause the program to crash." , eLogger::LoggerType::Critical);
#else
        for(const auto& t : db) {
            database.push_back(FROM_TEGRA_STRING(BACKUP_DATABASE) + __tegra_space + t);
            database.push_back(FROM_TEGRA_STRING(BACKUP_TO_DISK) + "='" + p + "'" + t);
        }
        try
        {
            for(const auto& i : database) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
#endif
        break;
    case Database::DriverTypes::PostgreSQL:
        for(const auto& t : db) {
            for(const auto& c : Configuration::GET["programs"]) {
                std::stringstream commandStream { c["pg_dump"]["path"].asString() + " -U " + u + " "+ t +" > " + p.append("backup.sql") };
                if(!system(commandStream.str().c_str())) {
                    if(DeveloperMode::IsEnable) {
                        eLogger::Log("Database backup has been created!", eLogger::LoggerType::Success);
                    }
                } else {
                    if(DeveloperMode::IsEnable) {
                        eLogger::Log("Database Backup Error on program pg_dump!", eLogger::LoggerType::Critical);
                    }
                }
            }
        }
        try
        {
            for(const auto& i : database) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }
}

void Manager::createTables(Database::DriverTypes type)
{
    auto engine = Engine();

    auto clientPtr = AppFramework::application().getDbClient();

    auto config = Configuration(ConfigType::File);

    config.init(SectionType::Database);

    std::vector<std::string> tables{};

    auto configTable = Configuration::GET["tables"];

    TableNames tableNames;

    for(const auto& ns : Database::Constants::defaultTables)
    {
        tableNames.push_back(ns);
    }
    switch (type) {
    case Database::DriverTypes::MySQL:
        for(const auto& t : tableNames) {
            tables.push_back(FROM_TEGRA_STRING(DROP_TABLE_IF_EXIST) + __tegra_space + "`" + t + "`");
        }
        for(const auto& var : configTable) {
            for(const auto& array : var["create"]) {
                if(array["name"] == FROM_TEGRA_STRING(TEGRA_RDBMS::PostgreSQL)) {
                    for(const auto& d : array["data"]) {
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::KeyStruct)) {
                            if(d["name"]==t)
                                tables.push_back(CREATE_TABLE __tegra_space + engine.table(t, System::TableType::KeyStruct) +
                                                 __tegra_space + FROM_TEGRA_STRING(d["content"].asString()));
                        }
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::ValueSturct)) {
                            if(d["name"]==t)
                                tables.push_back(CREATE_TABLE __tegra_space + engine.table(t, System::TableType::ValueSturct) +
                                                 __tegra_space + FROM_TEGRA_STRING(d["content"].asString()));
                        }
                    }
                }
            }
        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case Database::DriverTypes::PostgreSQL:
        for(const auto& t : tableNames) {
            tables.push_back(FROM_TEGRA_STRING(DROP_TABLE_IF_EXIST) + __tegra_space + engine.table(t, System::TableType::MixedStruct));
        }
        for(const auto& var : configTable) {
            for(const auto& array : var["create"]) {
                if(array["name"] == FROM_TEGRA_STRING(TEGRA_RDBMS::PostgreSQL)) {
                    for(const auto& d : array["data"]) {
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::KeyStruct)) {
                            if(d["name"]==t)
                                tables.push_back(CREATE_TABLE __tegra_space + engine.table(t, System::TableType::KeyStruct) +
                                                 __tegra_space + FROM_TEGRA_STRING(d["content"].asString()));
                        }
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::ValueSturct)) {
                            if(d["name"]==t)
                                tables.push_back(CREATE_TABLE __tegra_space + engine.table(t, System::TableType::ValueSturct) +
                                                 __tegra_space + FROM_TEGRA_STRING(d["content"].asString()));
                        }
                    }
                }
            }
        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }
}

void Manager::removeTables(Database::DriverTypes type)
{
    auto engine = Engine();

    auto clientPtr = AppFramework::application().getDbClient();

    std::vector<std::string> tables{};

    TableNames tableNames;

    for(const auto& ns : Database::Constants::defaultTables) {
        tableNames.push_back(engine.table(ns, System::TableType::MixedStruct));
    }
    switch (type) {
    case Database::DriverTypes::MySQL:
        for(const auto& t : tableNames) {
            tables.push_back(FROM_TEGRA_STRING(DROP_TABLE_IF_EXIST) + __tegra_space + "`" + t + "`");
        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Info);
        }
        break;
    case Database::DriverTypes::PostgreSQL:
        for(const auto& t : tableNames) {
            tables.push_back(FROM_TEGRA_STRING(DROP_TABLE_IF_EXIST) + __tegra_space + t);
        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Info);
        }
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }

}

void Manager::insertTables(Database::DriverTypes type)
{
    auto engine = Engine();

    languagePtr = CreateScope<Multilangual::Language>(appDataPtr->path.value());

    auto config = Configuration(ConfigType::File);

    config.init(SectionType::Database);

    auto clientPtr = AppFramework::application().getDbClient();

    std::string charset {engine.tableUnicode()};

    auto configTable = Configuration::GET["tables"];

    std::vector<std::string> tables{};

    TableNames tableNames;

    std::map<std::string, std::string> filterContent;

    for(const auto& ns : Database::Constants::defaultTables) {
        tableNames.push_back(ns);
    }

    switch (type) {
    case Database::DriverTypes::MySQL:
        //Reset All tables first.
        resetAllTables(DriverTypes::MySQL);
        filterContent.insert(std::pair<std::string, std::string>("{{system_name}}", TEGRA_TRANSLATOR("global", "name")));
        filterContent.insert(std::pair<std::string, std::string>("{{website_address}}", CONFIG::OFFICIAL_EMAIL));
        filterContent.insert(std::pair<std::string, std::string>("{{email}}", CONFIG::OFFICIAL_EMAIL));
        for(const auto& var : configTable) {
            for(const auto& array : var["insert"]) {
                if(array["name"] == FROM_TEGRA_STRING(TEGRA_RDBMS::MySQL)) {
                    for(const auto& d : array["data"]) {
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::KeyStruct)) {
                            if(d["name"]==t)
                                tables.push_back(INSERT __tegra_space INTO __tegra_space + engine.table(t, System::TableType::KeyStruct)
                                                 + __tegra_space + FROM_TEGRA_STRING(d["content"].asString()));
                        }
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::ValueSturct)) {
                            if(d["name"]==t)
                                tables.push_back(INSERT __tegra_space INTO __tegra_space + engine.table(t, System::TableType::ValueSturct)
                                                 + __tegra_space + FROM_TEGRA_STRING(engine.fullReplacer(FROM_TEGRA_STRING(d["content"].asString()), filterContent)));
                        }
                    }
                }
            }
        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case Database::DriverTypes::PostgreSQL:
        //Reset All tables first.
        resetAllTables(DriverTypes::PostgreSQL);
        filterContent.insert(std::pair<std::string, std::string>("{{system_name}}", TEGRA_TRANSLATOR("global", "name")));
        filterContent.insert(std::pair<std::string, std::string>("{{website_address}}", CONFIG::OFFICIAL_EMAIL));
        filterContent.insert(std::pair<std::string, std::string>("{{email}}", CONFIG::OFFICIAL_EMAIL));
        for(const auto& var : configTable) {
            for(const auto& array : var["insert"]) {
                if(array["name"] == FROM_TEGRA_STRING(TEGRA_RDBMS::PostgreSQL)) {
                    for(const auto& d : array["data"]) {
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::KeyStruct)) {
                            if(d["name"]==t)
                                tables.push_back(INSERT __tegra_space INTO __tegra_space + engine.table(t, System::TableType::KeyStruct)
                                                 + __tegra_space + FROM_TEGRA_STRING(d["content"].asString()));
                        }
                        for(const auto& t : engine.tableFilter(tableNames, System::TableType::ValueSturct)) {
                            if(d["name"]==t) {
                                tables.push_back(INSERT __tegra_space INTO __tegra_space + engine.table(t, System::TableType::ValueSturct)
                                                 + __tegra_space + FROM_TEGRA_STRING(engine.fullReplacer(FROM_TEGRA_STRING(d["content"].asString()), filterContent)));
                            }
                        }
                    }

                }

            }

        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }
}

void Manager::resetAllTables(Database::DriverTypes type)
{
    Scope<Engine> engine(new Engine());

    Scope<Configuration> config(new Configuration(ConfigType::File));

    config->init(SectionType::Database);

    auto clientPtr = AppFramework::application().getDbClient();

    std::vector<std::string> tables{};

    TableNames tableNames;

    for(const auto& ns : Database::Constants::defaultTables) {
        tableNames.push_back(ns);
    }
    switch (type) {
    case Database::DriverTypes::MySQL:
        for(const auto& t : tableNames) {
            tables.push_back(FROM_TEGRA_STRING(TRUNCATE_TABLE) + __tegra_space + engine->table(t, System::TableType::MixedStruct));
        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case Database::DriverTypes::PostgreSQL:
        for(const auto& t : tableNames) {
            tables.push_back(FROM_TEGRA_STRING(TRUNCATE_TABLE) + __tegra_space + engine->table(t, System::TableType::MixedStruct));
        }
        try
        {
            for(const auto& i : tables) {
                clientPtr->execSqlSync(i);
            }
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }
}

void Manager::resetTable(Database::DriverTypes type, const std::string& tableName)
{
    Scope<Engine> engine(new Engine());

    Scope<Configuration> config(new Configuration(ConfigType::File));

    config->init(SectionType::Database);

    auto clientPtr = AppFramework::application().getDbClient();

    TableNames tableNames;

    for(const auto& ns : Database::Constants::defaultTables) {
        tableNames.push_back(ns);
    }
    switch (type) {
    case Database::DriverTypes::MySQL:
        try
        {
            clientPtr->execSqlSync(FROM_TEGRA_STRING(TRUNCATE_TABLE) + __tegra_space + engine->table(tableName, System::TableType::MixedStruct));
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    case Database::DriverTypes::PostgreSQL:
        try
        {
            clientPtr->execSqlSync(FROM_TEGRA_STRING(TRUNCATE_TABLE) + __tegra_space + engine->table(tableName, System::TableType::MixedStruct));
        }
        catch (const SqlException& e)
        {
            if(DeveloperMode::IsEnable) {
                eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
            }
        }
        break;
    default:
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Please select a database driver!", eLogger::LoggerType::Critical);
        }
        break;
    }
}

const TableList& Manager::tables() const
{
    return structManagerPtr->tables;
}

void Manager::setTables(const TableList& newTables)
{
    structManagerPtr->tables = newTables;
}

unsigned int SqlHelper::lastInsertedId(const std::string& table) noexcept
{
    Scope<Configuration> config(new Configuration(ConfigType::File));

    config->init(SectionType::Database);

    Scope<Engine> engine(new Engine());

    auto clientPtr = AppFramework::application().getDbClient();

    unsigned int maxIndex{};

    try
    {
        if(config->currentRdbms() == Database::TEGRA_RDBMS::PostgreSQL) {
            for (auto &row : clientPtr->execSqlSync("select setval('"+engine->tablePrefix()+table+"_id_seq', max(id)+1) from "+engine->tablePrefix()+table+";"))
            {
                maxIndex = row["setval"].as<int>() == __tegra_zero ? 1 : row["setval"].as<int>();
            }
        }
        if(config->currentRdbms() == Database::TEGRA_RDBMS::MySQL) {
            for (auto &row : clientPtr->execSqlSync("select max(id)+1 from "+engine->tablePrefix()+table+";"))
            {
                maxIndex = row["setval"].as<int>() == __tegra_zero ? 1 : row["setval"].as<int>();
            }
        }
    }
    catch (const SqlException& e)
    {
        eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
    }
    return maxIndex;
}


void Connection::connect()
{
    std::string rdbms{}, dbName{}, dbUsername{}, dbPassword{}, dbCharset{}, dbHost{}, tablePrefix{};

    std::vector<std::string> driverType{};

    unsigned int dbPort{__tegra_zero};

    Scope<Configuration> config(new Configuration(ConfigType::File));

    config->init(SectionType::SystemCore);

    auto getConf = Configuration::GET["database"];

    for(const auto& c : getConf) {

        if(isset(BOOLCOMBINER(c,"status"))) {

            driverType.push_back(STRCOMBINER(c, "rdbms"));

            for(const auto& d : driverType) {
                rdbms = d;
            }

            dbHost          =   STRCOMBINER(c, "host");
            dbName          =   STRCOMBINER(c, "name");
            dbUsername      =   STRCOMBINER(c, "username");
            dbPassword      =   STRCOMBINER(c, "password");
            dbPort          =   INTCOMBINER(c, "port");
        }
    }

    try {
        APPLICATION_DB_RUN(rdbms, dbHost, dbPort, dbName, dbUsername, dbPassword);
    }
    catch (const SqlException& e)
    {
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
        }
    }
}

bool Connection::isConnected() __tegra_noexcept
{
    bool res {false};
    auto dbc = AppFramework::application().getDbClient();
    if (isset(dbc->hasAvailableConnections()) && true)
    {
        res = true;
    } else {
        if(DeveloperMode::IsEnable)
            eLogger::Log("Database Connection Error: " + FROM_TEGRA_STRING("There is a problem connecting to the database, please check your settings!"), eLogger::LoggerType::Critical);
        res = false;
    }
    return res;
}


TEGRA_NAMESPACE_END
