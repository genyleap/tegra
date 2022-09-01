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

#include "common.hpp"
#include "core.hpp"
#include "logger.hpp"
#include "console.hpp"
#include "terminal.hpp"
#include "version.hpp"
#include "prestructure.hpp"
#include "translator/language.hpp"
#include "translator/translator.hpp"
#include "abstracts/dynamics/moduleschema.hpp"
#include "abstracts/dynamics/pluginschema.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The ApplicationData class
 */
struct ApplicationData final
{
    ///Types
    OptionalString  path             {__tegra_unknown};
    OptionalString  templateId       {__tegra_unknown};
    OptionalString  templateErrorId  {__tegra_unknown};
    OptionalString  module           {__tegra_unknown};

    ///Classes & Structures
    SystemInfo systemInfo                       {};
    SemanticVersion semanticVersion             {};
    Version::ReleaseType releaseType            {};
    Multilangual::LanguageStruct languageStruct {};
};

TEGRA_NAMESPACE_END

#endif // TEGRA_APPLICATION_DATA_HPP
