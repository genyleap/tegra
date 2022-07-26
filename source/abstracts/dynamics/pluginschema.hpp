/*!
 * @file        pluginschema.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Schema structs for plugin system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_PLUGIN_SCHEMA_ABSTRACT_HPP
#define TEGRA_PLUGIN_SCHEMA_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Plugin)

/*!
 * \brief The PluginType enum
 */
__tegra_enum_class PluginType : u8
{
    Index,      //!For global user service.
    Admin,      //!For administrator service.
    Root,       //!For root service.
    System,     //!For system service.
    Cron,       //!For cron job service.
    Core,       //!For system core service.
    Theme,      //!For system template.
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
 * \brief The PluginInfo class
 */
struct PluginInfo __tegra_final
{
    OptionalString              codeName        {}; ///< A unique code for plugin.
    OptionalString              name            {}; ///< A name for plugin.
    OptionalString              description     {}; ///< A description for explanation plugin.
    OptionalString              compiledDate    {}; ///< Compiled date for plugin.
    Optional<SystemLicense>     license         {}; ///< License type for plugin.
    PluginType                  pluginType      {}; ///< The type of plugin.
    Optional<SemanticVersion>   version         {}; ///< Version of plugin.
    OptionalString              author          {}; ///< Author of plugin.
    OptionalString              url             {}; ///< Url of plugin.
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_PLUGIN_SCHEMA_ABSTRACT_HPP
