#include "plugininterface.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract plugin interface.
 */
AbstractPluginInterface::AbstractPluginInterface()
{
    __tegra_safe_instance(m_pluginInterfaceData, PluginInterfaceData);
}

/*!
 * \brief Destroys the plugin interface.
 */
AbstractPluginInterface::~AbstractPluginInterface()
{
    __tegra_safe_delete(m_pluginInterfaceData);
}

TEGRA_NAMESPACE_END
