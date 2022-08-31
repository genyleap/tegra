/*!
 * @file        database.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Database manager.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "common.hpp"
#include "core/core.hpp"
#include "core/application.hpp"
#include "core/config.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Database)


//! SQL Defines
//! Data Definition Language (DDL) statements defines data structures.
//! Use these statements to create, alter, or drop data structures in a database.

#define DROP_DATABASE           "DROP DATABASE"
#define DROP_DATABASE_IF_EXIST  "DROP DATABASE IF EXISTS"
#define DROP_TABLE_IF_EXIST     "DROP TABLE IF EXISTS"
#define CREATE_DATABASE         "CREATE DATABASE"
#define CREATE_TABLE            "CREATE TABLE"
#define ALTER_TABLE             "ALTER TABLE"

//! Data Manipulation Language (DML) affect the information stored in the database.
//! Use these statements to insert, update, and change the rows in the database.

#define CALL                    "CALL"
#define UPDATE                  "UPDATE"
#define INSERT                  "INSERT"
#define DELETE                  "DELETE"
#define LOCK_TABLE              "LOCK TABLE"
#define EXPLAIN_PLAN            "EXPLAIN PLAN"
#define MERGE                   "MERGE"
#define SELECT                  "SELECT"
#define SEQUENCE                "SEQUENCE"
#define TRUNCATE_TABLE          "TRUNCATE"
#define IS_NULL                 "IS NULL"

//! Types of SQL Statements

#define BACKUP_DATABASE         "BACKUP DATABASE"
#define BACKUP_TO_DISK          "TO DISK"
#define INNER_JOIN              "INNER JOIN"
#define FROM                    "FROM"
#define INTO                    "INTO"
#define WHERE                   "WHERE"
#define AND                     "AND"
#define OR                      "OR"

/*!
 * @brief The string of names related to the tables that are required by default for the system.
 * @returns list of table names as string.
 */
struct Constants final
{
    __tegra_inline_static_const VectorString defaultTables {
        "config", "config_l","apikey","resource","resource_l",
        "drafts", "templates","templates_l", "services","services_l", "social","social_l"
        ,"groups", "groups_l","menu","menu_l","modules","modules_l","plugins", "plugins_l",
        "config_groups","config_groups_l", "tasks","cache", "provinces", "cities",
        "tags", "globalization","translation", "members", "members_account",
        "members_contact", "members_extra", "members_job", "members_known_devices",
        "members_social","members_session", "members_verification", "questions",
        "answers", "rating", "review", "transaction", "likes"
    };

    __tegra_inline_static_const Types::VectorString drivers {
        "mysql", "postgresql"
    };

};

/*!
 * @brief The structure of tables in Tegra is divided into two parts, key and value, due to the nature of supporting multiple languages.
 * Data stored in tables are two types:
 * ======================================================
 * Therefore, we must consider this in their management.
 * ---------------- Key base table ----------------
 * ----> id is primary and auto increment index.
 * ======================================================
 * --------------- Value base table ---------------
 * ----> language is key and index.
 * ======================================================
 * First: the basic data that is considered as the key and will usually contain numeric and bit values.
 * Second: data that stores content based on language type and can be distinguished based on the language field.
 * Therefore, the tables that depend on the language are distinguished from the base table with the l character.
 * @example config [as key] and the other one should be like this config_l[as value].
 */
enum class TableType : u8
{
    MixedStruct, ///<Key and Value table
    KeyStruct,   ///<Only key table
    ValueSturct  ///<Only value table [with suffix "l"]
};

struct TEGRA_RDBMS final {
    static constexpr std::string_view   MySQL       = "mysql";
    static constexpr std::string_view   PostgreSQL  = "postgresql";

};

