/*!
 * @file        language.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Language engine structure.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_LANGUAGE_HPP
#define TEGRA_LANGUAGE_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

//! Tegra's Url.
#ifdef __has_include
# if __has_include(<url>)
#   include <url>
#else
#   error "Tegra's url was not found!"
# endif
#endif

TEGRA_USING SheetList  = std::vector<std::string>;
TEGRA_USING CodeType   = std::vector<std::string>;

TEGRA_NAMESPACE_BEGIN(Tegra::Multilangual)

/*!
 * \brief The LanguageStruct class
 */
struct LanguageStruct final
{
    LanguageType   get               {}; ///< LanguageType
    CodeType       languageSupport   {}; ///< Language support.
    Url            url               {}; ///< Url{en-us, fa-ir}.
};

/*! Declaration of language support */
class Language {
public:
    Language();
    Language(const std::string& uri);
    ~Language();

    /*!
     * \brief set function will sets all data from translator adaptor inside the system.
     * \param data as a map [list].
     */
    void registerAll(const LanguageType& data);

    /*!
     * \brief registerLanguage
     * \param code
     */
    void registerLanguage(const CodeType& code);

    /*!
     * \brief languageSupport
     * \returns
     */
    CodeType languageSupport() __tegra_const_noexcept;

    /*!
     * \brief registerSections
     * \param sheet
     */
    void registerSheet(const SheetList& sheet);

    /*!
     * \brief sheets
     * \returns
     */
    CodeType sheets() __tegra_const_noexcept;

    /*!
     * \brief getLanguageCode
     * \returns
     */
    std::string getLanguageCode() __tegra_const_noexcept;

    /*!
     * \brief getLanguage
     * \returns
     */
    std::string getLanguage() __tegra_const_noexcept;

    /*!
     * \brief get function will returns all data.
     * \returns as map.
     */
    __tegra_no_discard LanguageType get() __tegra_const_noexcept;

private:
    LanguageStruct* m_languageStruct{};
    SheetList m_sheets;
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_LANGUAGE_HPP
