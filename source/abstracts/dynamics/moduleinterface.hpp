/*!
 * @file        moduleinterface.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Module interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_MODULE_INTERFACE_ABSTRACT_HPP
#define TEGRA_MODULE_INTERFACE_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

//! Tegra's Module.
#ifdef __has_include
# if __has_include("module.hpp")
#   include "module.hpp"
#else
#   error "Tegra's module was not found!"
# endif
#endif


TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

using NameList      =   std::vector<std::string>;
using ModuleList    =   std::vector<Abstracts::Module::ModuleInfo>;
using ErrorString   =   std::vector<std::string>;

/*!
 * \brief The ModuleInterfaceData class
 */
struct ModuleInterfaceData final
{
public:
    NameList    nameList    {};     ///< List of modules name.
    ModuleList  moduleList  {};     ///< List of modules by info.
    ErrorString errors      {};     ///< List of errors.
};

class __tegra_export AbstractModuleInterface
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractModuleInterface)
    //Return a static instance of this class
    static AbstractModuleInterface& instance();

    /*!
     * \brief addDetail function sets all information of modules.
     * \param plist is type of ModuleList [std::vector<ModuleDetail>]
     */
    __tegra_virtual void addDetail(const ModuleList& plist) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief addName function sets name of modules.
     * \param name of module.
     */
    __tegra_virtual void addName(const std::string& name) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief setError function sets message of error inside modules.
     * \param var is message of error.
     */
    __tegra_virtual void setError(const std::string& var) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getDetail function gets detail from modules.
     * \returns list of detail such as name, version and etc.
     */
    __tegra_no_discard_virtual const ModuleList& getDetail() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getNames function gets name of modules.
     * \returns list of module.
     */
    __tegra_no_discard_virtual const NameList& getNames() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getErrors function gets list of errors.
     * \returns list of errors as string [ErrorString : std::vector<std::string>].
     */
    __tegra_no_discard_virtual const ErrorString& getErrors() __tegra_const_noexcept = __tegra_zero;

private:
    ModuleInterfaceData*  m_moduleInterfaceData;
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_MODULE_INTERFACE_ABSTRACT_HPP
