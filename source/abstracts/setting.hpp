/*!
 * @file        setting.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Site setting interface.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef SETTING_ABSTRACT_HPP
#define SETTING_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The ServiceType enum
 * \details Users and customers will have different options. For this purpose, it is necessary to have this structure.
 */
__tegra_enum_class ServiceType : u8
{
    Default       =   0x1,  ///< These types of options are available for all purposes and types of users.
    Customized    =   0x2,  ///< These types of options are only available for specific purposes or dedicated development.
    Premium       =   0x3   ///< These types of options are only available for premium users.
};

__tegra_enum_class Status : u8
{
    Disabled    =   0x0,  ///< Disabled.
    Hidden      =   0x1,  ///< Hidden.
    Active      =   0x2   ///< Active.
};

#if defined(ENABLE_SAFE_ONLY)
TEGRA_USING ValueType = std::variant<std::string, bool, s64, u64>;   ///<In this section we will cover data types for value of options.
#else
struct ValueType __tegra_final
{
    std::string AsString;           ///< String type.
    bool        AsBoolean;          ///< Boolean type.
    s64         AsSignedInteger;    ///< Integer with signed.
    u64         AsUnsignedInteger;  ///< Integer with unsigned.
};
#endif


/*!
 * \brief The SettingData class
 */
struct OptionData __tegra_final
{
    OptionalString      title      {};   ///< Title of setting option.
    OptionalString      descr      {};   ///< Description of setting option.
    Optional<ValueType> value      {};   ///< Value of setting option.
    OptionalJson        json       {};   ///< JSon of setting option.
    OptionalString      defaultVal {};   ///< Default value of setting option.
    OptionalString      extra      {};   ///< Extra value of setting option.
    Optional<Status>    status     {};   ///< Status value of setting option.
    OptionalNumeric     startGroup {};   ///< Group index value of option.
    ServiceType         service    {};   ///< Service type for option.
};

class __tegra_export AbstractSetting
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractSetting)

    /*!
     * \brief title is subject of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString title() __tegra_const = __tegra_zero;

    /*!
     * \brief descr is description of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString descr() __tegra_const = __tegra_zero;

    /*!
     * \brief value is content of option value.
     * \returns as ValueType.
     */
    __tegra_virtual Optional<ValueType> value() __tegra_const = __tegra_zero;

    /*!
     * \brief json is content based on json format.
     * \returns string.
     */
    __tegra_virtual OptionalString json() __tegra_const = __tegra_zero;

    /*!
     * \brief defaultVal will gets default value for option.
     * \returns string.
     */
    __tegra_virtual OptionalString defaultVal() __tegra_const = __tegra_zero;

    /*!
     * \brief extra will gets extra data from option.
     * \returns string.
     */
    __tegra_virtual OptionalString extra() __tegra_const = __tegra_zero;

    /*!
     * \brief status will gets status value from option.
     * \returns one of the Status.
     */
    __tegra_virtual Optional<Status> status() __tegra_const = __tegra_zero;

    /*!
     * \brief startGroup will gets index of group id.
     * \returns id as integer.
     */
    __tegra_virtual OptionalNumeric startGroup() __tegra_const = __tegra_zero;

    /*!
     * \brief It is necessary to receive a list of all the options in the settings in a part of the system.
     * \returns string of items list.
     */
    __tegra_virtual VectorString getByList() __tegra_const = __tegra_zero;

    /*!
     * \brief SetTitle inserts data for the option's title.
     * \param title is a string type for inserting values into the function.
     */
    __tegra_virtual void setTitle(const std::string& title) = __tegra_zero;

    /*!
     * \brief setDescr inserts data for the option's description.
     * \param descr is a string type for inserting values into the function.
     */
    __tegra_virtual void setDescr(const std::string& descr) = __tegra_zero;

    /*!
     * \brief setValue inserts data for the option's value.
     * \param value is a ValueType for inserting values into the function.
     */
    __tegra_virtual void setValue(const ValueType& value) = __tegra_zero;

    /*!
     * \brief setJson inserts data for the option's json.
     * \param json is a json type for inserting values into the function.
     */
    __tegra_virtual void setJson(const JSon& json) = __tegra_zero;

    /*!
     * \brief setDefaultValue inserts data for the option's default value.
     * \param deval is a string type for inserting values into the function.
     */
    __tegra_virtual void setDefaultValue(const std::string& deval) = __tegra_zero;

    /*!
     * \brief setStatus will change option's status.
     * \param status is a Status type for change the option status.
     */
    __tegra_virtual void setStatus(const Optional<Status> status) = __tegra_zero;

    /*!
     * \brief setStartGroup will sets option's group index.
     * \param index is number of group id.
     */
    __tegra_virtual void setStartGroup(const int index) = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractSetting)
};

TEGRA_NAMESPACE_END

#endif  // SETTING_ABSTRACT_HPP
