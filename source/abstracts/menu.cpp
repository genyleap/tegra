//! Tegra's Abstract Menu.
#ifdef __has_include
# if __has_include("abstracts/menu.hpp")
#   include "abstracts/menu.hpp"
#else
#   error "Tegra's menu was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract menu item.
 */
AbstractMenuItem::AbstractMenuItem()
{
}

/*!
 * \brief Destroys the menu item.
 */
AbstractMenuItem::~AbstractMenuItem()
{
}

/*!
 * \brief Constructs an abstract menu.
 */
AbstractMenu::AbstractMenu()
{
}

/*!
 * \brief Destroys the menu.
 */
AbstractMenu::~AbstractMenu()
{
}

TEGRA_NAMESPACE_END
