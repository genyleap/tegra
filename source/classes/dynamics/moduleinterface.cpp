//! Tegra's Moduleinterface.
#ifdef __has_include
# if __has_include("moduleinterface.hpp")
#   include "moduleinterface.hpp"
#else
#   error "Tegra's moduleinterface was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Abstracts;

class ModuleInterfaceImpl
{
public:
  NameList m_nameList;
  ModuleList m_moduleList;
  ErrorString m_errors;
};

ModuleInterface::ModuleInterface()
{
  m_pImpl = new ModuleInterfaceImpl();
  return;
}

ModuleInterface::~ModuleInterface()
{
  m_pImpl->m_nameList.clear();
  delete m_pImpl;
}

ModuleInterface& ModuleInterface::instance()
{
  static ModuleInterface inst;
  return inst;
}

void ModuleInterface::addDetail(const ModuleList& plist) __tegra_const_noexcept
{
  m_pImpl->m_moduleList = plist;
}

void ModuleInterface::addName(const std::string& name) __tegra_const_noexcept
{
  m_pImpl->m_nameList.push_back(name);
}

void ModuleInterface::setError(const std::string &var) __tegra_const_noexcept
{
  m_pImpl->m_errors.push_back(var);
}

__tegra_no_discard NameList& ModuleInterface::getNames() __tegra_const_noexcept
{
  return m_pImpl->m_nameList;
}

__tegra_no_discard ModuleList& ModuleInterface::getDetail() __tegra_const_noexcept
{
  return m_pImpl->m_moduleList;
}

__tegra_no_discard ErrorString& ModuleInterface::getErrors() __tegra_const_noexcept
{
  return m_pImpl->m_errors;
}
