/*!
 * @file        usermanager.hpp
 * @brief       This file is part of the Tegra System.
 * @details     User manager for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_USER_MANAGER_HPP
#define TEGRA_USER_MANAGER_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

//! Tegra's Abstraction (Interfaces).
#ifdef __has_include
# if __has_include(<interface>)
#   include <interface>
#else
#   error "The abstractions of Tegra was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The UserManager class
 */
class __tegra_export UserManager : public Abstracts::Account::AbstractUserManager
{
public:
    UserManager();
    UserManager(const Abstracts::Account::UserData& userData);
    ~UserManager();

    /*!
     * \brief memberId function will retrieves user id (memberId).
     * \param array username is a user unique name.
     * \returns as numeric id.
     */
    __tegra_no_discard OptionalNumeric memberId(const std::vector<std::string>& username) __tegra_const_noexcept_override;

    /*!
     * \brief The get function returns all the data related to the user based on the memberId.
     * \param int|array ID of the user to be creates.
     * \returns as UserData.
     */

    __tegra_no_discard Abstracts::Account::UserData get(const Abstracts::Account::ArrayIds& ids) __tegra_const_noexcept_override;

    /*!
     * \brief Create a user in the system.
     * \param array user userData. The keys must match the names of the fields in the database.
     * \returns true, if the user registration process is successful.
     */
    __tegra_no_discard bool create(const std::vector<Abstracts::Account::UserData>& userData) __tegra_const_noexcept_override;

    /*!
     * \brief Update the user in the system.
     * \param int|array ID of the user to be updated.
     * \param array userData to update. The keys must match the usernames of the fields in the database.
     * \returns true, if the user information is successfully updated.
     */
    __tegra_no_discard bool update(const Abstracts::Account::ArrayIds& ids, const std::vector<Abstracts::Account::UserData>& userData) __tegra_const_noexcept_override;

    /*!
     * \brief Removing a user from the system.
     * \param int|array ID of the user to be deleted.
     * \returns true, if the target user is deleted successfully.
     */
    __tegra_no_discard bool remove(const Abstracts::Account::ArrayIds& ids) __tegra_const_noexcept_override;


private:
    Abstracts::Account::DataTransfer *dataTransferPtr{}; //! A pointer to DataTransfer.
};

TEGRA_NAMESPACE_END

#endif // TEGRA_USER_MANAGER_HPP
