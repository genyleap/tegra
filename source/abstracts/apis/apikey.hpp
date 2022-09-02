/*!
 * @file        apikey.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Apikey interface for apis.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_APIKEY_ABSTRACT_HPP
#define TEGRA_APIKEY_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

//! Tegra's Abstract Api.
#ifdef __has_include
# if __has_include(<abstracts/api>)
#   include <abstracts/api>
#else
#   error "Tegra's api was not found!"
# endif
#endif


TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Apis)

/*!
 * \brief The AuthorizationInfo class
 * The user’s key and value.
 * The resulting string is simple.
 */
struct AuthorizationInfo __tegra_final
{
    OptionalString key;     ///< Key of user.
    OptionalString value;   ///< Value of user.
    OptionalString result;  ///< Result of string.
};

/*!
 * \brief The AddType enum
 */
__tegra_enum_class AddType : u8
{
    Header          =   0x0, ///< Add to header.
    QueryParameter  =   0x1, ///< Add to query as parameter.
};

/*!
 * \brief HTTP Basic Authentication.
 * The simplest way to handle authentication is through the use of HTTP, where the username and password are sent alongside every API call.
 * You can use an HTTP header and encode the username and password. Note that does not mean.
 * If you end up using HTTP Basic Authentication, use it through HTTPS so the connection between the parties is encrypted.
 */
class __tegra_export AbstractApiKey : protected AbstractApi
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractApiKey)

    /*!
     * \brief get function will gets output of access string.
     * \returns as final string.
     */
   __tegra_no_discard __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractApiKey)
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_APIKEY_ABSTRACT_HPP
