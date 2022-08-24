/*!
 * @file        base.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Base class interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef BASE_ABSTRACT_HPP
#define BASE_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The AbstractBaseClass class
 */
class __tegra_export AbstractBaseClass
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractBaseClass)


private:
    TEGRA_DISABLE_COPY(AbstractBaseClass)
};

TEGRA_NAMESPACE_END

#endif  // BASE_ABSTRACT_HPP
