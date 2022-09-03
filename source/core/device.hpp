/*!
 * @file        device.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Device for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_DEVICE_HPP
#define TEGRA_DEVICE_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements are not found!"
# endif
#endif

//! Tegra's Abstraction (Interfaces).
#ifdef __has_include
# if __has_include(<interface>)
#   include <interface>
#else
#   error "The abstractions of Tegra are not found!"
# endif
#endif

//! Tegra's Application.
#ifdef __has_include
# if __has_include(<application>)
#   include <application>
#else
#   error "The application of Tegra are not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The Device class
 */
class __tegra_export Device : public Abstracts::AbstractDevice
{
public:
    Device();
    ~Device();

    /*!
     * \brief set function will registers new device.
     * \param device as array holds DeviceInfo.
     * \returns as boolean.
     */
    __tegra_no_discard bool set(const std::vector<Abstracts::DeviceInfo>& device) __tegra_const_noexcept_override;

    /*!
     * \brief get function will reterives user-agent data from user's device only.
     * \param memberId as array is unique user id.
     * \returns DeviceInfo as data.
     */
    __tegra_no_discard Abstracts::DeviceInfo get(const std::vector<OptionalNumeric>& memberId) __tegra_const_noexcept_override;


private:
    Abstracts::DeviceInfo *deviceInfoPtr{};
    TEGRA_DISABLE_COPY(Device)
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_DEVICE_HPP
