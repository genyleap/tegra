/*!
 * @file        user.hpp
 * @brief       This file is part of the Tegra System.
 * @details     User interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef USER_ABSTRACT_HPP
#define USER_ABSTRACT_HPP

#include "common.hpp"
#include "userdata.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

class __tegra_export AbstractUser
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractUser)

private:
    UserData *userDataPtr{};
};

TEGRA_NAMESPACE_END

#endif // USER_ABSTRACT_HPP
