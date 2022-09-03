/*!
 * @file        menu.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Menu and item interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_MENU_ABSTRACT_HPP
#define TEGRA_MENU_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The MenuDisplayGroup enum
 * \details Display items by grouping.
 */
__tegra_enum_class MenuDisplayGroup : u8
{
    Default     =   0x1,  ///< Display for all users.
    Guest       =   0x2,  ///< Display for guest only.
    User        =   0x3,  ///< Display for user only.
    Admin       =   0x4,  ///< Display for admin only.
    Master      =   0x5,  ///< Display for master only.
    Customized  =   0x6   ///< Display for customized group only.
};

__tegra_enum_class ItemStatus : u8
{
    Disabled    =   0x0,  ///< Disabled.
    Hidden      =   0x1,  ///< Hidden.
    Active      =   0x2   ///< Active.
};

/*!
 * \brief The SettingData class
 */
struct MenuItemData __tegra_final
{
    OptionalNumeric         id         {};   ///< Id of menu item.
    OptionalNumeric         parentId   {};   ///< Parent id of menu item.
    OptionalBool            isParent   {};   ///< Parent mode of menu item.
    OptionalString          title      {};   ///< Title of menu item.
    OptionalString          descr      {};   ///< Description of menu item.
    OptionalString          url        {};   ///< Url of menu item.
    OptionalString          params     {};   ///< Params of menu item.
    Optional<ItemStatus>    status     {};   ///< Status value of menu item.
    OptionalNumeric         priority   {};   ///< Group index value of menu item.
    OptionalBool            inSiteMap  {};   ///< InMap status for menu item.
};

class __tegra_export AbstractMenuItem
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractMenuItem)

    /*!
     * \brief id is unique id of menu item.
     * \returns integer.
     */
    __tegra_virtual OptionalNumeric id() __tegra_const = __tegra_zero;

    /*!
     * \brief parentId is parent's id of menu item.
     * \returns integer.
     */
    __tegra_virtual OptionalNumeric parentId() __tegra_const = __tegra_zero;

    /*!
     * \brief isParent will gets item parent situation.
     * \returns true if item has parent id.
     */
    __tegra_virtual OptionalBool isParent() __tegra_const = __tegra_zero;

    /*!
     * \brief title is subject of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString title() __tegra_const = __tegra_zero;

    /*!
     * \brief descr is description of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString descr() __tegra_const = __tegra_zero;

    /*!
     * \brief url/uri is link or uri of menu item.
     * \returns string of url.
     */
    __tegra_virtual OptionalString url() __tegra_const = __tegra_zero;

    /*!
     * \brief parameter of rel options like [rel="nofollow"].
     * \returns string.
     */
    __tegra_virtual OptionalString params() __tegra_const = __tegra_zero;

    /*!
     * \brief status will gets status value from option.
     * \returns one of the Status.
     */
    __tegra_virtual Optional<ItemStatus> status() __tegra_const = __tegra_zero;

    /*!
     * \brief priority will gets priority(position index) of menu item.
     * \returns as integer.
     */
    __tegra_virtual OptionalNumeric priority() __tegra_const = __tegra_zero;

    /*!
     * \brief inSiteMap will gets sitemap status for an item.
     * \returns as boolean.
     */
    __tegra_virtual OptionalBool inSiteMap() __tegra_const = __tegra_zero;

    /*!
     * \brief Getting menu item by id from list.
     * \returns MenuItemData of items.
     */
    __tegra_virtual MenuItemData getMenuById() __tegra_const = __tegra_zero;

    /*!
     * \brief setId inserts id for an item.
     * \param id is a number type for inserting values into the function.
     */
    __tegra_virtual void setId(const OptionalNumeric id) = __tegra_zero;

    /*!
     * \brief setParentId inserts parent's id for an item.
     * \param pid is a number type for inserting values into the function.
     */
    __tegra_virtual void setParentId(const OptionalNumeric pid) = __tegra_zero;

    /*!
     * \brief setIsParent inserts parent's situation for an item.
     * \param isp is a number type for inserting values into the function.
     */
    __tegra_virtual void setIsParent(const OptionalBool isp) = __tegra_zero;

    /*!
     * \brief SetTitle inserts data for the option's title.
     * \param title is a string type for inserting values into the function.
     */
    __tegra_virtual void setTitle(const OptionalString& title) = __tegra_zero;

    /*!
     * \brief setDescr inserts data for the option's description.
     * \param descr is a string type for inserting values into the function.
     */
    __tegra_virtual void setDescr(const OptionalString& descr) = __tegra_zero;

    /*!
     * \brief setUrl inserts link for the item's href.
     * \param url is a string type for inserting values into the function.
     */
    __tegra_virtual void setUrl(const OptionalString& url) = __tegra_zero;

    /*!
     * \brief setParams inserts data for the option's default value.
     * \param param is a string type for inserting values into the function.
     */
    __tegra_virtual void setParams(const OptionalString& param) = __tegra_zero;

    /*!
     * \brief setStatus will change option's status.
     * \param status is a Status type for change the option status.
     */
    __tegra_virtual void setStatus(const Optional<ItemStatus> status) = __tegra_zero;

    /*!
     * \brief setPriority will sets a position as integer for item.
     * \param pos is number of item's position.
     */
    __tegra_virtual void setPriority(const OptionalNumeric pos) = __tegra_zero;

    /*!
     * \brief setInSiteMap will sets item into sitemap service.
     * \param map is status of item's in sitemap.
     */
    __tegra_virtual void setInSiteMap(const OptionalBool map) = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractMenuItem)
};

class __tegra_export AbstractMenu
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractMenu)

    /*!
     * \brief insert will create a new item for menu.
     * \param menuItemData parameter is item's data as MenuItemData.
     * \returns true if the object[item] was successfully created.
     */
    __tegra_virtual OptionalBool insert(const MenuItemData& menuItemData) = __tegra_zero;

    /*!
     * \brief edit will replace current item data with new.
     * \param id parameter is item's unique id for find it.
     * \param menuItemData parameter is item's data as MenuItemData.
     * \returns true if the object[item] was successfully edited.
     */
    __tegra_virtual OptionalBool edit(const int id, const MenuItemData& menuItemData) = __tegra_zero;

    /*!
     * \brief removeItem will removes an item from menu list.
     * \param id parameter is required to specify the item uid.
     * \returns true if the object[item] was successfully removed.
     */
    __tegra_virtual OptionalBool removeItem(const int id) = __tegra_zero;

    /*!
     * \brief changePos will change or move item's position between items.
     * \param id parameter is item's unique id.
     * \param posId parameter is position number for move.
     * \returns true if the object[item] was successfully moved.
     */
    __tegra_virtual OptionalBool changePos(const int id, const int posId) = __tegra_zero;

    /*!
     * \brief items will gets all item as string;
     * \returns list of items.
     */
    __tegra_virtual std::vector<OptionalString> items() __tegra_const = __tegra_zero;

    /*!
     * \brief itemsByStatus will gets all item as string;
     * \param status parameter is required for check status of item.
     * \returns list of items based on their status.
     */
    __tegra_virtual std::vector<OptionalString> itemsByStatus(const ItemStatus& status) __tegra_const = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractMenu)
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_MENU_ABSTRACT_HPP
