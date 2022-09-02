//! Tegra's Abstract Page.
#ifdef __has_include
# if __has_include("abstracts/page.hpp")
#   include "abstracts/page.hpp"
#else
#   error "Tegra's page was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract page class.
 */
AbstractPage::AbstractPage()
{
}

/*!
 * \brief Destroys the page class.
 */
AbstractPage::~AbstractPage()
{
}


TEGRA_NAMESPACE_END
