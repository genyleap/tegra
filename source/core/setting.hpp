/*!
 * @file        setting.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System setting structure.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef SETTING_HPP
#define SETTING_HPP

#include "common.hpp"
#include "core/core.hpp"

TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The SettingData class
 */
struct InterfaceData final
{
    OptionalString title      {};
    OptionalString descr      {};
    OptionalString value      {};
    OptionalString json       {};
    OptionalString defaultVal {};
    OptionalString extra      {};
};

class SettingInterface
{
public:
    SettingInterface(const OptionalString& title,
                     const OptionalString& descr,
                     const OptionalString& value,
                     const OptionalString& json,
                     const OptionalString& defaultVal,
                     const OptionalString& extra);
    SettingInterface();
    ~SettingInterface();

    /*!
     * \brief title is subject of setting option.
     * \returns string.
     */
    OptionalString title();

    /*!
     * \brief descr is description of setting option.
     * \returns string.
     */
    OptionalString descr();

    /*!
     * \brief value is content of option value.
     * \returns string.
     */
    OptionalString value();

    /*!
     * \brief json is content based on json format.
     * \returns string.
     */
    OptionalString json();

    /*!
     * \brief defaultVal will gets default value for option.
     * \returns string.
     */
    OptionalString defaultVal();

    /*!
     * \brief extra will gets extra data from option.
     * \returns string.
     */
    OptionalString extra();

    void setTitle(const std::string& val);
    void setDescr(const std::string& val);
    void setValue(const std::string& val);
    void setJson(const std::string& val);
    void setDefaultVal(const std::string& val);
    void setExtra(const std::string& val);

private:
    InterfaceData* m_interfaceData;
};

struct SettingData final
{
    VectorString   option   {};
    SettingType    type     {};
    std::string    language {};
};

class Setting
{
public:
    Setting();
    ~Setting();

    std::string getOption(const std::string& var);

    /*!
     * \brief getList function will returns list of setting items.
     * \returns list
     */
    __tegra_no_discard SettingType getList() __tegra_const_noexcept;

    /*!
     * \brief option function gets item as option.
     * \returns list of options.
     */
    VectorString option() const;

    /*!
     * \brief setOption function will sets value into option.
     * \param val as list of string.
     */
    void setOption(const VectorString& val);

    /*!
     * \brief saveList function will sets all data inside the list of setting. Any website changes effects on the list data.
     */
    void saveList() __tegra_const_noexcept;

private:
    SettingData* m_settingData;
};

TEGRA_NAMESPACE_END

#endif  // SETTING_HPP
