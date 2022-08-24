/*!
 * @file        dictionary.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Dictionary for translation unit.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_DICTIONARY_HPP
#define TEGRA_DICTIONARY_HPP

#include "common.hpp"

//! STL
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Translation)

using DicType       = MultiMap<std::string, Map<std::string, std::string>>;
using Alphabet      = VectorString;
using DicTypePair   = PairString;
using DictonaryType = MultiMap<std::string, DicTypePair>;

/*!
 * \brief The LanguageType enum
 */
enum class LanguageType : u8
{
    AUTO            =  0x0, //In this case, the system checks the language status automatically.
    SINGLE          =  0x1, //In this casem the system will sets all system interface based on single activated language.
    MULTILANGUAGE   =  0x2  //In this casem the system will sets all system interface based on multi-language for only activated language.
};

/*!
 * \brief The LanguageTemplate class
 */
class LanguageTemplate {
public:
    LanguageTemplate();
    LanguageTemplate(const std::string& word_key,
                     const std::string& module,
                     const std::string& default_value,
                     const std::string& custom_value);

    ~LanguageTemplate();

    /*!
     * \brief wordKey function will gets key as string.
     * \returns string.
     */
    __tegra_no_discard std::string wordKey () __tegra_const_noexcept;

    /*!
     * \brief module function will gets module name as string.
     * \returns string.
     */
    __tegra_no_discard std::string module () __tegra_const_noexcept;

    /*!
     * \brief defaultValue function will gets default value if there is no any value in custom value.
     * \returns string.
     */
    __tegra_no_discard std::string defaultValue () __tegra_const_noexcept;

    /*!
     * \brief customValue function will gets custom value.
     * \returns string.
     */
    __tegra_no_discard std::string customValue () __tegra_const_noexcept;

private:
    std::string m_wordKey;
    std::string m_module;
    std::string m_defaultValue;
    std::string m_customValue;
};

TEGRA_NAMESPACE_END

#endif // TEGRA_DICTIONARY_HPP
