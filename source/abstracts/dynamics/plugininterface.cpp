//! Tegra's Abstract Dynamics.
#ifdef __has_include
# if __has_include("abstracts/dynamics/plugininterface.hpp")
#   include "abstracts/dynamics/plugininterface.hpp"
#else
#   error "Tegra's plugininterface was not found!"
# endif
#endif

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
