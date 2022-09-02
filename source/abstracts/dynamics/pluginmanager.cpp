//! Tegra's Abstract Dynamics.
#ifdef __has_include
# if __has_include("abstracts/dynamics/pluginmanager.hpp")
#   include "abstracts/dynamics/pluginmanager.hpp"
#else
#   error "Tegra's pluginmanager was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract plugin manager.
 */
AbstractPluginManager::AbstractPluginManager()
{
    __tegra_safe_instance(m_pluginManagerData, PluginManagerData);
}

/*!
 * \brief Destroys the plugin manager.
 */
AbstractPluginManager::~AbstractPluginManager()
{
    __tegra_safe_delete(m_pluginManagerData);
}


TEGRA_NAMESPACE_END
