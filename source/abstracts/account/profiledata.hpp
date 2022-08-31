/*!
 * @file        usermedia.hpp
 * @brief       This file is part of the Tegra System.
 * @details     User media interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef PROFILE_DATA_ABSTRACT_HPP
#define PROFILE_DATA_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

enum class AvatarViewStatus : u8
{
    NoAvatar, ForEveryone, SpecificGroups, SelectedUsers
};

enum class ImageViewStatus : u8
{
    NoAvatar, ForEveryone, SpecificGroups, SelectedUsers
};

enum class CoverViewStatus : u8
{
    NoAvatar, ForEveryone, SpecificGroups, SelectedUsers
};

enum class StoryViewStatus : u8
{
    NoAvatar, ForEveryone, SpecificGroups, SelectedUsers
};

TEGRA_NAMESPACE_END

#endif // PROFILE_DATA_ABSTRACT_HPP
