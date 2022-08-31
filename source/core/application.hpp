/*!
 * @file        application.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System application.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_APPLICATION_HPP
#define TEGRA_APPLICATION_HPP

#include "common.hpp"
#include "core.hpp"
#include "logger.hpp"
#include "console.hpp"
#include "terminal.hpp"
#include "version.hpp"
#include "applicationdata.hpp"
#include "translator/language.hpp"
#include "translator/translator.hpp"
#include "abstracts/dynamics/moduleschema.hpp"
#include "abstracts/dynamics/pluginschema.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Types;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Abstracts;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Module;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Plugin;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The Application class
 */
class __tegra_export Application
{
public:
    Application() = default;
    Application(const ApplicationData& appData);
    ~Application();

    static Application* get(const ApplicationData& appData);

    /*!
     * \brief start
     */
    void start();

    /*!
     * \brief name of application.
     * \returns as string.
     */
    OptionalString name() __tegra_const_noexcept;

    /*!
     * \brief code name of application.
     * \returns as string.
     */
    OptionalString codeName() __tegra_const_noexcept;

    /*!
     * \brief type of application.
     * \returns as string.
     */
    OptionalString type() __tegra_const_noexcept;

    /*!
     * \brief license of application.
     * \returns as string.
     */
    OptionalString license() __tegra_const_noexcept;

    /*!
     * \brief model of application.
     * \returns as string.
     */
    OptionalString model() __tegra_const_noexcept;

    /*!
     * \brief modules function will gets all modules on Tegra.
     * \returns a list of modules with their information.
     */
    __tegra_no_discard std::vector<ModuleInfo> modules() __tegra_noexcept;

    /*!
     * \brief registerModules
     * \param moduleList
     */
    void registerModules(const std::vector<ModuleInfo>& moduleList) __tegra_noexcept;

    /*!
     * \brief registerPlugins
     * \param moduleList
     */
    void registerPlugins(const std::vector<PluginInfo>& pluginsList) __tegra_noexcept;

    /*!
     * \brief plugins function will gets all plugins on Tegra.
     * \returns a list of plugins with their information.
     */
    __tegra_no_discard std::vector<PluginInfo> plugins() __tegra_noexcept;

    /*!
     * \brief path as string.
     * \returns string.
     */
    OptionalString path() __tegra_const_noexcept;

    /*!
     * \brief module as module name.
     * \returns string.
     */
    OptionalString module() __tegra_const_noexcept;

    /*!
     * \brief templateId will gets error template id.
     * \returns string.
     */
    OptionalString templateErrorId() __tegra_const_noexcept;

    /*!
     * \brief templateId will gets template id.
     * \returns string.
     */
    OptionalString templateId() __tegra_const_noexcept;

    Scope<Engine>   engine  {};
    Scope<Version>  version {};
    Scope<SystemInfo>  systemInfo {};

    Translation::Translator* translator{__tegra_nullptr}; //alternative translator for engine.
    Multilangual::Language* language{__tegra_nullptr};

private:

    std::vector<ModuleInfo> m_moduleInfoList;
    std::vector<PluginInfo> m_pluginInfoList;

    static Application* appPtr;
    static ApplicationData* appDataPtr;
};

TEGRA_NAMESPACE_END

#endif // TEGRA_APPLICATION_HPP
