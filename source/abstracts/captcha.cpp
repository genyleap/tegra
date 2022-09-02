//! Tegra's Abstract Captcha.
#ifdef __has_include
# if __has_include("abstracts/captcha.hpp")
#   include "abstracts/captcha.hpp"
#else
#   error "Tegra's captcha was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract captcha.
 */
AbstractCaptcha::AbstractCaptcha()
{
}

/*!
 * \brief Destroys the captcha.
 */
AbstractCaptcha::~AbstractCaptcha()
{
}

TEGRA_NAMESPACE_END
