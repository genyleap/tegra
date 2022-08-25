#include "moduelinterface.hpp"

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
