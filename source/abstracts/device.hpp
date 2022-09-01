/*!
 * @file        device.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Device interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef DEVICE_ABSTRACT_HPP
#define DEVICE_ABSTRACT_HPP

#include "common.hpp"
#include "core/core.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Types;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

enum class DeviceState : u8
{
    Online, Offline
};

struct DeviceInfo final
{
    //!Statics
    OptionalNumeric id          {}; ///< Device ID.
    OptionalString  title       {}; ///< Device Title.
    OptionalString  description {}; ///< Device Description.
    OptionalString  ipAddress   {}; ///< Device IP Address.
    OptionalString  macAddress  {}; ///< Device Mac Address.
    //!Dynamics
    Optional<DeviceType> type   {}; ///< Device Type (Desktop, Mobile and etc.).
    Optional<DeviceState> state {}; ///< Device State.
};

/*!
 * \brief The AbstractDevice class
 */
class __tegra_export AbstractDevice
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractDevice)

    /*!
     * \brief set function will registers new device.
     * \param device as array holds DeviceInfo.
     * \returns as boolean.
     */
    __tegra_no_discard_virtual bool set(const std::vector<DeviceInfo>& device) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief get function will reterives user-agent data from user's device only.
     * \param memberId as array is unique user id.
     * \returns DeviceInfo as data.
     */
    __tegra_no_discard_virtual DeviceInfo get(const std::vector<OptionalNumeric>& memberId) __tegra_const_noexcept = __tegra_zero;


private:
    DeviceInfo *deviceInfoPtr{};
    TEGRA_DISABLE_COPY(AbstractDevice)
};

TEGRA_NAMESPACE_END

#endif  // DEVICE_ABSTRACT_HPP
