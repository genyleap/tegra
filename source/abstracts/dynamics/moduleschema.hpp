/*!
 * @file        moduleschema.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Schema structs for module system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef MODULE_SCHEMA_ABSTRACT_HPP
#define MODULE_SCHEMA_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Module)

/*!
 * \brief The ModuleType enum
 */
__tegra_enum_class ModuleType : u8
{
    Index,      //!For global user service.
    Admin,      //!For administrator service.
    System,     //!For system service.
    Service,    //!!For external or internal service.
    Default,    //!For default global service.
    Custom      //!For custom global service.
};

/*!
 * \brief The PermissionType enum
 */
__tegra_enum_class PermissionType
{
    ReadOnly,
    EditableOnly,
    Restricted,
    FullAccess,
    ByService
};

/*!
 * \brief The ModuleInfo class
 */
struct ModuleInfo __tegra_final
{
    Optional<u32>               codeName        {}; ///< A unique code for module.
    OptionalString              name            {}; ///< A name for module.
    OptionalString              description     {}; ///< A description for explanation module.
    OptionalString              compiledDate    {}; ///< Compiled date for module.
    Optional<SystemLicense>     license         {}; ///< License type for module.
    ModuleType                  moduleType      {}; ///< The type of module.
    Optional<SemanticVersion>   version         {}; ///< Version of module.
    OptionalString              author          {}; ///< Author of module.
    OptionalString              url             {}; ///< Url of module.
};

TEGRA_NAMESPACE_END

#endif  // MODULE_SCHEMA_ABSTRACT_HPP
