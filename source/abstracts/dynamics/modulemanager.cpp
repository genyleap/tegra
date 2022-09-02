//! Tegra's Abstract Dynamics.
#ifdef __has_include
# if __has_include("abstracts/dynamics/modulemanager.hpp")
#   include "abstracts/dynamics/modulemanager.hpp"
#else
#   error "Tegra's modulemanager was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract module manager.
 */
AbstractModuleManager::AbstractModuleManager()
{
    __tegra_safe_instance(m_moduleManagerData, ModuleManagerData);
}

/*!
 * \brief Destroys the module manager.
 */
AbstractModuleManager::~AbstractModuleManager()
{
    __tegra_safe_delete(m_moduleManagerData);
}

TEGRA_NAMESPACE_END
