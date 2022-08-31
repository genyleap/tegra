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
#include "account/usermedia.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;
TEGRA_USING_NAMESPACE Tegra::Account;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

/*!
 * \brief The UserTypes enum
 */
__tegra_enum_class UserTypes
    {
        Guest           =   0x1,    ///< As a guest.
        Admin           =   0x2,    ///< As a administrator.
        Master          =   0x3,    ///< As a master/root.
        Moderator       =   0x4,    ///< As a moderator.
        Robot           =   0x5,    ///< As a robot.
        BySystemGroup   =   0x6,    ///< As a system group.
        ByCustomGroup   =   0x7     ///< As a customized group.
    };

enum class Gender : u8
{
    Unknown, Male, Female
};

struct SocialAddress final
{
    OptionalString google       {}; ///< Google/Gmail.
    OptionalString instagram    {}; ///< Instagram.
    OptionalString twitter      {}; ///< Twitter.
    OptionalString telegram     {}; ///< Telegram.
    OptionalString facebook     {}; ///< Facebook.
    OptionalString discord      {}; ///< Discord.
    OptionalString whatsapp     {}; ///< WhatsApp.
    OptionalString github       {}; ///< Github.
    OptionalString extra        {}; ///< Extra Options.
};

struct PersonalLinks final
{
    Optional<SocialAddress> social  {}; ///< Social Media.
    OptionalString email            {}; ///< Email Address.
    OptionalString web              {}; ///< Personal/Business Website.
    OptionalString extra            {}; ///< Extra Options.
};

struct UserMedia final
{
    Optional<Avatar>  avatar  {}; ///< Avatar.
    Optional<Image>   image   {}; ///< Image.
    Optional<Cover>   cover   {}; ///< Cover.
    Optional<Story>   story   {}; ///< Story.
};

struct PhoneNumbers final
{
    OptionalString mobile           {}; ///< Mobile Number.
    OptionalString tel              {}; ///< Telephone Number.
    OptionalString extra            {}; ///< Extra Options.
};


struct UserData final
{
    OptionalNumeric         memberId    {}; ///< User ID.
    OptionalString          username    {}; ///< Username.
    OptionalString          firstname   {}; ///< Firstname.
    OptionalString          lastname    {}; ///< Lastname.
    OptionalString          password    {}; ///< Password.
    Optional<GroupData>     groups      {}; ///< Group.
    Optional<PersonalLinks> links       {}; ///< Links.
    Optional<SocialAddress> social      {}; ///< Links.
    Optional<Gender>        gender      {}; ///< Gender.
    Optional<PhoneNumbers>  phone       {}; ///< Gender.
    Optional<UserMedia>     media       {}; ///< User Media.
    OptionalString          extra       {}; ///< Extra Options.
};

TEGRA_NAMESPACE_END

#endif // USER_DATA_ABSTRACT_HPP
