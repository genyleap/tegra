//! Tegra's Usermedia.
#ifdef __has_include
# if __has_include(<abstracts/usermedia>)
#   include <abstracts/usermedia>
#else
#   error "Tegra's usermedia was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Account)

/*!
 * \brief Constructs an abstract avatar.
 */
AbstractAvatar::AbstractAvatar()
{
}

/*!
 * \brief Destroys the abstract avatar.
 */
AbstractAvatar::~AbstractAvatar()
{
}

/*!
 * \brief Constructs an abstract image.
 */
AbstractImage::AbstractImage()
{
}

/*!
 * \brief Destroys the abstract image.
 */
AbstractImage::~AbstractImage()
{
}

/*!
 * \brief Constructs an abstract cover.
 */
AbstractCover::AbstractCover()
{
}

/*!
 * \brief Destroys the abstract cover.
 */
AbstractCover::~AbstractCover()
{
}

/*!
 * \brief Constructs an abstract story.
 */
AbstractStory::AbstractStory()
{
}

/*!
 * \brief Destroys the abstract story.
 */
AbstractStory::~AbstractStory()
{
}

TEGRA_NAMESPACE_END
