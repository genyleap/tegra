#include "modulemanager.hpp"

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
