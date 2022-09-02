//! Tegra's Account Activities.
#ifdef __has_include
# if __has_include("account/activities.hpp")
#   include "account/activities.hpp"
#else
#   error "Tegra's activities are not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs an activities.
 */
Activities::Activities()
{
}

/*!
 * \brief Destroys the activities.
 */
Activities::~Activities()
{
}

ActivityData Activities::get(const OptionalNumeric memberId) __tegra_const_noexcept
{
  //! ToDo...
}

void Activities::set(const ActivityData& activity) __tegra_const_noexcept
{
  //! ToDo...
}

TEGRA_NAMESPACE_END



