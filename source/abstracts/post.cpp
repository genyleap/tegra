//! Tegra's Abstract Post.
#ifdef __has_include
# if __has_include("abstracts/post.hpp")
#   include "abstracts/post.hpp"
#else
#   error "Tegra's post was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract page class.
 */
AbstractPost::AbstractPost()
{
    __tegra_safe_instance(m_postData, PostData);
}

/*!
 * \brief Destroys the page class.
 */
AbstractPost::~AbstractPost()
{
    __tegra_safe_delete(m_postData);
}


TEGRA_NAMESPACE_END
