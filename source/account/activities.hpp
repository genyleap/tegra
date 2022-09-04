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

#ifndef TEGRA_USER_ACTIVITIES_HPP
#define TEGRA_USER_ACTIVITIES_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

//! Tegra's Abstraction (Interfaces).
#ifdef __has_include
# if __has_include(<interface>)
#   include <interface>
#else
#   error "The abstractions of Tegra was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The AbstractActivities class
 */
class __tegra_export Activities : public Abstracts::Account::AbstractActivities
{
public:
    Activities();
    ~Activities();

    /*!
     * \brief function get will gets user activities.
     * \param memberId is unique id for user.
     * \returns as Activity data.
     */
    __tegra_no_discard Abstracts::Account::ActivityData get(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief set function will sets user activities.
     * \param activity is data based on Activity struct members.
     */
    __tegra_virtual void set(const Abstracts::Account::ActivityData& activity) __tegra_const_noexcept_override;

private:
    Abstracts::Account::ActivityData m_activity;
    TEGRA_DISABLE_COPY(Activities)
};

TEGRA_NAMESPACE_END

#endif // TEGRA_USER_ACTIVITIES_HPP
