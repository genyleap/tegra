//! Tegra's Abstract Base.
#ifdef __has_include
# if __has_include("abstracts/base.hpp")
#   include "abstracts/base.hpp"
#else
#   error "Tegra's base was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract base class.
 */
AbstractBaseClass::AbstractBaseClass()
{
}

/*!
 * \brief Destroys the base class.
 */
AbstractBaseClass::~AbstractBaseClass()
{
}


TEGRA_NAMESPACE_END
