/*!
 * @file        api.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Api interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_API_ABSTRACT_HPP
#define TEGRA_API_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The API authentication process validates the identity of the client attempting to make a connection by using an authentication protocol.
 * And for this there are different methods that we cover.
 */
__tegra_enum_class AuthenticationType : u8
{
    NoAuth          =   0x0,  ///< No any authorization.
    ApiKey          =   0x1,  ///< Authentication based on ApiKey.
    BearerToken     =   0x2,  ///< Authentication based on BearerToken.
    BasicAuth       =   0x3,  ///< Authentication based on BasicAuth.
    DigestAuth      =   0x4,  ///< Authentication based on DigestAuth.
    OAuth1_0        =   0x5,  ///< Authentication based on OAuth1.0.
    OAuth2_0        =   0x6,  ///< Authentication based on OAuth2.0.
    Hawk            =   0x7,  ///< Authentication based on Hawk.
    AwsSignature    =   0x8,  ///< Authentication based on AWS Signature.
    Customized      =   0x9   ///< Authentication based on Customized method.
};

/*!
 * \brief The AbstractApi class
 */
class __tegra_export AbstractApi
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractApi)

    /*!
     * \brief get function will gets output of access string.
     * \returns as final string.
     */
    __tegra_no_discard __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractApi)
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_API_ABSTRACT_HPP
