/*!
 * MIT License
 *
 * Copyright (c) 2022 The Genyleap. All rights reserved.
 * Copyright (c) 2022 Kambiz Asadzadeh.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TRANSFER_ABSTRACT_HPP
#define TRANSFER_ABSTRACT_HPP

#include "common.hpp"
#include "api.hpp"

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
    AuthenticationType  auth     {};  ///< Authentication type for api service.
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