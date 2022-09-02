/*!
 * @file        modulemanager.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Module manager interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef MODULE_MANAGER_ABSTRACT_HPP
#define MODULE_MANAGER_ABSTRACT_HPP

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

//! Tegra's Module interface.
#ifdef __has_include
# if __has_include("moduleinterface.hpp")
#   include "moduleinterface.hpp"
#else
#   error "Tegra's module interface was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

// Define the prototype for a function that should exist in the lib
// that is used to create and return the module type in the lib.

TEGRA_POINTER_TO_AN_OBJECT(AbstractModule, fnCreateModule)

// Destroys the module type from the lib before the library is unloaded.
using fnDestroyModule = TEGRA_POINTER_TO_A_FUNCTION;

using ModuleMap  =  std::map<std::string, AbstractModule*>;

using LibraryMap =  std::map<std::string, void*>;

/*!
 * \brief The ModuleManagerData class
 */
class ModuleManagerData final
{
public:
    ModuleMap   modules {};
    LibraryMap  libs    {};
};

/*!
 * \brief The AbstractModuleManager class
 */
class __tegra_export AbstractModuleManager
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractModuleManager)
    /*!
     * \brief load function loads the module and returns true if the module was loaded successfully; otherwise returns false.
     * \param module is module name.
     * \returns module.
     */
    __tegra_no_discard_virtual AbstractModule* load(const std::string& module) = __tegra_zero;

    /*!
     * \brief unload function unloads the module and returns true if the module could be unloaded; otherwise returns false.
     * \param module
     */
    __tegra_virtual void unload(AbstractModule*& module) = __tegra_zero;

    /*!
     * \brief isLoaded function returns true if the module is loaded; otherwise returns false.
     * \return bolean of status.
     */
    __tegra_no_discard_virtual bool isLoaded() = __tegra_zero;

private:
    ModuleManagerData* m_moduleManagerData;
    bool m_status = {false};
};

TEGRA_NAMESPACE_END

#endif  // MODULE_MANAGER_ABSTRACT_HPP
