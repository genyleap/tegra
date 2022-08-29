/*!
 * @file        plugininterface.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Plugin interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef PLUGIN_INTERFACE_ABSTRACT_HPP
#define PLUGIN_INTERFACE_ABSTRACT_HPP

#include "common.hpp"
#include "plugin.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

//struct PluginDetail
//{
//  OptionalString            codeName      {}; ///< Code Name.
//  OptionalString            name          {}; ///< Name.
//  OptionalString            description   {}; ///< Description.
//  OptionalString            compiledDate  {}; ///< Compiled Date.
//  Optional<SystemLicense>   license       {}; ///< License.
//  Optional<PluginType>      type          {}; ///< Type.
//  Optional<SemanticVersion> version       {}; ///< Version.
//  OptionalString            author        {}; ///< Author.
//  OptionalString            url           {}; ///< Url.
//};

using NameList      =   std::vector<std::string>;
using PluginList    =   std::vector<PluginInfo>;
using ErrorString   =   std::vector<std::string>;

/*!
 * \brief The PluginInterfaceData class
 */
struct PluginInterfaceData final
{
public:
    NameList    nameList    {};     ///< List of plugins name.
    PluginList  pluginList  {};     ///< List of plugins by info.
    ErrorString errors      {};     ///< List of errors.
};

class __tegra_export AbstractPluginInterface
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPluginInterface)
    //Return a static instance of this class
    static AbstractPluginInterface& instance();

    /*!
     * \brief addDetail function sets all information of plugins.
     * \param plist is type of PluginList [std::vector<PluginDetail>]
     */
    __tegra_virtual void addDetail(const PluginList& plist) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief addName function sets name of plugins.
     * \param name of plugin.
     */
    __tegra_virtual void addName(const std::string& name) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief setError function sets message of error inside plugins.
     * \param var is message of error.
     */
    __tegra_virtual void setError(const std::string& var) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getDetail function gets detail from plugins.
     * \returns list of detail such as name, version and etc.
     */
    __tegra_no_discard_virtual const PluginList& getDetail() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getNames function gets name of plugins.
     * \returns list of plugin.
     */
    __tegra_no_discard_virtual const NameList& getNames() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getErrors function gets list of errors.
     * \returns list of errors as string [ErrorString : std::vector<std::string>].
     */
    __tegra_no_discard_virtual const ErrorString& getErrors() __tegra_const_noexcept = __tegra_zero;

private:
    PluginInterfaceData*  m_pluginInterfaceData;
};


TEGRA_NAMESPACE_END

#endif  // PLUGIN_INTERFACE_ABSTRACT_HPP
