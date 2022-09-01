#include "setting.hpp"
#include "logger.hpp"
#include "core/core.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra)

SettingInterface::SettingInterface(
    const OptionalString &title,
    const OptionalString &descr,
    const OptionalString &value,
    const OptionalString &json,
    const OptionalString &defaultVal,
    const OptionalString &extra)
{
    m_interfaceData = new InterfaceData();
}

SettingInterface::SettingInterface()
{
    m_interfaceData = new InterfaceData();
}

SettingInterface::~SettingInterface()
{
    __tegra_safe_delete(m_interfaceData);
}

OptionalString SettingInterface::title()
{
    if (isset(m_interfaceData->title)) {
        return m_interfaceData->title;
    } else {
        return std::nullopt;
    }
}

OptionalString SettingInterface::descr()
{
    if (isset(m_interfaceData->descr)) {
        return m_interfaceData->descr;
    } else {
        return std::nullopt;
    }
}

OptionalString SettingInterface::value()
{
    if (isset(m_interfaceData->value)) {
        return m_interfaceData->value;
    } else {
        return std::nullopt;
    }
}

OptionalString SettingInterface::json()
{
    if (isset(m_interfaceData->json)) {
        return m_interfaceData->json;
    } else {
        return std::nullopt;
    }
}

OptionalString SettingInterface::defaultVal()
{
    if (isset(m_interfaceData->defaultVal)) {
        return m_interfaceData->defaultVal;
    } else {
        return std::nullopt;
    }
}

OptionalString SettingInterface::extra()
{
    if (isset(m_interfaceData->extra)) {
        return m_interfaceData->extra;
    } else {
        return std::nullopt;
    }
}

void SettingInterface::setTitle(const std::string& val)
{
    if(m_interfaceData->title->empty()) { m_interfaceData->title = val; }
    m_interfaceData->title.value_or("empty!");
}

void SettingInterface::setDescr(const std::string& val)
{
    if(m_interfaceData->descr->empty()) { m_interfaceData->descr = val; }
    m_interfaceData->descr.value_or("empty!");
}

void SettingInterface::setValue(const std::string& val)
{
    if(m_interfaceData->value->empty()) { m_interfaceData->value = val; }
    m_interfaceData->value.value_or("empty!");
}

void SettingInterface::setJson(const std::string& val)
{
    if(m_interfaceData->json->empty()) { m_interfaceData->json = val; }
    m_interfaceData->json.value_or("empty!");
}

void SettingInterface::setDefaultVal(const std::string& val)
{
    if(m_interfaceData->defaultVal->empty()) { m_interfaceData->defaultVal = val; }
    m_interfaceData->defaultVal.value_or("empty!");
}

void SettingInterface::setExtra(const std::string &val)
{
    if(m_interfaceData->extra->empty()) { m_interfaceData->extra = val; }
    m_interfaceData->extra.value_or("empty!");
}

Setting::Setting()
{
    m_settingData = new SettingData();
}

Setting::~Setting()
{
    __tegra_safe_delete(m_settingData);
}

std::string Setting::getOption(const std::string& var)
{
    return "empty-todo"; ///ToDo...
}

SettingType Setting::getList() __tegra_const_noexcept
{
  //ToDo...
}

std::vector<std::string> Setting::option() const
{
    return m_settingData->option;
}

void Setting::setOption(const std::vector<std::string>& val)
{
    m_settingData->option = val;
}

void Setting::saveList() __tegra_const_noexcept
{
  //ToDo...
}


TEGRA_NAMESPACE_END