//!System default tables
struct TEGRA_TABLES final
{
    static constexpr std::string_view   CONFIG                  = "config";
    static constexpr std::string_view   CONFIG_L                = "config_l";
    static constexpr std::string_view   APIKEY                  = "apikey";
    static constexpr std::string_view   RESOURCE                = "resource";
    static constexpr std::string_view   RESOURCE_L              = "resource_l";
    static constexpr std::string_view   DRAFTS                  = "drafts";
    static constexpr std::string_view   TEMPLATES               = "templates";
    static constexpr std::string_view   TEMPLATES_L             = "templates_l";
    static constexpr std::string_view   SERVICES                = "services";
    static constexpr std::string_view   SERVICES_L              = "services_l";
    static constexpr std::string_view   GROUPS                  = "groups";
    static constexpr std::string_view   GROUPS_L                = "groups_l";
    static constexpr std::string_view   MENU                    = "menu";
    static constexpr std::string_view   MENU_L                  = "menu_l";
    static constexpr std::string_view   MODULES                 = "modules";
    static constexpr std::string_view   MODULES_L               = "modules_l";
    static constexpr std::string_view   PLUGINS                 = "plugins";
    static constexpr std::string_view   PLUGINS_L               = "plugins_l";
    static constexpr std::string_view   TAGS                    = "tags";
    static constexpr std::string_view   TAGS_L                  = "tags_l";
    static constexpr std::string_view   CONFIG_GROUPS           = "config_groups";
    static constexpr std::string_view   CONFIG_GROUPS_L         = "config_groups_l";
    static constexpr std::string_view   TASKS                   = "tasks";
    static constexpr std::string_view   CACHE                   = "cache";
    static constexpr std::string_view   PROVINCES               = "provinces";
    static constexpr std::string_view   CITIES                  = "cities";
    static constexpr std::string_view   GLOBALIZATION           = "globalization";
    static constexpr std::string_view   TRANSLATION             = "translation";
    static constexpr std::string_view   MEMBERS                 = "members";
    static constexpr std::string_view   MEMBERS_ACCOUNT         = "members_account";
    static constexpr std::string_view   MEMBERS_CONTACT         = "members_contact";
    static constexpr std::string_view   MEMBERS_EXTRA           = "members_extra";
    static constexpr std::string_view   MEMBERS_JOB             = "members_job";
    static constexpr std::string_view   MEMBERS_KNOWN_DEVICES   = "members_known_devices";
    static constexpr std::string_view   MEMBERS_SOCIAL          = "members_social";
    static constexpr std::string_view   MEMBERS_SESSION         = "members_session";
    static constexpr std::string_view   MEMBERS_VERIFICATION    = "members_verification";
    static constexpr std::string_view   QUESTIONS               = "questions";
    static constexpr std::string_view   ANSWERS                 = "answers";
    static constexpr std::string_view   RATING                  = "rating";
    static constexpr std::string_view   REVIEW                  = "review";
    static constexpr std::string_view   TRANSACTION             = "transaction";
    static constexpr std::string_view   LIKES                   = "likes";
};

/*!
 * @brief Driver types as RDBMS.
 */
enum class DriverTypes : u8
{
    Default     = 0x0, ///<The driver that is selected by default.
    MySQL       = 0x1, ///<Mysql driver.
    PostgreSQL  = 0x2, ///<Postgresql driver.
    Unknown     = 0x3  ///<If no driver is detected!
};

using DatabaseList = std::vector<std::string>;
using TableList    = std::vector<std::string>;

struct StructManager final
{
    std::string     username    {};
    std::string     password    {};
    std::string     path        {};

    TableList       tables      {};
    DatabaseList    database    {};
    Database::DriverTypes types {};
};

class Manager
{
public:
    Manager() = delete;
    Manager(const ApplicationData& appData, const StructManager& structManager);
    Manager(const Manager& rhsManager) = delete;
    Manager(Manager&& rhsManager) noexcept = delete;
    Manager& operator=(const Manager& rhsManager) = delete;
    Manager& operator=(Manager&& rhsManager) noexcept = delete;
    ~Manager();


    /*!
     * @brief createDatabase function will create a new SQL databases.
     * @param type is database type such as MySQL or PostgreSQL.
     * @param db is list of database name that you want to create.
     */
    void createDatabase();

    /*!
     * @brief removeDatabase function will drop an existing SQL databases.
     * @param type is database type such as MySQL or PostgreSQL.
     * @param db is list of database name that you want to create.
     */
    void removeDatabase();

