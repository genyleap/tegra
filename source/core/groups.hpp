/*!
 * @file        groups.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Groups manager for accounts.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef GROUPS_HPP
#define GROUPS_HPP

#include "common.hpp"
#include "abstracts/account/groups.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Account;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The Groups class
 */
class __tegra_export Groups : public AbstractGroups
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Groups)

    /*!
     * \brief add function will add new group.
     * \param groupData is contains all data of permissions.
     * \returns boolean.
     */
    __tegra_no_discard bool add(const GroupData& groupData) __tegra_const_noexcept_override;

    /*!
     * \brief edit function will update group.
     * \param id is unique id for group.
     * \param groupData is all data for group.
     * \returns boolean.
     */
    __tegra_no_discard bool edit(const u32 id, const GroupData& groupData) __tegra_const_noexcept_override;

    /*!
     * \brief remove function will remove group by own id.
     * \param id is unique id for group.
     * \returns boolean.
     */
    __tegra_no_discard bool remove(const u32 id) __tegra_const_noexcept_override;

    /*!
     * \brief get function will returns all data from group.
     * \param id is unique id for group.
     * \returns GroupData as own data.
     */
    __tegra_no_discard GroupData get(const u32 id) __tegra_const_noexcept_override;

private:
    TEGRA_DISABLE_COPY(Groups)
    GroupData* m_groupData;
};

TEGRA_NAMESPACE_END

#endif  // GROUPS_HPP
