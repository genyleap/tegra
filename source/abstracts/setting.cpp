//! Tegra's Abstract Setting.
#ifdef __has_include
# if __has_include("abstracts/setting.hpp")
#   include "abstracts/setting.hpp"
#else
#   error "Tegra's setting was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract setting.
 */
AbstractSetting::AbstractSetting()
{
}

/*!
 * \brief Destroys the setting.
 */
AbstractSetting::~AbstractSetting()
{
}

TEGRA_NAMESPACE_END
