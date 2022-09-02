//! Tegra's Account UserMedia
#ifdef __has_include
# if __has_include("account/usermedia.hpp")
#   include "account/usermedia.hpp"
#else
#   error "Tegra's usermedia was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts;

TEGRA_NAMESPACE_BEGIN(Tegra::Account)

/*!
 * \brief Constructs an avatar.
 */
Avatar::Avatar()
{
}

/*!
 * \brief Destroys the user avatar.
 */
Avatar::~Avatar()
{
}

OptionalString Avatar::get(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

bool Avatar::add(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Avatar::update(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Avatar::remove(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

AvatarViewStatus Avatar::viewStatus(const AvatarViewStatus viewStatus) __tegra_const_noexcept
{

}

/*!
 * \brief Constructs an image.
 */
Image::Image()
{
}

/*!
 * \brief Destroys the user image.
 */
Image::~Image()
{
}

OptionalString Image::get(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

bool Image::add(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Image::update(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Image::remove(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

ImageViewStatus Image::viewStatus(const ImageViewStatus viewStatus) __tegra_const_noexcept
{

}

/*!
 * \brief Constructs an cover.
 */
Cover::Cover()
{
}

/*!
 * \brief Destroys the user cover.
 */
Cover::~Cover()
{
}

OptionalString Cover::get(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

bool Cover::add(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Cover::update(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Cover::remove(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

CoverViewStatus Cover::viewStatus(const CoverViewStatus viewStatus) __tegra_const_noexcept
{

}

/*!
 * \brief Constructs an story.
 */
Story::Story()
{
}

/*!
 * \brief Destroys the user story.
 */
Story::~Story()
{
}

OptionalString Story::get(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

bool Story::add(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Story::update(const OptionalNumeric memberId, const std::string &url) __tegra_const_noexcept
{

}

bool Story::remove(const OptionalNumeric memberId) __tegra_const_noexcept
{

}

StoryViewStatus Story::viewStatus(const StoryViewStatus viewStatus) __tegra_const_noexcept
{

}

TEGRA_NAMESPACE_END



