/*!
 * @file        usermanager.hpp
 * @brief       This file is part of the Tegra System.
 * @details     User manager interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_USER_MANAGER_ABSTRACT_HPP
#define TEGRA_USER_MANAGER_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

//! Tegra's Core (Core Only).
#ifdef __has_include
# if __has_include(<core>)
#   include <core>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

//! Tegra's Abstraction (Interface).
#ifdef __has_include
# if __has_include(<abstracts/account>)
#   include <abstracts/account>
#else
#   error "The account abstraction of Tegra was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

using ArrayIds = std::vector<OptionalNumeric>; ///< Array as int for user id.

/*!
 * \brief The UserData class
 */
struct UserData __tegra_final
{
    UserBasicData basic {}; ///< Basic Data (Default & Required)
};

struct DataTransfer final
{
    System::DataGetway dataGetway {};   ///< Getway model.
    UserData* userDataPtr {};   ///< A pointer to UserData;
};

/*!
 * \brief The AbstractUserManager class
 */
class __tegra_export AbstractUserManager
{
public:
    AbstractUserManager();
    AbstractUserManager(const UserData& userData);
    __tegra_virtual ~AbstractUserManager();

    /*!
     * \brief memberId function will retrieves user id (memberId).
     * \param array username is a user unique name.
     * \returns as numeric id.
     */
    __tegra_no_discard_virtual OptionalNumeric memberId(const std::vector<std::string>& username) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief The get function returns all the data related to the user based on the memberId.
     * \param int|array ID of the user to be creates.
     * \returns as UserData.
     */

    __tegra_no_discard_virtual UserData get(const ArrayIds& ids) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief Create a user in the system.
     * \param array user userData. The keys must match the names of the fields in the database.
     * \returns true, if the user registration process is successful.
     */
    __tegra_no_discard_virtual bool create(const std::vector<UserData>& userData) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief Update the user in the system.
     * \param int|array ID of the user to be updated.
     * \param array userData to update. The keys must match the usernames of the fields in the database.
     * \returns true, if the user information is successfully updated.
     */
    __tegra_no_discard_virtual bool update(const ArrayIds& ids, const std::vector<UserData>& userData) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief Removing a user from the system.
     * \param int|array ID of the user to be deleted.
     * \returns true, if the target user is deleted successfully.
     */
    __tegra_no_discard_virtual bool remove(const ArrayIds& ids) __tegra_const_noexcept = __tegra_zero;


private:
    DataTransfer *dataTransferPtr{}; //! A pointer to DataTransfer.
};

TEGRA_NAMESPACE_END

#endif // TEGRA_USER_MANAGER_ABSTRACT_HPP
