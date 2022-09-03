//! Tegra's Plugininterface.
#ifdef __has_include
# if __has_include("plugininterface.hpp")
#   include "plugininterface.hpp"
#else
#   error "Tegra's plugininterface was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts;

class PluginInterfaceImpl
{
public:
  NameList m_nameList;
  PluginList m_pluginList;
  ErrorString m_errors;
};

PluginInterface::PluginInterface()
{
  m_pImpl = new PluginInterfaceImpl();
  return;
}

PluginInterface::~PluginInterface()
{
  m_pImpl->m_nameList.clear();
  delete m_pImpl;
}

PluginInterface& PluginInterface::instance()
{
  static PluginInterface inst;
  return inst;
}

void PluginInterface::addDetail(const PluginList& plist) __tegra_const_noexcept
{
  m_pImpl->m_pluginList = plist;
}

void PluginInterface::addName(const std::string& name) __tegra_const_noexcept
{
  m_pImpl->m_nameList.push_back(name);
}

void PluginInterface::setError(const std::string &var) __tegra_const_noexcept
{
  m_pImpl->m_errors.push_back(var);
}

__tegra_no_discard NameList& PluginInterface::getNames() __tegra_const_noexcept
{
  return m_pImpl->m_nameList;
}

__tegra_no_discard PluginList& PluginInterface::getDetail() __tegra_const_noexcept
{
  return m_pImpl->m_pluginList;
}

__tegra_no_discard ErrorString& PluginInterface::getErrors() __tegra_const_noexcept
{
  return m_pImpl->m_errors;
}
