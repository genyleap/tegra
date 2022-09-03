//! Tegra's Abstract Dynamics.
#ifdef __has_include
# if __has_include("abstracts/dynamics/plugin.hpp")
#   include "abstracts/dynamics/plugin.hpp"
#else
#   error "Tegra's plugin was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts::Plugin;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract plugin.
 */
AbstractPlugin::AbstractPlugin()
{
    __tegra_safe_instance(m_pluginInfo, PluginInfo);
}

/*!
 * \brief Destroys the plugin.
 */
AbstractPlugin::~AbstractPlugin()
{
    __tegra_safe_delete(m_pluginInfo);
}


TEGRA_NAMESPACE_END
