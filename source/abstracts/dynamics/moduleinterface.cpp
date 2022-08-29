#include "plugininterface.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract plugin interface.
 */
AbstractModuleInterface::AbstractModuleInterface()
{
    __tegra_safe_instance(m_pluginInterfaceData, ModuleInterfaceData);
}

/*!
 * \brief Destroys the plugin interface.
 */
AbstractModuleInterface::~AbstractModuleInterface()
{
    __tegra_safe_delete(m_pluginInterfaceData);
}

TEGRA_NAMESPACE_END
