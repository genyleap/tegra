//! Tegra's Abstract Api.
#ifdef __has_include
# if __has_include("abstracts/api.hpp")
#   include "abstracts/api.hpp"
#else
#   error "Tegra's api was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract api.
 */
AbstractApi::AbstractApi()
{
}

/*!
 * \brief Destroys the api.
 */
AbstractApi::~AbstractApi()
{
}

TEGRA_NAMESPACE_END
