/*!
 * @file        transfer.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Transfer interface for services.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TRANSFER_ABSTRACT_HPP
#define TRANSFER_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

// ToDo change for overridden version.
//! Tegra's Api.
#ifdef __has_include
# if __has_include(<abstracts/api>)
#   include <abstracts/api>
#else
#   error "Tegra's api was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Method of sending and receiving information.
 */
__tegra_enum_class TransferMethodState : u8
{
    Internal    =   0x1,  ///< Transfer from internal method.
    ExternalApi =   0x2,  ///< Transfer from external method like api.
    Customized  =   0x3   ///< Transfer from an other method.
};

struct TransferData __tegra_final
{
    TransferMethodState method   {};  ///< Transfer method for api service.
    AuthenticationType  auth     {};  ///< Authentication type for api service. // change with overridden version.
    OptionalString      path     {};  ///< Path for api service.
    OptionalString      output   {};  ///< Output from api service.
};

/*!
 * \brief The AbstractTransferMethod class
 */
class __tegra_export AbstractTransferMethod
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractTransferMethod)

    /*!
     * \brief The get function receives data through the interface.
     * \returns as optional string.
     */
    __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief Getting transfer method for service.
     * \returns method.
     */
    __tegra_virtual TransferMethodState getMethod() = __tegra_zero;

    /*!
     * \brief Change the method of service usage.
     * \param method is type of transfering between services.
     */
    __tegra_virtual void change(const TransferMethodState& method) = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractTransferMethod)
};
TEGRA_NAMESPACE_END

#endif  // TRANSFER_ABSTRACT_HPP
