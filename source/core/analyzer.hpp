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

#ifndef TEGRA_ANALYZER_HPP
#define TEGRA_ANALYZER_HPP

#include "common.hpp"
#include "core.hpp"
#include "core/config.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::System)

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
    __tegra_no_discard OptionalString result() __tegra_noexcept;

private:
    ApplicationData* appDataPtr{};
    Scope<Multilangual::Language> languagePtr{};
    bool m_isExist{false};
    std::string m_message{};

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
    bool isExist(const std::string& pluginName);
    __tegra_no_discard OptionalString result() __tegra_noexcept;

private:
    ApplicationData* appDataPtr{};
    Scope<Multilangual::Language> languagePtr{};
    bool m_isExist{false};
    std::string m_message{};

};

TEGRA_NAMESPACE_END

#endif // TEGRA_ANALYZER_HPP
