//! Tegra's Abstract Service.
#ifdef __has_include
# if __has_include("abstracts/service.hpp")
#   include "abstracts/service.hpp"
#else
#   error "Tegra's service was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract activity.
 */
AbstractActivity::AbstractActivity()
{
}

/*!
 * \brief Destroys the activity.
 */
AbstractActivity::~AbstractActivity()
{
}

/*!
 * \brief Constructs an abstract service.
 */
AbstractService::AbstractService()
{
}

/*!
 * \brief Destroys the service.
 */
AbstractService::~AbstractService()
{
}

TEGRA_NAMESPACE_END
