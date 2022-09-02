//! Tegra's Console.
#ifdef __has_include
# if __has_include("console.hpp")
#   include "console.hpp"
#else
#   error "Tegra's console was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::Console)

Output::Output() {}

Output::~Output() {}

TEGRA_NAMESPACE_END
