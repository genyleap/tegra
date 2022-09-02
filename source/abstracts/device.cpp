//! Tegra's Abstract Device.
#ifdef __has_include
# if __has_include("abstracts/device.hpp")
#   include "abstracts/device.hpp"
#else
#   error "Tegra's device was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract device.
 */
AbstractDevice::AbstractDevice()
{
}

/*!
 * \brief Destroys the abstract device.
 */
AbstractDevice::~AbstractDevice()
{
}

TEGRA_NAMESPACE_END
