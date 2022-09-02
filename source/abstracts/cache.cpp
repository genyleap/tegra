//! Tegra's Abstract Cache.
#ifdef __has_include
# if __has_include("abstracts/cache.hpp")
#   include "abstracts/cache.hpp"
#else
#   error "Tegra's cache was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract cache.
 */
AbstractCache::AbstractCache()
{
}

/*!
 * \brief Destroys the cache.
 */
AbstractCache::~AbstractCache()
{
}

TEGRA_NAMESPACE_END
