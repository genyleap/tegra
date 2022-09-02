//! Tegra's Abstract Dynamics.
#ifdef __has_include
# if __has_include("abstracts/dynamics/moduleinterface.hpp")
#   include "abstracts/dynamics/moduleinterface.hpp"
#else
#   error "Tegra's moduleinterface was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract module interface.
 */
AbstractModuleInterface::AbstractModuleInterface()
{
    __tegra_safe_instance(m_moduleInterfaceData, ModuleInterfaceData);
}

/*!
 * \brief Destroys the module interface.
 */
AbstractModuleInterface::~AbstractModuleInterface()
{
    __tegra_safe_delete(m_moduleInterfaceData);
}

TEGRA_NAMESPACE_END
