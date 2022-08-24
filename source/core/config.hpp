/*!
 * @file        config.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System configuration.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "common.hpp"
#include "core/core.hpp"
#include "core/setting.hpp"
#include "abstracts/configuration.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The RdbmsInterface class
 */
struct RdbmsInterface final
{
    std::string codename    {};     ///< Code name for rdbms.
    std::string host        {};     ///< Host name.
    std::string name        {};     ///< Name of host.
    std::string username    {};     ///< Username.
    std::string password    {};     ///< Password.
    u32         port        {};     ///< Port of host.
    bool        status      {};     ///< Status of rdbms.
};
/*!
 * \brief The DataSetting struct
 */
struct DataConfig final
{
    RdbmsInterface            rdbmsInfo   {};   ///< Rdbms info.
    ConfigType                configType  {};   ///< Config type.
    SectionType               sectionType {};   ///< Section type.
    Scope<Engine>             engine      {};   ///< Tegra Engine
    Scope<Interface::Setting> setting     {};   ///< Tegra Setting
    std::string               configFile  {};   ///< Config file.
    JSon                      json        {};   ///< Json type.
};

TEGRA_USING RdbmsTypeList = std::vector<std::optional<RdbmsInterface>>;

/*!
 * \brief The Configuration class
 */
class Configuration : public AbstractConfiguration
{
public:
    Configuration() = delete;
    Configuration(const ConfigType& configType);
    Configuration(const ConfigType& configType, const std::string& customFile);
    Configuration(const ConfigType& configType, const SectionType& sectionType);
    ~Configuration();

    /*!
     * \brief GET is static method.
     */
    inline static Json::Value GET;

    /*!
     * \brief Checks and initializations are required from the abstract class before configuration.
     */
    void init(const SectionType sectionType) __tegra_override;

    /*!
     * \brief Creating and implementing the content of a tree in configuration files requires this function.
     * \param fileType as types of configuration file.
     * \returns true if the creating and implementing was successful.
     */
    bool create(const FileType& fileType) __tegra_override;

    /*!
     * \brief We need to register files inside the project to read and write.
     * \param files as a list string.
     */
    void registerFile(const VectorString& files) __tegra_override;

    /*!
     * \brief We need to get each file to check more details.
     * \returns list of files as string.
     */
    VectorString files() __tegra_override;

    /*!
     * \brief status of configuration system.
     * \returns true if there is no problem inside the config.
     */
    bool status() __tegra_override;

    /*!
     * \brief get function will gets value based on variable types.
     * \returns value based on it's type.
     */
    std::optional<VariableType> get() __tegra_override;

    /*!
     * \brief Writing in the configuration file requires sending information of variable type.
     * \param variable of multi types.
     */
    void write(const KeyValueType& variable) __tegra_override;

    /*!
     * \brief Updating in the configuration file requires sending information of variable type.
     * \param variable of multi types.
     */
    void update(const KeyValueType& variable) __tegra_override;

    /*!
     * \brief Removing in the configuration file requires sending information of variable type.
     * \param variable of multi types.
     */
    void remove(const KeyValueType& variable) __tegra_override;

    /*!
     * \brief It is sometimes necessary to reset all configuration variables.
     * \returns true if file resets.
     */
    bool reset() __tegra_override;

    /*!
     * \brief We may sometimes change the permission level of the file to prevent possible changes.
     * \returns true if permission changed.
     */
    bool lock() __tegra_override;

    /*!
     * \brief isInstalled function gets system install status.
     * \returns true if the system is installed.
     */
    bool isInstalled() __tegra_noexcept;

    /*!
     * \brief The installation process must be locked after successful installation. In this case, this function will be helpful.
     */
    void lockInstall() __tegra_noexcept;

    /*!
     * \brief system function will sets system configuration variables.
     */
    void system(const std::string& debug,
                const std::string& cookiePrefix,
                const std::string& tablePrefix,
                const std::string& tableValueStruct,
                const std::string& tableUnicode,
                const std::string& defaultLanguage) __tegra_noexcept;

    /*!
     * \brief database function will sets database configuration variables.
     */
    void database(const std::string& rdbms,
                  const std::string& host,
                  const std::string& name,
                  const std::string& username,
                  const std::string& password,
                  const std::string& port) __tegra_noexcept;

    /*!
     * \brief feature function will sets feature configuration variables.
     */
    void feature(const std::string& dynamic, const std::string& crossMode) __tegra_noexcept;

    /*!
     * \brief maintenance function will sets maintenance configuration variables.
     */
    void maintenance(const std::string& backupPath,
                     const std::string& experimentalUpdate,
                     const std::string& update,
                     const std::string& dbBackUpPath) __tegra_noexcept;

    /*!
     * \brief debug function will sets debug configuration variables.
     */
    void debug(const std::string& debug) __tegra_noexcept;

    /*!
     * \brief rdbms function will gets current used rdbms data from config.
     * \returns list of data member.
     */
    RdbmsTypeList rdbms() __tegra_noexcept;

    /*!
     * \brief getPrefix function will returns prefix.
     * \returns string.
     */
    std::string getPrefix() __tegra_noexcept;

    /*!
     * \brief getLanguageUris function will gets language uris.
     * \returns list of strings.
     */
    std::vector<std::string> getLanguageUris() __tegra_noexcept;

    /*!
     * \brief currentRdbms function will gets current used rdbms name.
     * \return string name of rdbms.
     */
    std::string currentRdbms();
    /*!
     * \brief getDefaultUri
     * \returns string.
     */
    std::string getDefaultUri() __tegra_noexcept;

    /*!
     * \brief getBaseUrl function will returns base domain address.
     * \returns string.
     */
    std::string getBaseUrl() __tegra_noexcept;

    /*!
     * \brief programs function will sets programs configuration variables.
     */
    void programs(const std::string& pgDumpPath) __tegra_noexcept;

protected:
    __tegra_no_discard std::string jsonFile() __tegra_noexcept;

private:
    DataConfig*     m_dataConfig;
    VectorString    m_files{};
};

TEGRA_NAMESPACE_END

#endif  // CONFIG_HPP
