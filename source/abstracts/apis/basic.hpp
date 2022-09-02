/*!
 * @file        basic.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Basic interface for apis.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef BASIC_API_ABSTRACT_HPP
#define BASIC_API_ABSTRACT_HPP

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
 * The user’s username and password are combined with a colon.
 * The resulting string is base64 encoded.
 */
struct AuthorizationInfo __tegra_final
{
    OptionalString username;  ///< Username of user.
    OptionalString password;  ///< Password of user.
    OptionalString result;    ///< Result of encoded.
};

/*!
 * \brief HTTP Basic Authentication.
 * The simplest way to handle authentication is through the use of HTTP, where the username and password are sent alongside every API call.
 * You can use an HTTP header and encode the username and password. Note that does not mean.
 * If you end up using HTTP Basic Authentication, use it through HTTPS so the connection between the parties is encrypted.
 */
class __tegra_export AbstractBasicApi : protected AbstractApi
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractBasicApi)

    /*!
     * \brief get function will gets output of access string.
     * \returns as final string.
     */
   __tegra_no_discard __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractBasicApi)
};

TEGRA_NAMESPACE_END

#endif  // BASIC_API_ABSTRACT_HPP
