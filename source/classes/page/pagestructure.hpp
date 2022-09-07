/*!
 * @file        pagestructure.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Page structure for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_PAGE_STRUCTURE_HPP
#define TEGRA_PAGE_STRUCTURE_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

//! Tegra's Core (Core Only).
#ifdef __has_include
# if __has_include(<core>)
#   include <core>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

//! Tegra's Tags.
#ifdef __has_include
# if __has_include(<tags>)
#   include <tags>
#else
#   error "Tegra's tags was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The PageType enum
 */
enum class PageType : u8
{
    Default     =   0x0,    ///< Page as default.
    Static      =   0x1,    ///< Page as static mode.
    Dynamic     =   0x2,    ///< Page as dynamic mode.
    Custom      =   0x3     ///< Page as custom design.
};

/*!
 * \brief The PageStatus enum
 */
enum class PageStatus : u8
{
    Open            =   0x0,    ///< Page is open.
    Locked          =   0x2,    ///< Page is locked by user or default.
    Important       =   0x3,    ///< Page is open and it's important.
    Special         =   0x4,    ///< Page is open and special.
    Hidden          =   0x5,    ///< Page is hidden and not open.
    Pending         =   0x6,    ///< Page is hidden and not open, it is waiting for creator action.
};

/*!
 * \brief The CreatorType enum
 */
enum class CreatorType : u8
{
    BySystem, ByUser, ByRobot, ByAdmin, ByApi, Unknown
};

/*!
 * \brief The PageCreatorData class
 */
struct PageCreatorData final
{
    OptionalNumeric     creatorId   {}; ///< Creator ID.
    CreatorType         creatorType {CreatorType::Unknown}; ///< Type of creator.
};

/*!
 * \brief The PageThemeStyle enum
 */
enum class PageThemeStyle : u8
{
    Default         =   0x0,
    AsPage          =   0x1,
    BySystemDesign  =   0x2,
    ByCustomDesign  =   0x3
};

/*!
 * \brief The PageLinks class
 */
struct PageLinks final
{
    OptionalString self     {};
    OptionalString parent   {};
    OptionalString child    {};
    OptionalString backward {};
    OptionalString forward  {};
};

/*!
 * \brief The PageProperties class
 */
struct PageProperties __tegra_final
{
    //! BASIC
    OptionalNumeric     id              {__tegra_zero};         ///< Index of page.
    OptionalNumeric     parentId        {__tegra_zero};         ///< Parent Id index.
    OptionalNumeric     priority        {__tegra_zero};         ///< Index of page position.
    OptionalString      title           {__tegra_null_str};     ///< Title (subject) of page.
    OptionalString      url             {__tegra_null_str};     ///< Url for page.
    Tags                tags            {};                     ///< Tags list for page.
    OptionalString      text            {__tegra_null_str};     ///< Text (main content) for page.
    OptionalString      documentTitle   {__tegra_null_str};     ///< Document title (title of page).
    OptionalString      metaDescr       {__tegra_null_str};     ///< Meta description (more details) for page.
    //! MEDIA
    OptionalString      cover           {__tegra_null_str};     ///< Image or video for page.
    OptionalString      icon            {__tegra_null_str};     ///< Icon for page.
    //! DATETIME
    OptionalString      createdDate     {__tegra_null_str};     ///< Created date time.
    OptionalString      publishTime     {__tegra_null_str};     ///< Publishing time.
    OptionalString      pinnedTime      {__tegra_null_str};     ///< Pinned time.
    OptionalString      lastModified    {__tegra_null_str};     ///< Last Modified date-time.
    //! EXTRA
    OptionalBool        inclueInSitemap            {false};     ///< If included in sitemap section.
    OptionalBool        canBeModeratedFromFrontend {false};     ///< Can be moderated from frontend?!
    OptionalBool        accessByApi {false};                    ///< Can be access from api output.
    OptionalString      theme       {__tegra_null_str};         ///< Page theme.
    //! CLASSES & ENUMS
    Optional<PageType>          type        {};
    Optional<PageStatus>        status      {};
    Optional<PageType>          pageType    {};
    Optional<CreatorType>       creator     {};
    Optional<PageThemeStyle>    themeStyle  {};
    Optional<PageLinks>         links       {};
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_PAGE_STRUCTURE_HPP
