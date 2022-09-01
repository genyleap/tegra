/*!
 * @file        userdata.hpp
 * @brief       This file is part of the Tegra System.
 * @details     UserData interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef USER_DATA_ABSTRACT_HPP
#define USER_DATA_ABSTRACT_HPP

#include "common.hpp"
#include "groups.hpp"
#include "usermedia.hpp"
#include "basicdata.hpp"
#include "account/usermedia.hpp"
#include "account/activities.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;
TEGRA_USING_NAMESPACE Tegra::Account;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

/*!
 * \brief The UserData class
 */
struct UserData __tegra_final
{
    UserBasicData basic {}; ///< Basic Data (Default & Required)
};

TEGRA_NAMESPACE_END

#endif // USER_DATA_ABSTRACT_HPP
