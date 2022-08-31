/*!
 * @file        usermedia.hpp
 * @brief       This file is part of the Tegra System.
 * @details     User media interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef USER_MEDIA_HPP
#define USER_MEDIA_HPP

#include "common.hpp"
#include "abstracts/account/usermedia.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Account;

TEGRA_NAMESPACE_BEGIN(Tegra::Account)

/*!
 * \brief The Avatar class
 */
class __tegra_export Avatar : public AbstractAvatar
{
public:
    TEGRA_DEFAULT_OCTORS(Avatar)

    /*!
     * \brief function get will gets profile picture address by own memberId.
     * \param memberId is unique id for user.
     * \returns as string.
     */
    __tegra_no_discard OptionalString get(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief function add will inserts avatar image by memberId and image address or link.
     * \param memberId is unique id for user.
     * \param url is a link for image.
     * \returns as boolean.
     */
    __tegra_no_discard bool add(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief get function will changes and updates profile picture by memberId and a new image address or link.
     * \param memberId is unique id for user.
     * \param url is a link for image.
     * \returns as boolean.
     */
    __tegra_no_discard bool update(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief remove function will removes profile picture by memberId.
     * \param memberId is unique id for user.
     * \returns as boolean.
     */
    __tegra_no_discard bool remove(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief viewStatus function will checks the status of view for user's avatar.
     * \param viewStatus as AvatarViewStatus enum.
     * \returns as one of AvatarViewStatus's items.
     */
    __tegra_no_discard AvatarViewStatus viewStatus(const AvatarViewStatus viewStatus) __tegra_const_noexcept_override;


private:
    AvatarViewStatus m_avatarViewStatus;
};

/*!
 * \brief The Image class
 */
class __tegra_export Image : public AbstractImage
{
public:
    TEGRA_DEFAULT_OCTORS(Image)

    /*!
     * \brief get function will gets profile image address by own memberId.
     * \param memberId is unique id for user.
     * \returns as string.
     */
    __tegra_no_discard OptionalString get(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief get function will inserts profile picture by memberId and image address or link.
     * \param memberId is unique id for user.
     * \param url is a link for image.
     * \returns as boolean.
     */
    __tegra_no_discard bool add(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief get function will changes and updates profile image by memberId and a new image address or link.
     * \param memberId is unique id for user.
     * \param url is a link for image.
     * \returns as boolean.
     */
    __tegra_no_discard bool update(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief remove function will removes profile image by memberId.
     * \param memberId is unique id for user.
     * \returns as boolean.
     */
    __tegra_no_discard bool remove(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief viewStatus function will checks the status of view for user's image.
     * \param viewStatus as ImageViewStatus enum.
     * \returns as one of ImageViewStatus's items.
     */
    __tegra_no_discard ImageViewStatus viewStatus(const ImageViewStatus viewStatus) __tegra_const_noexcept_override;


private:
    ImageViewStatus m_imageViewStatus;
};

/*!
 * \brief The Cover class
 */
class __tegra_export Cover : public AbstractCover
{
public:
    TEGRA_DEFAULT_OCTORS(Cover)

    /*!
     * \brief get function will gets profile cover address by own memberId.
     * \param memberId is unique id for user.
     * \returns as string.
     */
    __tegra_no_discard OptionalString get(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief get function will inserts profile cover by memberId and cover address or link.
     * \param memberId is unique id for user.
     * \param url is a link for cover.
     * \returns as boolean.
     */
    __tegra_no_discard bool add(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief get function will changes and updates profile cover by memberId and a new cover address or link.
     * \param memberId is unique id for user.
     * \param url is a link for cover.
     * \returns as boolean.
     */
    __tegra_no_discard bool update(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief remove function will removes profile cover by memberId.
     * \param memberId is unique id for user.
     * \returns as boolean.
     */
    __tegra_no_discard bool remove(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief viewStatus function will checks the status of view for user's cover.
     * \param viewStatus as ImageViewStatus enum.
     * \returns as one of ImageViewStatus's items.
     */
    __tegra_no_discard CoverViewStatus viewStatus(const CoverViewStatus viewStatus) __tegra_const_noexcept_override;


private:
    CoverViewStatus m_coverViewStatus;
};

/*!
 * \brief The Story class
 */
class __tegra_export Story : public AbstractStory
{
public:
    TEGRA_DEFAULT_OCTORS(Story)

    /*!
     * \brief get function will gets profile story address by own memberId.
     * \param memberId is unique id for user.
     * \returns as string.
     */
    __tegra_no_discard OptionalString get(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief get function will inserts profile story by memberId and story address or link.
     * \param memberId is unique id for user.
     * \param url is a link for cover.
     * \returns as boolean.
     */
    __tegra_no_discard bool add(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief get function will changes and updates profile story by memberId and a new story address or link.
     * \param memberId is unique id for user.
     * \param url is a link for story.
     * \returns as boolean.
     */
    __tegra_no_discard bool update(const OptionalNumeric memberId, const std::string& url) __tegra_const_noexcept_override;

    /*!
     * \brief remove function will removes profile story by memberId.
     * \param memberId is unique id for user.
     * \returns as boolean.
     */
    __tegra_no_discard bool remove(const OptionalNumeric memberId) __tegra_const_noexcept_override;

    /*!
     * \brief viewStatus function will checks the status of view for user's story.
     * \param viewStatus as StoryViewStatus enum.
     * \returns as one of StoryViewStatus's items.
     */
    __tegra_no_discard StoryViewStatus viewStatus(const StoryViewStatus viewStatus) __tegra_const_noexcept_override;


private:
    StoryViewStatus m_storyViewStatus;
};

TEGRA_NAMESPACE_END

#endif // USER_MEDIA_HPP
