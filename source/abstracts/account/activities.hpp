/*!
 * @file        activities.hpp
 * @brief       This file is part of the Tegra System.
 * @details     User activities interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef USER_ACTIVITIES_ABSTRACT_HPP
#define USER_ACTIVITIES_ABSTRACT_HPP

#include "common.hpp"
#include "profiledata.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

enum class ActivityAction : u8
{
    SignUp,
    SignIn,
    Update,
    Rules,
    Download,
    Upload,
    Create,
    Remove,
    Rename,
    Change,
    Buy,
    Sell,
    Forward,
    Reply,
    View,
    Move
};

struct Activity final
{
    OptionalString datetime         {};
    OptionalString ipAddress        {};
    Optional<ActivityAction> action {};
};

/*!
 * \brief The AbstractActivities class
 */
class __tegra_export AbstractActivities
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractActivities)

    /*!
     * \brief function get will gets user activities.
     * \param memberId is unique id for user.
     * \returns as Activity data.
     */
    __tegra_no_discard_virtual Activity get(const OptionalNumeric memberId) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief set function will sets user activities.
     * \param activity is data based on Activity struct members.
     */
    __tegra_virtual void set(const Activity& activity) __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractActivities)
    Activity m_activity;
};

TEGRA_NAMESPACE_END

#endif // USER_ACTIVITIES_ABSTRACT_HPP