    /*!
     * @brief backupDatabase function will create a full back up of an existing SQL database.
     * @param type is database type such as MySQL or PostgreSQL.
     * @param db is list of database name that you want to create.
     * @param path is a location for save the backup file.
     */
    void backupDatabase(Database::DriverTypes type, const DatabaseList& db, const std::string& path, const std::string& u);

    /*!
     * @brief createTables function will create new table on your database.
     * @param type is database type such as MySQL or PostgreSQL.
     */
    void createTables(Database::DriverTypes type);

    /*!
     * @brief removeTables function will remove new table on your database.
     * @param type is database type such as MySQL or PostgreSQL.
     */
    void removeTables(Database::DriverTypes type);

    /*!
     * @brief insertTables function will inserts new data inside the table.
     * @param type is database type such as MySQL or PostgreSQL.
     */
    void insertTables(Database::DriverTypes type);

    /*!
     * @brief resetTables function will reset all table's data inside the database.
     * @param type is database type such as MySQL or PostgreSQL.
     */
    void resetAllTables(Database::DriverTypes type);

    /*!
     * @brief resetTables function will reset all data inside the table.
     * @param type is database type such as MySQL or PostgreSQL.
     */
    void resetTable(Database::DriverTypes type, const std::string& tableName);

    /*!
     * @brief tables function gets list of tables.
     * @return as container.
     */
    const TableList& tables() const;

    /*!
     * @brief setTables function will sets list of table inside the tables function.
     * @param newTables as a list.
     */
    void setTables(const std::vector<std::string>& newTables);

    /*!
     * @brief setDb function will sets database as list.
     * @param db as vector container.
     */
    void setDb(const DatabaseList& db);

    /*!
     * @brief db function will returns list of database names.
     * @return as list.
     */
    __tegra_no_discard DatabaseList db() const;

    /*!
     * @brief setTypes function will sets type of database.
     * @param t as a Database Type such as MySQL, PostgreSQL and etc.
     */
    void setTypes(Database::DriverTypes t);

    /*!
     * @brief types function gets type of db.
     * @return as Types.
     */
    Database::DriverTypes types();

    /*!
     * @brief Sometimes it is necessary to compare the string name of the driver type (rdbms) with the value in the configuration file.
     * @returns string name of the database driver type.
     */
    std::string getRdbmsType();

    /*!
     * @brief username function will gets db username as string if it's empty then returns as default.
     * @return default or custom value.
     */
    __tegra_no_discard std::optional<std::string> username() const;

    /*!
     * @brief setUsername function will sets username for database.
     * @param username as string.
     */
    void setUsername(const std::string& username);

    /*!
     * @brief password function will gets db password as string if it's empty then returns as default.
     * @return default or custom value.
     */
    __tegra_no_discard std::optional<std::string> password() const;

    /*!
     * @brief setPassword function will sets password for database.
     * @param pass as string.
     */
    void setPassword(const std::string& pass);

    /*!
     * @brief path function will gets db backup path as string if it's empty then returns as default.
     * @return default or custom value.
     */
    __tegra_no_discard std::optional<std::string> path() const;

    /*!
     * @brief setPath function will sets backup path for database.
     * @param pass as string.
     */
    void setPath(const std::string& path);

private:
    StructManager* structManagerPtr;
    ApplicationData* appDataPtr{};
    Scope<Multilangual::Language> languagePtr{};
};

/*!
 * \brief The SqlHelper struct is useful for extra sql actions.
 */
struct SqlHelper final
{
    unsigned int lastInsertedId(const std::string& table) __tegra_noexcept;
};

#define IsConnected Connection::isConnected()
struct Connection
{
    /*!
     * \brief connect function will connect via rdbms.
     */
    void connect();

    /*!
     * \brief checks if there is a connection successfully established.
     */
    static bool isConnected() __tegra_noexcept;
private:
    bool m_connected;
};

TEGRA_NAMESPACE_END

#endif  // DATABASE_HPP
