//! Tegra's Minify.
#ifdef __has_include
# if __has_include("minify.hpp")
#   include "minify.hpp"
#else
#   error "Tegra's minify was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

Minify::Minify()
{
    m_minifyStruct = new MinifyStruct();
}

Minify::~Minify()
{
    __tegra_safe_delete(m_minifyStruct);
}

TEGRA_NAMESPACE_END
