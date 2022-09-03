//! Tegra's Device.
#ifdef __has_include
# if __has_include("device.hpp")
#   include "device.hpp"
#else
#   error "Tegra's device was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs an device.
 */
Device::Device()
{
}

/*!
 * \brief Destroys the device.
 */
Device::~Device()
{
}


bool Device::set(const std::vector<DeviceInfo>& device) __tegra_const_noexcept
{

}

DeviceInfo Device::get(const std::vector<OptionalNumeric>& memberId) __tegra_const_noexcept
{

}

TEGRA_NAMESPACE_END

