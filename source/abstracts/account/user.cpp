#include "user.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

/*!
 * \brief Constructs an abstract user.
 */
AbstractUser::AbstractUser()
{
    __tegra_safe_instance(userDataPtr, UserData);
}

/*!
 * \brief Destroys the user.
 */
AbstractUser::~AbstractUser()
{
    __tegra_safe_delete(userDataPtr);
}

TEGRA_NAMESPACE_END
