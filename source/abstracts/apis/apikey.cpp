//! Tegra's Abstract Apikey.
#ifdef __has_include
# if __has_include(<abstracts/apis/apikey>)
#   include <abstracts/apis/apikey>
#else
#   error "Tegra's apikey was not found!"
# endif
#endif


TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Apis)

/*!
 * \brief Constructs an abstract api key.
 */
AbstractApiKey::AbstractApiKey()
{
}

/*!
 * \brief Destroys the api key.
 */
AbstractApiKey::~AbstractApiKey()
{
}

TEGRA_NAMESPACE_END
