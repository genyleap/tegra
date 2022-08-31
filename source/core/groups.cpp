#include "groups.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs an abstract groups class.
 */
Groups::Groups()
{
    __tegra_safe_instance(m_groupData, GroupData);
}

/*!
 * \brief Destroys the groups class.
 */
Groups::~Groups()
{
    __tegra_safe_delete(m_groupData);
}


bool Groups::add(const GroupData& groupData) __tegra_const_noexcept
{
  ///ToDo...
}

bool Groups::edit(const u32 id, const GroupData& groupData) __tegra_const_noexcept
{
  ///ToDo...
}

bool Groups::remove(const u32 id) __tegra_const_noexcept
{
  ///ToDo...
}

GroupData Groups::get(const u32 id) __tegra_const_noexcept
{
    //m_groupData->....;
    ///ToDo...
    return *m_groupData;
}

TEGRA_NAMESPACE_END
