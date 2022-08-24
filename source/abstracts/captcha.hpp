/*!
 * @file        captcha.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Captcha interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef CAPTCHA_ABSTRACT_HPP
#define CAPTCHA_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The AbstractCaptcha class
 */
class __tegra_export AbstractCaptcha
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractCaptcha)


    /*!
     * \brief Get the HTML code of the captcha.
     * \returns as string output.
     */
    __tegra_constexpr_virtual OptionalString getCode() __tegra_const = __tegra_zero;

    /*!
     * \brief Checking if the user passed the captcha or not.
     * \returns as boolean.
     */
    __tegra_constexpr_virtual OptionalBool checkCode() __tegra_const = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractCaptcha)
};

TEGRA_NAMESPACE_END

#endif  // CAPTCHA_ABSTRACT_HPP
