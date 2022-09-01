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

#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "common.hpp"
#include "core/core.hpp"
#include "abstracts/device.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Types;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Abstracts;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The Device class
 */
class __tegra_export Device : public AbstractDevice
{
public:
    Device();
    ~Device();

    /*!
     * \brief set function will registers new device.
     * \param device as array holds DeviceInfo.
     * \returns as boolean.
     */
    __tegra_no_discard bool set(const std::vector<DeviceInfo>& device) __tegra_const_noexcept_override;

    /*!
     * \brief get function will reterives user-agent data from user's device only.
     * \param memberId as array is unique user id.
     * \returns DeviceInfo as data.
     */
    __tegra_no_discard DeviceInfo get(const std::vector<OptionalNumeric>& memberId) __tegra_const_noexcept_override;


private:
    DeviceInfo *deviceInfoPtr{};
    TEGRA_DISABLE_COPY(Device)
};

TEGRA_NAMESPACE_END

#endif  // DEVICE_HPP
