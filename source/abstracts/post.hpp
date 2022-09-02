/*!
 * @file        post.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Post interface for pages.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_POST_ABSTRACT_HPP
#define TEGRA_POST_ABSTRACT_HPP

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
#   error "Tegra's requirements are not found!"
# endif
#endif

//! Tegra's Tags.
#ifdef __has_include
# if __has_include(<tags>)
#   include <tags>
#else
#   error "Tegra's tags are not found!"
# endif
#endif

//! Tegra's Share.
#ifdef __has_include
# if __has_include(<share>)
#   include <share>
#else
#   error "Tegra's share was not found!"
# endif
#endif

//! Tegra's Message.
#ifdef __has_include
# if __has_include(<message>)
#   include <message>
#else
#   error "Tegra's message was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The PostStatus enum
 */
__tegra_enum_class PostStatus : u8
{
    Publish,        ///< Viewable by everyone.
    Future,         ///< Scheduled to be published in a future date.
    Draft,          ///< Incomplete post viewable by anyone with proper user role.
    Pending,        ///< Awaiting a user with the publish capability.
    Private,        ///< Viewable only to Tegra users at Administrator level.
    Trash,          ///< Posts in the Trash are assigned the trash status.
    AutoDraft,      ///< Revisions that Tegra saves automatically while you are editing.
    Inherit,        ///< Used with a child post (such as Attachments and Revisions) to determine the actual status from the parent post.
    Custom          ///< As custom status.
};

/*!
 * \brief The PostShare class
 */
struct PostData final
{
    ///!BASIC
    OptionalNumeric id              {};    ///< Index of post.
    OptionalNumeric priority        {};    ///< Index of post position.
    OptionalString  title           {};    ///< Title (subject) of post.
    OptionalString  url             {};    ///< Url for post.
    Tags            tags            {};    ///< Tags list for post.
    OptionalString  text            {};    ///< Text (main content) for post.
    OptionalString  documentTitle   {};    ///< Document title (title of post).
    OptionalString  metaDescr       {};    ///< Meta description (more details) for post.
    ///!MEDIA
    System::MediaType  cover           {};    ///< Image or video for post.
    System::IconType   icon            {};    ///< Icon for post.
    ///!DATETIME
    OptionalString  createdDate     {};    ///< Created date time.
    OptionalString  publishTime     {};    ///< Publishing time.
    OptionalString  pinnedTime      {};    ///< Pinned time.
    OptionalString  lastModified    {};    ///< Last Modified date-time.
    ///!EXTRA
    OptionalBool    inclueInSitemap            {};  ///< If included in sitemap section.
    OptionalBool    canBeModeratedFromFrontend {};  ///< Can be moderated from frontend?!
    OptionalBool    accessByApi     {};  ///< Can be access from api output.
    OptionalString  theme           {};  ///< Post theme.
    OptionalString  link            {};  ///< Post link.
    PostStatus      postStatus      {};  ///< Post status.
    Share           shareAction     {};  ///< Share action.
    ShareData       shareData       {};  ///< Share data.
    Message         message         {};  ///< Messahe for post.
};

/*!
 * \brief The AbstractPost class
 */
class __tegra_export AbstractPost
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPost)

    /*!
     * \brief publish function will create and publish post by PostStatus state.
     * \param specifies data from the PostData.
     * \returns boolean.
     */
    __tegra_no_discard_virtual OptionalBool publish(const PostData& postData) __tegra_const = __tegra_zero;

    /*!
     * \brief remove function will delete a post by own id.
     * \param id is unique index of post.
     * \returns true, if the post is removed successfully.
     */
    __tegra_no_discard_virtual OptionalBool remove(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief update function will edit a post by own id.
     * \param id is unique index of post.
     * \param postData are the post's data.
     * \returns true, if the post is updated successfully.
     */
    __tegra_no_discard_virtual OptionalBool update(const u32 id, const PostData& postData) __tegra_const = __tegra_zero;

    /*!
     * \brief copy function will copy a post.
     * \param id is unique index of post.
     * \returns true, if the post is copied successfully.
     */
    __tegra_no_discard_virtual OptionalBool copy(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief move function will move a post to sub post.
     * \param id is unique index of post.
     * \param toParentId is parent post id.
     * \returns true, if the post is moved successfully.
     */
    __tegra_no_discard_virtual OptionalBool move(const u32 id, const u32 toParentId) __tegra_const = __tegra_zero;

    /*!
     * \brief lock function will lock and set a post as uneditable from users.
     * \param id is unique index of post.
     * \returns true, if the post is locked successfully.
     */
    __tegra_no_discard_virtual OptionalBool lock(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief hide function will hide a post from users.
     * \param id is unique index of post.
     * \returns true, if the post is hidden successfully.
     */
    __tegra_no_discard_virtual OptionalBool hide(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief status function will change the post status.
     * \param status is a parameter based on PostStatus.
     * \returns true, if the post status changed successfully.
     */
    __tegra_no_discard_virtual OptionalBool status(const PostStatus status) __tegra_const = __tegra_zero;

    /*!
     * \brief addMessage function will add new message for the post.
     * \param message is a parameter based on MessageData.
     * \returns true, if the post message added successfully.
     */
    __tegra_no_discard_virtual OptionalBool addMessage(const MessageData& messageData) __tegra_const = __tegra_zero;


private:
    TEGRA_DISABLE_COPY(AbstractPost)
    PostData* m_postData{};
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_POST_ABSTRACT_HPP
