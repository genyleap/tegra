/*!
 * @file        analyzer.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Analyzer system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_TEGRA_ANALYZER_HPP
#define TEGRA_TEGRA_ANALYZER_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements are not found!"
# endif
#endif

//! Tegra's Application.
#ifdef __has_include
# if __has_include(<application>)
#   include <application>
#else
#   error "The application of Tegra are not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::System)

#define MODULES "modules"
#define PLUGINS "plugins"
#define CHECKSUMS_FILE ".txt"

enum class CheckType
{
    MD5, SHA1, SHA256, SHA512
};

struct ChecksumData final
{
    std::string message     {};
    std::string algorithm   {};
    CheckType checkType     {};
};

struct ModuleAnalyzerData final
{
    bool isExist        {false};
    bool isSupported    {false};
    bool isOfficial     {false};
    std::string message {__tegra_null_str};
};

class ModuleAnalyzer
{
public:
    ModuleAnalyzer(const ApplicationData& appData);
    ~ModuleAnalyzer();

    /*!
     * \brief isExist function checks module exist or not.
     * \param moduleName as module string name.
     * \returns true if the module exists.
     */
    __tegra_no_discard bool isExist(const std::string& moduleName) __tegra_noexcept;

    /*!
     * \brief isOfficial function will checks module creator.
     * \param moduleName as module string name.
     * \returns true if the module created by official owner or developers.
     */
    __tegra_no_discard bool isOfficial(const std::string& moduleName) __tegra_noexcept;

    /*!
     * \brief isSupported function will ensures that the desired file is supported by the system.
     * \param moduleName as module string name.
     * \returns true if the module supported by system.
     */
    __tegra_no_discard bool isSupported(const std::string& moduleName) __tegra_noexcept;

    /*!
     * \brief result function will gets message of status.
     * \returns as string message.
     */
    __tegra_no_discard OptionalString result() __tegra_noexcept;

private:
    ApplicationData* appDataPtr{};
    Scope<Multilangual::Language> languagePtr{};
    ModuleAnalyzerData m_moduleAnalyzerData;

};

class PluginAnalyzer
{
public:
    PluginAnalyzer(const ApplicationData& appData);
    ~PluginAnalyzer();

    /*!
     * \brief isExist function checks plugin exist or not.
     * \param pluginName as plugin string name.
     * \returns true if the plugin exists.
     */
    /*!
     * \brief isExist function checks plugin exist or not.
     * \param pluginName as plugin string name.
     * \returns true if the plugin exists.
     */
    __tegra_no_discard bool isExist(const std::string& pluginName) __tegra_noexcept;

    /*!
     * \brief isOfficial function will checks plugin creator.
     * \param pluginName as plugin string name.
     * \returns true if the plugin created by official owner or developers.
     */
    __tegra_no_discard bool isOfficial(const std::string& pluginName) __tegra_noexcept;

    /*!
     * \brief isSupported function will ensures that the desired file is supported by the system.
     * \param pluginName as plugin string name.
     * \returns true if the plugin supported by system.
     */
    __tegra_no_discard bool isSupported(const std::string& pluginName) __tegra_noexcept;

    /*!
     * \brief result function will gets message of status.
     * \returns as string message.
     */
    __tegra_no_discard OptionalString result() __tegra_noexcept;

private:
    ApplicationData* appDataPtr{};
    Scope<Multilangual::Language> languagePtr{};
    ModuleAnalyzerData m_moduleAnalyzerData;
};

class Checksum
{
public:
    Checksum(const CheckType& checkType);
    ~Checksum();

    __tegra_no_discard bool checkFile(const std::string& path) __tegra_noexcept;
    __tegra_no_discard bool generate(const std::string& file) __tegra_noexcept;
    __tegra_no_discard std::string getResult() __tegra_noexcept;

    void setResult(const std::string& r) __tegra_noexcept;

private:
    ChecksumData m_checkSumData;

};

TEGRA_NAMESPACE_END

#endif // TEGRA_TEGRA_ANALYZER_HPP
