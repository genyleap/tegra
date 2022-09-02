/*!
 * @file        plugininterface.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Plugin interface system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_PLUGIN_INTERFACE_HPP
#define TEGRA_PLUGIN_INTERFACE_HPP

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

class PluginInterfaceImpl;

/*!
 * \brief The PluginInterface class is exported from the mail library.
 */
class __tegra_export PluginInterface : public AbstractPluginInterface
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(PluginInterface)
  //Return a static instance of this class
  static PluginInterface& instance();

  /*!
   * \brief addDetail function sets all information of plugins.
   * \param plist is type of PluginList [std::vector<PluginInfo>]
   */
  void addDetail(const PluginList& plist) __tegra_const_noexcept_override;

  /*!
   * \brief addName function sets name of plugins.
   * \param name of plugin.
   */
  void addName(const std::string& name) __tegra_const_noexcept_override;

  /*!
   * \brief setError function sets message of error inside plugins.
   * \param var is message of error.
   */
  void setError(const std::string& var) __tegra_const_noexcept_override;

  /*!
   * \brief getDetail function gets detail from plugins.
   * \return list of detail such as name, version and etc.
   */
  __tegra_no_discard PluginList& getDetail() __tegra_const_noexcept_override;

  /*!
   * \brief getNames function gets name of plugins.
   * \return list of plugin.
   */
  __tegra_no_discard NameList& getNames() __tegra_const_noexcept_override;

  /*!
   * \brief getErrors function gets list of errors.
   * \return list of errors as string [ErrorString : std::vector<std::string>].
   */
  __tegra_no_discard ErrorString& getErrors() __tegra_const_noexcept_override;

private:
  PluginInterfaceImpl*  m_pImpl = {nullptr};
  NameList              m_nameList;
  PluginList            m_pluginList;
  ErrorString           m_errors;
};


#endif // TEGRA_PLUGIN_INTERFACE_HPP
