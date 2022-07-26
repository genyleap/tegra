/*!
 * @file        pluginmanager.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Plugin manager system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_PLUGIN_MANAGER_HPP
#define TEGRA_PLUGIN_MANAGER_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

//! Tegra's Abstract Dynamics.
#ifdef __has_include
# if __has_include(<abstracts/dynamics>)
#   include <abstracts/dynamics>
#else
#   error "Tegra's dynamics was not found!"
# endif
#endif

class PluginManagerPimpl;

/*!
 * \brief The PluginManager class
 */
class __tegra_export PluginManager : public Tegra::Abstracts::AbstractPluginManager
{
public:
  static PluginManager& instance();

  /*!
   * \brief load function loads the plugin and returns true if the plugin was loaded successfully; otherwise returns false.
   * \param plugin is plugin name.
   * \return plugin.
   */
  __tegra_no_discard Tegra::Abstracts::AbstractPlugin* load(const std::string& plugin) override;

  /*!
   * \brief unload function unloads the plugin and returns true if the plugin could be unloaded; otherwise returns false.
   * \param plugin
   */
  void unload(Tegra::Abstracts::AbstractPlugin*& plugin) override;

  /*!
   * \brief isLoaded function returns true if the plugin is loaded; otherwise returns false.
   * \return bolean of status.
   */
 __tegra_no_discard bool isLoaded() override;

private:
  TEGRA_DEFAULT_OCTORS(PluginManager)
  bool m_status = {false};
  Tegra::Scope<PluginManagerPimpl> m_implementation;
};


#endif // TEGRA_PLUGIN_MANAGER_HPP
