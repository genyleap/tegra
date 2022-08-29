/*!
 * @file        moduleinterface.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Module interface system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef MODULE_INTERFACE_HPP
#define MODULE_INTERFACE_HPP

#include "common.hpp"
#include "abstracts/dynamics/moduleinterface.hpp"

TEGRA_USING_NAMESPACE Tegra::Abstracts;

class ModuleInterfaceImpl;

/*!
 * \brief The ModuleInterface class is exported from the mail library.
 */
class __tegra_export ModuleInterface : public AbstractModuleInterface
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(ModuleInterface)
  //Return a static instance of this class
  static ModuleInterface& instance();

  /*!
   * \brief addDetail function sets all information of modules.
   * \param plist is type of ModuleList [std::vector<ModuleInfo>]
   */
  void addDetail(const ModuleList& plist) __tegra_const_noexcept_override;

  /*!
   * \brief addName function sets name of modules.
   * \param name of module.
   */
  void addName(const std::string& name) __tegra_const_noexcept_override;

  /*!
   * \brief setError function sets message of error inside modules.
   * \param var is message of error.
   */
  void setError(const std::string& var) __tegra_const_noexcept_override;

  /*!
   * \brief getDetail function gets detail from modules.
   * \return list of detail such as name, version and etc.
   */
  __tegra_no_discard ModuleList& getDetail() __tegra_const_noexcept_override;

  /*!
   * \brief getNames function gets name of modules.
   * \return list of module.
   */
  __tegra_no_discard NameList& getNames() __tegra_const_noexcept_override;

  /*!
   * \brief getErrors function gets list of errors.
   * \return list of errors as string [ErrorString : std::vector<std::string>].
   */
  __tegra_no_discard ErrorString& getErrors() __tegra_const_noexcept_override;

private:
  ModuleInterfaceImpl*  m_pImpl = {nullptr};
  NameList              m_nameList;
  ModuleList            m_moduleList;
  ErrorString           m_errors;
};


#endif // MODULE_INTERFACE_HPP
