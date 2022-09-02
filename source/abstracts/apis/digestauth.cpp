//! Tegra's Abstract Digestauth.
#ifdef __has_include
# if __has_include(<abstracts/apis/digestauth>)
#   include <abstracts/apis/digestauth>
#else
#   error "Tegra's digestauth was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Apis)

/*!
 * \brief Constructs an abstract digest auth.
 */
AbstractDigestAuth::AbstractDigestAuth()
{
}

/*!
 * \brief Destroys the digets auth.
 */
AbstractDigestAuth::~AbstractDigestAuth()
{
}

TEGRA_NAMESPACE_END
