//! Tegra's Timezone.
#ifdef __has_include
# if __has_include("timezone.hpp")
#   include "timezone.hpp"
#else
#   error "Tegra's timezone was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs an timezone.
 */
Timezone::Timezone()
{
}

/*!
 * \brief Destroys the timezone.
 */
Timezone::~Timezone()
{
}

TEGRA_NAMESPACE_END

