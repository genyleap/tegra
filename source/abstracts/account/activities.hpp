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

#ifndef TEGRA_USER_ACTIVITIES_ABSTRACT_HPP
#define TEGRA_USER_ACTIVITIES_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

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

struct ActivityData final
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
    __tegra_no_discard_virtual ActivityData get(const OptionalNumeric memberId) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief set function will sets user activities.
     * \param activity is data based on Activity struct members.
     */
    __tegra_virtual void set(const ActivityData& activity) __tegra_const_noexcept = __tegra_zero;

private:
    ActivityData m_activity;
};

TEGRA_NAMESPACE_END

#endif // TEGRA_USER_ACTIVITIES_ABSTRACT_HPP
