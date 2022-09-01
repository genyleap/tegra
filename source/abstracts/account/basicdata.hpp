/*!
 * @file        basicdata.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Basic Data interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef USER_BASIC_DATA_ABSTRACT_HPP
#define USER_BASIC_DATA_ABSTRACT_HPP

#include "common.hpp"
#include "groups.hpp"
#include "usermedia.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

class Device;
class Activities;
class Timezone;

struct ExtraKey __tegra_final
{
    int            keyAsInt    {};
    std::string    keyAsString {};
};

//! Extra option by key and value.
using ExtraField = std::map<ExtraKey*, std::string>;

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

__tegra_enum_class Gender : u8 { Unknown, Male, Female };

__tegra_enum_class Editors : u8 { Default, CKEditor, TinyMCE, Other };

struct PhysicalAddress __tegra_final
{
    OptionalString country      {}; ///< Country.
    OptionalString state        {}; ///< State.
    OptionalString city         {}; ///< City.
    OptionalString street       {}; ///< Street.
    OptionalString alley        {}; ///< Alley.
    OptionalString plaque       {}; ///< Plaque.
    //!Extra
    Optional<ExtraField> extra  {}; ///< Extra.
};

struct SocialAddress __tegra_final
{
    OptionalString google       {}; ///< Google/Gmail.
    OptionalString instagram    {}; ///< Instagram.
    OptionalString twitter      {}; ///< Twitter.
    OptionalString telegram     {}; ///< Telegram.
    OptionalString linkedin     {}; ///< LinkedIn.
    OptionalString facebook     {}; ///< Facebook.
    OptionalString discord      {}; ///< Discord.
    OptionalString whatsapp     {}; ///< WhatsApp.
    OptionalString github       {}; ///< Github.
    //!Extra
    Optional<ExtraField> extra  {}; ///< Extra.
};

struct PersonalLinks __tegra_final
{
    Optional<SocialAddress> social  {}; ///< Social Media.
    OptionalString email            {}; ///< Email Address.
    OptionalString web              {}; ///< Personal/Business Website.
    Optional<ExtraField> extra      {}; ///< Extra.
};

struct DateTimesData
{
    OptionalString created      {}; ///< Created time.
    OptionalString lastvisit    {}; ///< Last visit time.
    OptionalString updatedTime  {}; ///< Updated time.
};

struct BanData
{
    OptionalBool   banned   {}; ///< Banned mode.
    OptionalString explain  {}; ///< Ban explain.
    OptionalString until    {}; ///< Ban until.
};

struct UserMedia __tegra_final
{
//    Optional<Avatar>  avatar  {}; ///< Avatar.
//    Optional<Image>   image   {}; ///< Image.
//    Optional<Cover>   cover   {}; ///< Cover.
//    Optional<Story>   story   {}; ///< Story.
};

struct PhoneNumbers __tegra_final
{
    OptionalString mobile           {}; ///< Mobile Number.
    OptionalString tel              {}; ///< Telephone Number.
    Optional<ExtraField> extra      {}; ///< Extra.
};

struct NetworkAddress __tegra_final
{
    OptionalString   ipv4  {}; ///< IP Version 4 Address.
    OptionalString   ipv6  {}; ///< IP Version 6 Address.
    OptionalString   mac   {}; ///< Mac Address.
};

struct MetaStrings __tegra_final
{
    OptionalString   bio        {}; ///< Bio Data.
    OptionalString   signature  {}; ///< Signature.
    Optional<ExtraField> extra  {}; ///< Extra.
};

struct Referrals __tegra_final
{
    OptionalString   referral  {}; ///< Referral For.
    OptionalString   invited   {}; ///< Invited From.
};

struct UserBasicData __tegra_final
{
    //! Raw Numeric
    OptionalNumeric             memberId     {}; ///< User ID.
    //! Raw String
    OptionalString              username     {}; ///< Username.
    OptionalString              firstname    {}; ///< Firstname.
    OptionalString              lastname     {}; ///< Lastname.
    OptionalString              password     {}; ///< Password.
    OptionalString              signature    {}; ///< Signature.
    OptionalString              birthday     {}; ///< Birthday.
    OptionalString              language     {}; ///< Language.
    //! By Classes & Enums.
    Optional<Gender>            gender       {}; ///< Gender.
    Optional<GroupData>         groups       {}; ///< Group.
    Optional<UserMedia>         media        {}; ///< User Media.
    Optional<PhoneNumbers>      phone        {}; ///< Gender.
    Optional<PersonalLinks>     links        {}; ///< Links.
    Optional<SocialAddress>     social       {}; ///< Social Network.
    Optional<PhysicalAddress>   address      {}; ///< Physical Address.
    Optional<NetworkAddress>    networkAddr  {}; ///< Network Address.
    Optional<Timezone*>         timezone     {}; ///< Timezone.
    Optional<Device*>           devices      {}; ///< Devices.
    Optional<Activities*>        activities   {}; ///< User Activities.
    Optional<DateTimesData>     datetime     {}; ///< User Datetimes data.
    Optional<BanData>           ban          {}; ///< Ban Data.
    Optional<Referrals>         referrals    {}; ///< Referrals.
    Optional<MetaStrings>       metastring   {}; ///< Meta String.
    Optional<Editors>           editor       {}; ///< User Editor.
    //! Raw Boolean
    OptionalBool                completed    {}; ///< Completed Mode.
    OptionalBool                subscription {}; ///< Subscription Mode.
    OptionalBool                status       {}; ///< User Status.
    //! Raw ExtraField
    Optional<ExtraField>        extra        {}; ///< Extra Options.
};

TEGRA_NAMESPACE_END

#endif // USER_BASIC_DATA_ABSTRACT_HPP
