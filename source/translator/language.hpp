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

#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#include "common.hpp"
#include "core/url.hpp"

TEGRA_NAMESPACE_BEGIN(Tegra::Multilangual)

/*!
 * \brief The LanguageStruct class
 */
struct LanguageStruct final
{
    Types::LanguageType   get               {}; ///< LanguageType
    Types::LanguageCodes  languageSupport   {}; ///< Language support.
    Url                   url               {}; ///< Url{en-us, fa-ir}.
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
    void registerAll(const Types::LanguageType& data);

    /*!
     * \brief registerLanguage
     * \param code
     */
    void registerLanguage(const Types::LanguageCodes& code);

    /*!
     * \brief languageSupport
     * \returns
     */
    Types::LanguageCodes languageSupport() __tegra_const_noexcept;

    /*!
     * \brief sections
     * \returns
     */
    Types::VectorSection sections() __tegra_const_noexcept;

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
    __tegra_no_discard Types::LanguageType get() __tegra_const_noexcept;

private:
    LanguageStruct* m_languageStruct{};
};

TEGRA_NAMESPACE_END

#endif  // LANGUAGE_HPP
