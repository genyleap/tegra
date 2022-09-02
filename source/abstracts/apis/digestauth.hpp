/*!
 * @file        digestauth.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Digestauth interface for apis.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef DIGEST_AUTH_ABSTRACT_HPP
#define DIGEST_AUTH_ABSTRACT_HPP

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
 * The digest data for mixing.
 */
struct AuthorizationInfo __tegra_final
{
    OptionalString username;    ///< Username of user.
    OptionalString password;    ///< Password of user.
    OptionalString realm;       ///< A string describing a protected area.
    OptionalString nonce;       ///< A server-specified quoted string that the server can use to control the lifetime in which particular credentials will be considered valid.
    OptionalString algorithm;   ///< Algorithm used to produce the digest.
    OptionalString qop;         ///< Quoted string indicating the quality of protection supported by the server.
    OptionalString nonceCount;  ///< The nonce counter.
    OptionalString clientNonce; ///< The nonce value is opaque to the client.
    OptionalString opaque;      ///< A server-specified quoted string that should be returned unchanged in the Authorization.
    OptionalString result;      ///< Result of final mixed string.
};

/*!
 * \brief HTTP Digest Auth.
 * A Bearer Token is an opaque string, not intended to have any meaning to clients using it.
 */
class __tegra_export AbstractDigestAuth : protected AbstractApi
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractDigestAuth)

    /*!
     * \brief get function will gets output of access string.
     * \returns as final string.
     */
   __tegra_no_discard __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractDigestAuth)
};

TEGRA_NAMESPACE_END

#endif  // DIGEST_AUTH_ABSTRACT_HPP
