//! Tegra's Groups.
#ifdef __has_include
# if __has_include(<abstracts/groups>)
#   include <abstracts/groups>
#else
#   error "Tegra's groups was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

/*!
 * \brief Constructs an abstract groups.
 */
AbstractGroups::AbstractGroups()
{
}

/*!
 * \brief Destroys the groups.
 */
AbstractGroups::~AbstractGroups()
{
}

TEGRA_NAMESPACE_END
