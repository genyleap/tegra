//! Tegra's Abstract Bearertoken.
#ifdef __has_include
# if __has_include(<abstracts/apis/bearertoken>)
#   include <abstracts/apis/bearertoken>
#else
#   error "Tegra's bearertoken was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Apis)

/*!
 * \brief Constructs an abstract bearer token.
 */
AbstractBearerToken::AbstractBearerToken()
{
}

/*!
 * \brief Destroys the bearer token.
 */
AbstractBearerToken::~AbstractBearerToken()
{
}

TEGRA_NAMESPACE_END
