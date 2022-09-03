/*!
 * @file        application.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System application.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_APPLICATION_DATA_HPP
#define TEGRA_APPLICATION_DATA_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements are not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The ApplicationData class
 */
struct ApplicationData final
{
    ///Types
    OptionalString  path                 {__tegra_unknown};
    OptionalString  templateViewId       {__tegra_unknown};
    OptionalString  templateViewErrorId  {__tegra_unknown};
    OptionalString  module               {__tegra_unknown};

    ///Classes & Structures
    SystemInfo systemInfo                       {};
    SemanticVersion semanticVersion             {};
    Version::ReleaseType releaseType            {};
    Multilangual::LanguageStruct languageStruct {};
};

TEGRA_NAMESPACE_END

#endif // TEGRA_APPLICATION_DATA_HPP
