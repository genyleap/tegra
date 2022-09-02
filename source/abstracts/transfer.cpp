//! Tegra's Abstract Transfer.
#ifdef __has_include
# if __has_include("abstracts/transfer.hpp")
#   include "abstracts/transfer.hpp"
#else
#   error "Tegra's transfer was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract transfer method.
 */
AbstractTransferMethod::AbstractTransferMethod()
{
}

/*!
 * \brief Destroys the transfer method.
 */
AbstractTransferMethod::~AbstractTransferMethod()
{
}

TEGRA_NAMESPACE_END
