//! Tegra's Activities.
#ifdef __has_include
# if __has_include(<abstracts/activities>)
#   include <abstracts/activities>
#else
#   error "Tegra's activities was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

/*!
 * \brief Constructs an abstract activities.
 */
AbstractActivities::AbstractActivities()
{
}

/*!
 * \brief Destroys the abstract activities.
 */
AbstractActivities::~AbstractActivities()
{
}

TEGRA_NAMESPACE_END
