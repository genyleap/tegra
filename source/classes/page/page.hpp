/*!
 * @file        page.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Page structure for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_PAGE_HPP
#define TEGRA_PAGE_HPP

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

//! Tegra's Abstraction (Interfaces).
#ifdef __has_include
# if __has_include(<interface>)
#   include <interface>
#else
#   error "The abstractions of Tegra are not found!"
# endif
#endif

//! Tegra's Page Structure.
#ifdef __has_include
# if __has_include("pagestructure.hpp")
#   include "pagestructure.hpp"
#else
#   error "Tegra's pagestructure was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

class Page;

TEGRA_USING PageList = std::vector<Page>;

/*!
 * \brief The Page class
 */
class __tegra_export Page : public Abstracts::AbstractPage
{
public:
    TEGRA_DEFAULT_OCTORS(Page)

    Page(const PageProperties& properties);

    /*!
     * \brief id will gets index number of page.
     * \returns as numeric.
     */
    __tegra_no_discard OptionalNumeric id() __tegra_const_noexcept_override;

    /*!
     * \brief parentId will gets parent index number of page.
     * \returns as numeric.
     */
    __tegra_no_discard OptionalNumeric parentId() __tegra_const_noexcept_override;

    /*!
     * \brief priority will gets position number of page.
     * \returns as numeric.
     */
    __tegra_no_discard OptionalNumeric priority() __tegra_const_noexcept_override;

    /*!
     * \brief title will gets title of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString title() __tegra_const_noexcept_override;

    /*!
     * \brief url will gets url of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString url() __tegra_const_noexcept_override;

    /*!
     * \brief tags will gets inserted tags for page.
     * \returns as Tags class.
     */
    __tegra_no_discard Tags tags() __tegra_const_noexcept_override;

    /*!
     * \brief text will gets content of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString text() __tegra_const_noexcept_override;

    /*!
     * \brief documentTitle will gets document title of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString documentTitle() __tegra_const_noexcept_override;

    /*!
     * \brief metaDescr will gets meta description of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString metaDescr() __tegra_const_noexcept_override;

    /*!
     * \brief icon will gets icon of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString icon() __tegra_const_noexcept_override;

    /*!
     * \brief cover will gets image of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString cover() __tegra_const_noexcept_override;

    /*!
     * \brief publishTime will gets publish time of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString publishTime() __tegra_const_noexcept_override;

    /*!
     * \brief pinnedTime will gets pinned time of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString pinnedTime() __tegra_const_noexcept_override;

    /*!
     * \brief lastModified will gets last modified date and time of page.
     * \returns as string.
     */
    __tegra_no_discard OptionalString lastModified() __tegra_const_noexcept_override;

    /*!
     * \brief inclueInSitemap will gets included status in map.
     * \returns as boolean.
     */
    __tegra_no_discard OptionalBool inclueInSitemap() __tegra_const_noexcept_override;

    /*!
     * \brief canBeModeratedFromFrontend will gets moderated to frontend.
     * \returns as boolean.
     */
    __tegra_no_discard OptionalBool canBeModeratedFromFrontend() __tegra_const_noexcept_override;

    /*!
     * \brief accessByApi will generates output as api strcuture.
     * \returns as boolean.
     */
    __tegra_no_discard OptionalBool accessByApi() __tegra_const_noexcept_override;

    /*!
     * \brief create function will add a new page.
     * \param properties are the page information.
     * \returns true, if the page is created successfully.
     */
    __tegra_no_discard OptionalBool create(const PageProperties& properties) __tegra_const_noexcept_override;

    /*!
     * \brief remove function will delete a page by own id.
     * \param id is unique index of page.
     * \returns true, if the page is removed successfully.
     */
    __tegra_no_discard OptionalBool remove(const u32 id) __tegra_const_noexcept_override;

    /*!
     * \brief update function will edit a page by own id.
     * \param id is unique index of page.
     * \param properties are the page's data.
     * \returns true, if the page is updated successfully.
     */
    __tegra_no_discard OptionalBool update(const u32 id, const PageProperties& properties) __tegra_const_noexcept_override;

    /*!
     * \brief move function will move a page to sub page.
     * \param id is unique index of page.
     * \param toParentId is parent page id.
     * \returns true, if the page is moved successfully.
     */
    __tegra_no_discard OptionalBool move(const u32 id, const u32 toParentId) __tegra_const_noexcept_override;

    /*!
     * \brief lock function will lock and set a page as uneditable from users.
     * \param id is unique index of page.
     * \returns true, if the page is locked successfully.
     */
    __tegra_no_discard OptionalBool lock(const u32 id) __tegra_const_noexcept_override;

    /*!
     * \brief hide function will hide a page from users.
     * \param id is unique index of page.
     * \returns true, if the page is hidden successfully.
     */
    __tegra_no_discard OptionalBool hide(const u32 id) __tegra_const_noexcept_override;

    /*!
     * \brief status function will change the page status.
     * \param status is a parameter based on PageStatus.
     * \returns true, if the page status changed successfully.
     */
    __tegra_no_discard OptionalBool status(const PageStatus status) __tegra_const_noexcept_override;

    /*!
     * \brief theme function will gets theme for page.
     * \param theme parameter as PageThemeStyle.
     * \returns output of theme.
     */
    __tegra_no_discard OptionalString theme(const PageThemeStyle theme) __tegra_const_noexcept_override;

    /*!
     * \brief list function will gets an array from pages.
     * \param creatorData parameter as PageCreatorData [id and type].
     * \returns list of pages based on filters.
     */
    __tegra_no_discard PageList list(const PageCreatorData& creatorData, const PageType pageType, const PageStatus pageStatus) __tegra_const_noexcept;

    /*!
     * \brief parent function will gets parent page.
     * \param id is unique index of page.
     * \returns parent page.
     */
    __tegra_no_discard Page parent(const u32 id) __tegra_const_noexcept;

private:
    PageProperties mPageProperties;
};

TEGRA_USING ArchivedPage = std::map<int, Page>;
TEGRA_USING ArchivedPageProvider = std::pair<int, Page>;

/*!
 * \brief The PageArchive class
 * \ Maybe useful for check history of page exploring by user.
 */
class __tegra_export PageArchive
{
public:
    PageArchive();
    ~PageArchive();

    /*!
     * \brief registerPage function will sets a page for archive.
     * \param page as Page object.
     */
    void registerPage(const Page& page);

    /*!
     * \brief list function will gets all page from archive.
     */
    __tegra_no_discard ArchivedPage list() __tegra_const_noexcept;

private:
    ArchivedPage mPage;
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_PAGE_HPP
