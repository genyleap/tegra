//! Tegra's Abstract Dynamics.
#ifdef __has_include
# if __has_include("abstracts/dynamics/module.hpp")
#   include "abstracts/dynamics/module.hpp"
#else
#   error "Tegra's module was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract module.
 */
AbstractModule::AbstractModule()
{
    __tegra_safe_instance(m_moduleInfo, ModuleInfo);
}

/*!
 * \brief Destroys the module.
 */
AbstractModule::~AbstractModule()
{
    __tegra_safe_delete(m_moduleInfo);
}


TEGRA_NAMESPACE_END
