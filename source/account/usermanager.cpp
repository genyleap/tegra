//! Tegra's Account Usermanager.
#ifdef __has_include
# if __has_include("account/usermanager.hpp")
#   include "account/usermanager.hpp"
#else
#   error "Tegra's usermanager was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Account;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs a user manager.
 */
UserManager::UserManager()
{
    __tegra_safe_instance(dataTransferPtr, DataTransfer);
    __tegra_safe_instance(dataTransferPtr->userDataPtr, UserData);
}

/*!
 * \brief Constructs a user manager.
 */
UserManager::UserManager(const UserData& userData)
{
    __tegra_safe_instance(dataTransferPtr, DataTransfer);
    __tegra_safe_instance_rhs(dataTransferPtr->userDataPtr, UserData, userData);
}

/*!
 * \brief Destroys the usermanager.
 */
UserManager::~UserManager()
{
    __tegra_safe_delete(dataTransferPtr);
    __tegra_safe_delete(dataTransferPtr->userDataPtr);
}

OptionalNumeric UserManager::memberId(const std::vector<std::string>& username) __tegra_const_noexcept
{

}

UserData UserManager::get(const ArrayIds& ids) __tegra_const_noexcept
{

}

bool UserManager::create(const std::vector<UserData>& userData) __tegra_const_noexcept
{

}

bool UserManager::update(const ArrayIds& ids, const std::vector<UserData>& userData) __tegra_const_noexcept
{

}

bool UserManager::remove(const ArrayIds& ids) __tegra_const_noexcept
{

}

TEGRA_NAMESPACE_END
