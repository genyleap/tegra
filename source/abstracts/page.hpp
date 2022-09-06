/*!
 * @file        page.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Page interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_PAGE_ABSTRACT_HPP
#define TEGRA_PAGE_ABSTRACT_HPP

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
# if __has_include(<classes/page/pagestructure.hpp>)
#   include <classes/page/pagestructure.hpp>
#else
#   error "Tegra's tags was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The AbstractPage class
 */
class __tegra_export AbstractPage
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPage)

    /*!
     * \brief id will gets index number of page.
     * \returns as numeric.
     */
    __tegra_no_discard_virtual OptionalNumeric id() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief parentId will gets parent index number of page.
     * \returns as numeric.
     */
    __tegra_no_discard_virtual OptionalNumeric parentId() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief priority will gets position number of page.
     * \returns as numeric.
     */
    __tegra_no_discard_virtual OptionalNumeric priority() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief title will gets title of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString title() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief url will gets url of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString url() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief tags will gets inserted tags for page.
     * \returns as Tags class.
     */
    __tegra_no_discard_virtual Tags tags() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief text will gets content of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString text() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief documentTitle will gets document title of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString documentTitle() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief metaDescr will gets meta description of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString metaDescr() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief icon will gets icon of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString icon() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief cover will gets image of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString cover() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief publishTime will gets publish time of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString publishTime() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief pinnedTime will gets pinned time of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString pinnedTime() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief lastModified will gets last modified date and time of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString lastModified() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief inclueInSitemap will gets included status in map.
     * \returns as boolean.
     */
    __tegra_no_discard_virtual OptionalBool inclueInSitemap() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief canBeModeratedFromFrontend will gets moderated to frontend.
     * \returns as boolean.
     */
    __tegra_no_discard_virtual OptionalBool canBeModeratedFromFrontend() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief accessByApi will generates output as api strcuture.
     * \returns as boolean.
     */
    __tegra_no_discard_virtual OptionalBool accessByApi() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief create function will add a new page.
     * \param properties are the page information.
     * \returns true, if the page is created successfully.
     */
    __tegra_no_discard_virtual OptionalBool create(const PageProperties& properties) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief remove function will delete a page by own id.
     * \param id is unique index of page.
     * \returns true, if the page is removed successfully.
     */
    __tegra_no_discard_virtual OptionalBool remove(const u32 id) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief update function will edit a page by own id.
     * \param id is unique index of page.
     * \param properties are the page's data.
     * \returns true, if the page is updated successfully.
     */
    __tegra_no_discard_virtual OptionalBool update(const u32 id, const PageProperties& properties) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief move function will move a page to sub page.
     * \param id is unique index of page.
     * \param toParentId is parent page id.
     * \returns true, if the page is moved successfully.
     */
    __tegra_no_discard_virtual OptionalBool move(const u32 id, const u32 toParentId) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief lock function will lock and set a page as uneditable from users.
     * \param id is unique index of page.
     * \returns true, if the page is locked successfully.
     */
    __tegra_no_discard_virtual OptionalBool lock(const u32 id) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief hide function will hide a page from users.
     * \param id is unique index of page.
     * \returns true, if the page is hidden successfully.
     */
    __tegra_no_discard_virtual OptionalBool hide(const u32 id) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief status function will change the page status.
     * \param status is a parameter based on PageStatus.
     * \returns true, if the page status changed successfully.
     */
    __tegra_no_discard_virtual OptionalBool status(const PageStatus status) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief theme function will gets theme for page.
     * \param theme parameter as PageThemeStyle.
     * \returns output of theme.
     */
    __tegra_no_discard_virtual OptionalString theme(const PageThemeStyle theme) __tegra_const_noexcept = __tegra_zero;
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_PAGE_ABSTRACT_HPP
