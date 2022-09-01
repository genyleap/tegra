#include "usermanager.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

/*!
 * \brief Constructs an abstract user manager.
 */
AbstractUserManager::AbstractUserManager()
{
    __tegra_safe_instance(dataTransferPtr, DataTransfer);
    __tegra_safe_instance(dataTransferPtr->userDataPtr, UserData);
}

/*!
 * \brief Constructs an abstract user manager.
 */
AbstractUserManager::AbstractUserManager(const UserData& userData)
{
    __tegra_safe_instance(dataTransferPtr, DataTransfer);
    __tegra_safe_instance_rhs(dataTransferPtr->userDataPtr, UserData, userData);
}

/*!
 * \brief Destroys the usermanager.
 */
AbstractUserManager::~AbstractUserManager()
{
    __tegra_safe_delete(dataTransferPtr);
    __tegra_safe_delete(dataTransferPtr->userDataPtr);
}

TEGRA_NAMESPACE_END
