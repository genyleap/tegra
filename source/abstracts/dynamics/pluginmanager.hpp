/*!
 * @file        pluginmanager.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Plugin manager interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef PLUGIN_MANAGER_ABSTRACT_HPP
#define PLUGIN_MANAGER_ABSTRACT_HPP

#include "common.hpp"
#include "plugin.hpp"
#include "plugininterface.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

// Define the prototype for a function that should exist in the lib
// that is used to create and return the plugin type in the lib.

TEGRA_POINTER_TO_AN_OBJECT(AbstractPlugin, fnCreatePlugin)

// Destroys the plugin type from the lib before the library is unloaded.
using fnDestroyPlugin = TEGRA_POINTER_TO_A_FUNCTION;

using PluginMap  =  std::map<std::string, AbstractPlugin*>;

using LibraryMap =  std::map<std::string, void*>;

/*!
 * \brief The PluginManagerData class
 */
class PluginManagerData final
{
public:
    PluginMap   plugins {};
    LibraryMap  libs    {};
};

/*!
 * \brief The AbstractPluginManager class
 */
class __tegra_export AbstractPluginManager
{
public:
    static AbstractPluginManager& instance();

    /*!
     * \brief load function loads the plugin and returns true if the plugin was loaded successfully; otherwise returns false.
     * \param plugin is plugin name.
     * \returns plugin.
     */
    __tegra_no_discard_virtual AbstractPlugin* load(const std::string& plugin) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief unload function unloads the plugin and returns true if the plugin could be unloaded; otherwise returns false.
     * \param plugin
     */
    __tegra_virtual void unload(AbstractPlugin*& plugin) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief isLoaded function returns true if the plugin is loaded; otherwise returns false.
     * \return bolean of status.
     */
    __tegra_no_discard_virtual bool isLoaded() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPluginManager)
    PluginManagerData* m_pluginManagerData;
    bool m_status = {false};
};

TEGRA_NAMESPACE_END

#endif  // PLUGIN_MANAGER_ABSTRACT_HPP
