//! Tegra's Abstract Configuration.
#ifdef __has_include
# if __has_include("abstracts/configuration.hpp")
#   include "abstracts/configuration.hpp"
#else
#   error "Tegra's configuration was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract configuration.
 */
AbstractConfiguration::AbstractConfiguration()
{
}

/*!
 * \brief Destroys the configuration.
 */
AbstractConfiguration::~AbstractConfiguration()
{
}

TEGRA_NAMESPACE_END
