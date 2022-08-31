/*!
 * @file        activities.hpp
 * @brief       This file is part of the Tegra System.
 * @details     User activities class for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef USER_ACTIVITIES_HPP
#define USER_ACTIVITIES_HPP

#include "common.hpp"
#include "abstracts/account/activities.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Account;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Account)

/*!
 * \brief The AbstractActivities class
 */
class __tegra_export Activities : public AbstractActivities
{
public:
    TEGRA_DEFAULT_OCTORS(Activities)

    /*!
     * \brief function get will gets user activities.
     * \param memberId is unique id for user.
     * \returns as Activity data.
     */
    __tegra_no_discard Activity get(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief set function will sets user activities.
     * \param activity is data based on Activity struct members.
     */
    __tegra_virtual void set(const Activity& activity) __tegra_const_noexcept_override;

private:
    TEGRA_DISABLE_COPY(Activities)
    Activity m_activity;
};

TEGRA_NAMESPACE_END

#endif // USER_ACTIVITIES_HPP
