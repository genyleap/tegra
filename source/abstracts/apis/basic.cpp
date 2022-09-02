//! Tegra's Abstract Basic.
#ifdef __has_include
# if __has_include(<abstracts/apis/basic>)
#   include <abstracts/apis/basic>
#else
#   error "Tegra's basic was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Apis)

/*!
 * \brief Constructs an abstract basic api.
 */
AbstractBasicApi::AbstractBasicApi()
{
}

/*!
 * \brief Destroys the basic api.
 */
AbstractBasicApi::~AbstractBasicApi()
{
}

TEGRA_NAMESPACE_END
