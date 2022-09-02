/*!
 * @file        modulemanager.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Module manager system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_MODULE_MANAGER_HPP
#define TEGRA_MODULE_MANAGER_HPP

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

TEGRA_USING_NAMESPACE Tegra::Abstracts;

class ModuleManagerPimpl;

/*!
 * \brief The ModuleManager class
 */
class __tegra_export ModuleManager : public AbstractModuleManager
{
public:
  static ModuleManager& instance();

  /*!
   * \brief load function loads the module and returns true if the module was loaded successfully; otherwise returns false.
   * \param module is module name.
   * \return module.
   */
  __tegra_no_discard AbstractModule* load(const std::string& module) override;

  /*!
   * \brief unload function unloads the module and returns true if the module could be unloaded; otherwise returns false.
   * \param module
   */
  void unload(AbstractModule*& module) override;

  /*!
   * \brief isLoaded function returns true if the module is loaded; otherwise returns false.
   * \return bolean of status.
   */
 __tegra_no_discard bool isLoaded() override;

private:
  TEGRA_DEFAULT_OCTORS(ModuleManager)
  bool m_status = {false};
  std::unique_ptr<ModuleManagerPimpl> m_implementation;
};


#endif // TEGRA_MODULE_MANAGER_HPP
