/*!
 * @file        template.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Template interface for website theme.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_TEMPLATES_HPP
#define TEGRA_TEMPLATES_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

//! Tegra's Abstraction (Interfaces).
#ifdef __has_include
# if __has_include(<interface>)
#   include <interface>
#else
#   error "The abstractions of Tegra was not found!"
# endif
#endif

//! Tegra's Seo.
#ifdef __has_include
# if __has_include(<seo>)
#   include <seo>
#else
#   error "The seo of Tegra was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::System)

#define SYSTEM_THIRD_PARTY_JAVASCRIPT  "thirdPartyJs"
#define SYSTEM_THIRD_PARTY_CSS         "thirdPartyCss"
#define SYSTEM_SYSTEM_SHEET            "systemStyle"
#define SYSTEM_LINK_SHEET              "linkSheet"
#define SYSTEM_META_SHEET              "meta"

using StaticMap = std::map<std::string, std::string>;

enum class UserType : u8
{
    Guest,
    User,
    Admin,
    Moder,
    Extra
};

enum class TemplateFileType : u8
{
    HTML,
    XHTML,
    CSS,
    JavaScript
};

enum class UIFramework : u8
{
    Self,
    ThirdParty
};

enum class CDN : u8
{
    Internal,
    External
};

/*!
 * @brief The Template class
 */
class Template
{
public:

    /*!
     * \brief Template class represents the template style and content decoration mode.
     * \param usertype is for template model such as Admin, User and etc.
     * \param p is path as string that is taken from the input.
     */
    Template() = delete;
    Template(const UserType& usertype, const ApplicationData& appData);
    ~Template();
    /*!
     * \brief The Requirments struct
     */
    struct Requirments
    {
        MapConfig config;
        SEO::StaticMeta staticMeta;
    };

    /** Template source folder */
    const static inline std::string Source    = "templates";

    /** Static assets folder folder */
    const static inline std::string Assets    = "assets";

    /** User template folder */
    const static inline std::string User      = "User";

    /** Admin template folder */
    const static inline std::string Admin     = "Admin";

    /** Extra panel template folder */
    const static inline std::string Moder     = "Moderator";

    /** Type of files to be processed */
    inline const static std::string fileType  = {".html"};
    inline const static std::string cssRoot   = {".css"};
    inline const static std::string cspRoot   = {".csp"};
    inline const static std::string jsRoot    = {".js"};
    inline const static std::string fontRoot  = {".font"};

    std::string theme() const;

    std::string font() const;

    std::string css() const;

    std::string script() const;

    std::string gg() const;

    std::vector<std::string> styleSheet;

    std::vector<std::string> javaScript;

    std::vector<std::string> linkSheet;

    std::vector<std::string> systemSheet;

    bool fileExist(const std::string& file);

    SEO::StaticMeta* staticMeta;

    Scope<Multilangual::Language> languagePtr{};

    Framework::HttpViewData viewData;

private:
    UserType utype;
};

class LoadListTemplate;
/*!
 * @brief The LoadListTemplate class
 * @details this class provides template meta tag and links inside of HTML
 * document.
 */
class LoadListTemplate
{
public:

    struct BasicStruct final
    {
        std::string title{};
        std::string description{};
        std::string seprator{};
        std::string fullSiteTitle{};
    };

    LoadListTemplate(const std::string &l, const std::string &p);
    ~LoadListTemplate();

    /*!
     * \brief return title of HTML document.
     */
    std::optional<std::string> title() const;

    /*!
     * \brief return description of HTML document.
     */
    std::optional<std::string> description() const;

    /*!
     * \brief return seprator character between title and description.
     */
    std::optional<std::string> siteSeprator() const;

    /*!
     * \brief return full website title.
     */
    std::optional<std::string> fullSiteTitle() const;

protected:
    /*!
     * \brief Sets a title for HTML document.
     * \return string.
     */
    __tegra_maybe_unused void setTitle(const std::string& val);

    /*!
     * \brief Sets a description for HTML document.
     * \return string.
     */
    __tegra_maybe_unused void setDescription(const std::string& val);


    /*!
     * \brief Sets a seprator character between title and descriptio for HTML document.
     * \return string.
     */
    __tegra_maybe_unused void setSiteSeprator(const std::string& val);

    /*!
     * \brief Sets full string of title and description.
     * \return string.
     */
    __tegra_maybe_unused void setFullSiteTitle(const std::string& val);

public:
    static inline std::map<std::string, std::string> metaData;

private:
    std::string   m_title{};
    std::string   m_description{};
    std::string   m_siteSeprator{};
    std::string   m_fullSiteTitle{};
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_TEMPLATES_HPP
