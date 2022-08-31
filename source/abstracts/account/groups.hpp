/*!
 * @file        groups.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Groups manager interface for accounts.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef GROUPS_ABSTRACT_HPP
#define GROUPS_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

__tegra_enum_class SpecialType : u8
{
    AsDefaultUsers      =   0x1,    ///< As a Simple user [Limited].
    AsDevelopers        =   0x2,    ///< As a Developer/Programmer.
    AsDesigners         =   0x3,    ///< As a Designer.
    AsManagers          =   0x4,    ///< As a Manager.
    AsRobots            =   0x5,    ///< As a Robot.
    AsFullAccess        =   0x6     ///< As a master with all privileges.
};

/*!
 * \brief The GroupData class
 */
struct GroupData __tegra_final
{
    u32                 id              {};     ///< Id for group.
    OptionalString      title           {};     ///< Title for group.
    OptionalString      description     {};     ///< Description for group.
    u32                 parentId        {};     ///< Parent's id.
    OptionalBool        protection      {};     ///< Group's protection mode.
    OptionalString      icon            {};     ///< Icon for group.
    u32                 stars           {};     ///< Total of stars.
    OptionalString      stylePrefix     {};     ///< Custom style for prefix.
    OptionalString      styleSuffix     {};     ///< Custom style for suffix.
    OptionalString      doHtml          {};     ///< Can insert html tag inside posts.
    OptionalString      service         {};     ///< Service for group.
    OptionalString      module          {};     ///< Module for group.
    OptionalString      plugin          {};     ///< Plugin for group.
    OptionalBool        root            {};     ///< Group can be access as root permission.
    OptionalBool        master          {};     ///< Group can be access as master permission.
    OptionalNumeric     maxUpload       {};     ///< Maximum upload size.
    OptionalNumeric     maxDownload     {};     ///< Maximum download size.
    OptionalNumeric     maxPayment      {};     ///< Maximum payment count.
    OptionalBool        captcha         {};     ///< Enable captcha for group or not.
    OptionalBool        moderate        {};     ///< Group can access to site as moderator.
    OptionalString      platforms       {};     ///< Usable platforms.
    OptionalBool        hasSign         {};     ///< Group can has sign under the posts.
    u32                 report          {};     ///< Total of reports.
    u32                 rate            {};     ///< Total of rates.
    OptionalBool        createOwnUser   {};     ///< Can create own user [sub user].
    OptionalBool        createOwnPost   {};     ///< Can create own post.
    OptionalBool        editOwnPost     {};     ///< Can edit own posts.
    OptionalBool        editAllPost     {};     ///< Can edit all posts.
    OptionalBool        hideOwnPost     {};     ///< Can hide own posts.
    OptionalBool        hideAllPost     {};     ///< Can hide all posts.
    OptionalBool        removeOwnPost   {};     ///< Can remove own posts.
    OptionalBool        removeAllPost   {};     ///< Can remove all posts.
    OptionalBool        changeOwnPost   {};     ///< Can change own posts.
    OptionalBool        canPromote      {};     ///< Can promote own posts.
    OptionalBool        canCoverChange  {};     ///< Can change own cover.
    OptionalBool        canAvatarChange {};     ///< Can change own avatar.
    OptionalBool        editProfile     {};     ///< Can edit profile details.
    OptionalBool        useAnimation    {};     ///< Can use animation file like gif or lotties.
    OptionalNumeric     maxCoverSize    {};     ///< Maximum cover size.
    OptionalNumeric     maxAvatarSize   {};     ///< Maximum avatar size.
    OptionalBool        banned          {};     ///< Banned mode.
    OptionalNumeric     floodLimit      {};     ///< Flood limitation.
    OptionalNumeric     searchLimit     {};     ///< Search limitation.
    OptionalBool        accessClosed    {};     ///< Can access to closed site.
    SpecialType         special         {};     ///< Is special group.
    OptionalBool        apiAccess       {};     ///< Can access to api as developer.
};

/*!
 * \brief The AbstractGroups class
 */
class __tegra_export AbstractGroups
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractGroups)

    /*!
     * \brief add function will add new group.
     * \param groupData is contains all data of permissions.
     * \returns boolean.
     */
    __tegra_no_discard_virtual bool add(const GroupData& groupData) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief edit function will update group.
     * \param id is unique id for group.
     * \param groupData is all data for group.
     * \returns boolean.
     */
    __tegra_no_discard_virtual bool edit(const u32 id, const GroupData& groupData) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief remove function will remove group by own id.
     * \param id is unique id for group.
     * \returns boolean.
     */
    __tegra_no_discard_virtual bool remove(const u32 id) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief get function will returns all data from group.
     * \param id is unique id for group.
     * \returns GroupData as own data.
     */
    __tegra_no_discard_virtual GroupData get(const u32 id) __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractGroups)
    GroupData* m_groupData;
};

TEGRA_NAMESPACE_END

#endif  // GROUPS_ABSTRACT_HPP
