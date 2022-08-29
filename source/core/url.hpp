/*!
 * @file        url.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Url structure.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef URL_HPP
#define URL_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The UrlStructure class
 */
struct UrlStructure
{
    OptionalString scheme       {}; ///< The scheme tells web servers which protocol to use when it accesses a page on your website.
    OptionalString subdomain    {}; ///< A subdomain in a URL indicates which particular page of your website the web browser should serve up.
    OptionalString secondLevel  {}; ///< Your second-level domain (SLD) is the name of your website.
    OptionalString topLevel     {}; ///< The top-level domain (TLD) specifies what type of entity your organization registers as on the internet.
    OptionalString subdirectory {}; ///< A subdirectory — also known as a subfolder — helps people as well as web crawlers understand which particular section of a webpage they’re on.
};

/*!
 * \brief The LanguageUrl class
 */
struct LanguageUrl
{
    OptionalString uri {};  ///< Uri for language [https://localhost/{language-uri}=en-us, fa-ir]
};

/*!
 * \brief The Url class
 */
class __tegra_export Url
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Url)
    Url(const std::string& uri);
    /*!
     * \brief registerTag function will sets data in tag list.
     * \param urlStructure is a type of UrlStructure.
     */
    void registerUrl(const UrlStructure& urlStructure) __tegra_const_noexcept;

    /*!
     * \brief getAsStructure will gets url by seprated sections.
     * \returns url as UrlStructure.
     */
    UrlStructure getAsStructure() __tegra_const_noexcept;

    /*!
     * \brief getAsUrl function will gets url as full string.
     * \returns as string.
     */
    OptionalString getAsUrl() __tegra_const_noexcept;

    /*!
     * \brief setLanguageUri function will sets a string for language.
     * \param uri as string.
     */
    void setLanguageUri(const std::string& uri) __tegra_const_noexcept;

    /*!
     * \brief getLanguageUri function will gets language based on url.
     * \returns as string.
     */
    OptionalString getLanguageUri() __tegra_const_noexcept;

protected:
    LanguageUrl* m_languageUrl{};

private:
    TEGRA_DISABLE_COPY(Url)
    UrlStructure* m_urlStructure{};
};

TEGRA_NAMESPACE_END

#endif  // URL_HPP
