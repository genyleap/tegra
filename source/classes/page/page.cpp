//! Tegra's Page.
#ifdef __has_include
# if __has_include("page.hpp")
#   include "page.hpp"
#else
#   error "Tegra's page was not found!"
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

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Abstracts;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs page class.
 */
Page::Page()
{
}

Page::Page(const PageProperties& properties)
{
    mPageProperties = properties;
}

/*!
 * \brief Destroys the page class.
 */
Page::~Page()
{
}


OptionalNumeric Page::id() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.id, int());
}

OptionalNumeric Page::parentId() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.parentId, int());
}

OptionalNumeric Page::priority() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.priority, int());
}

OptionalString Page::title() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.title, std::string());
}

OptionalString Page::url() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.url, std::string());
}

Tags Page::tags() __tegra_const_noexcept
{
    //! ToDo...
    Tags t;
    return t;
}

OptionalString Page::text() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.text, std::string());
}

OptionalString Page::documentTitle() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.documentTitle, std::string());
}

OptionalString Page::metaDescr() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.metaDescr, std::string());
}

OptionalString Page::icon() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.icon, std::string());
}

OptionalString Page::cover() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.cover, std::string());
}

OptionalString Page::publishTime() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.publishTime, std::string());
}

OptionalString Page::pinnedTime() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.pinnedTime, std::string());
}

OptionalString Page::lastModified() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.lastModified, std::string());
}

OptionalBool Page::inclueInSitemap() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.inclueInSitemap, bool());
}

OptionalBool Page::canBeModeratedFromFrontend() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.canBeModeratedFromFrontend, bool());
}

OptionalBool Page::accessByApi() __tegra_const_noexcept
{
    return perfectCheck(mPageProperties.accessByApi, bool());
}

OptionalBool Page::create(const PageProperties& properties) __tegra_const_noexcept
{
  //! ToDo..
}

OptionalBool Page::remove(const u32 id) __tegra_const_noexcept
{
    //! ToDo..
}

OptionalBool Page::update(const u32 id, const PageProperties& properties) __tegra_const_noexcept
{
    //! ToDo..
}

OptionalBool Page::move(const u32 id, const u32 toParentId) __tegra_const_noexcept
{
    //! ToDo..
}

OptionalBool Page::lock(const u32 id) __tegra_const_noexcept
{
    //! ToDo..
}

OptionalBool Page::hide(const u32 id) __tegra_const_noexcept
{
    //! ToDo..
}

OptionalBool Page::status(const PageStatus status) __tegra_const_noexcept
{
    //! ToDo..
}

OptionalString Page::theme(const PageThemeStyle theme) __tegra_const_noexcept
{
    //! ToDo..
}

__tegra_no_discard PageList Page::list(const PageCreatorData& creatorData, const PageType pageType, const PageStatus pageStatus) __tegra_const_noexcept
{
    PageList tempList{};

         //! Set a query and gets data by filters.
         //! Check the feature and status and then return.
         //!
    /* Check type first. */
    switch (pageType) {
    case PageType::Default:

        break;
    case PageType::Custom:

        break;
    case PageType::Dynamic:

        break;
    case PageType::Static:

        break;
    default:
        break;
    }

    /* Check status. */
    switch (pageStatus) {
    case PageStatus::Hidden:

        break;
    case PageStatus::Important:

        break;
    case PageStatus::Open:

        break;
    case PageStatus::Pending:

        break;
    case PageStatus::Locked:

        break;
    case PageStatus::Special:

        break;
    default:
        break;
    }

    /* Check creator data. */
    switch (creatorData.creatorType) {
    case CreatorType::BySystem:

        break;
    case CreatorType::ByAdmin:

        break;
    case CreatorType::ByUser:

        break;
    case CreatorType::ByRobot:

        break;
    case CreatorType::ByApi:

        break;
    case CreatorType::Unknown:

    default:
        break;
    }

         //! Add query for getting data by creatorId.
    return tempList;
}

Page Page::parent(const u32 id) __tegra_const_noexcept
{
    //!ToDo...Test
    PageProperties properties;
    properties.id = 200;
    properties.title = "Parent 200!";
    properties.accessByApi = true;
    //!ToDo...
    Page page(properties);
    if(isset(id) && properties.id == id) {
        return page;
    } else {
        return Page();
    }
}

PageArchive::PageArchive()
{
}

PageArchive::~PageArchive()
{
}

void PageArchive::registerPage(const Page& page)
{
    mPage.insert(ArchivedPageProvider(page.id().value(), page));
}

__tegra_no_discard ArchivedPage PageArchive::list() __tegra_const_noexcept
{
    return mPage;
}

TEGRA_NAMESPACE_END
