/*!
 * @file        configuration.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Configuration interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef CONFIGURATION_ABSTRACT_HPP
#define CONFIGURATION_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

__tegra_enum_class FileType : u8
{
    INI     =   0x1,  ///<An INI file is a configuration file for computer software that consists of a text-based content with a structure and syntax comprising key–value pairs for properties, and sections that organize the properties.
    JSON    =   0x2,  ///<JSON (JavaScript Object Notation) is an open standard file format and data interchange format that uses human-readable text to store and transmit data objects consisting of attribute–value pairs and arrays (or other serializable values).
    XML     =   0x3,  ///<Extensible Markup Language (XML) is a markup language and file format for storing, transmitting, and reconstructing arbitrary data. It defines a set of rules for encoding documents in a format that is both human-readable and machine-readable.
    YAML    =   0x4,  ///<YAML is a human-readable data-serialization language. It is commonly used for configuration files and in applications where data is being stored or transmitted.
    HOCON   =   0x5,  ///<HOCON or Human-Optimized Config Object Notation is a format for human-readable data, and a superset of JSON.
    TOML    =   0x6,  ///<TOML is a file format for configuration files. It is intended to be easy to read and write due to obvious semantics which aim to be "minimal", and is designed to map unambiguously to a dictionary.
    RUNCOM  =   0x7   ///<RUNCOM is a CTSS macro command (script) processor.
};

__tegra_enum_class ConfigType : u8
{
    File,       ///<Config based on file such as json.
    Database,   ///<Config based on database.
    Network     ///<Config based on network I/O.
};

__tegra_enum_class SectionType : u8
{
    SystemCore, ///<Configuration for system core.
    Database,   ///<Configuration for database.
    Framework,  ///<Configuration for framework.
    Interface,  ///<Configuration for User Interface.
    Custom      ///<Configuration for our custom sections.
};


#if !defined(ENABLE_SAFE_ONLY)
TEGRA_USING AbstractConfigMember = std::variant<FileType, std::string, std::vector<std::string>, bool>;
TEGRA_USING VariableType = std::variant<std::string, bool, uint>;   ///<In this section we will cover three data types, String, Boolean, and Integer.
TEGRA_USING KeyValueType = std::variant<std::string, VariableType>; ///<We need to have key as string and it's value as multi type as VariableType.
#else
struct AbstractConfigMember __tegra_final
{
    FileType                 fileType   {};
    std::string              path       {};
    std::vector<std::string> files      {};
    bool                     status     {};
};

/*!
 * \brief In this section we will cover three data types, String, Boolean, and Integer.
 */
struct VariableType __tegra_final
{
    union Type
    {
        uint        typeInt;
        bool        typeBool;
        std::string typeString;
    };
};

/*!
 * \brief We need to have key as string and it's value as VariableType.
 */
struct KeyValueType __tegra_final
{
    union Type
    {
        std::string  key;
        VariableType value;
    };
};
#endif

/*!
 * \brief The AbstractConfiguration class
 */
class __tegra_export AbstractConfiguration
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractConfiguration)

    /*!
     * \brief Checks and initializations are required from the abstract class before configuration.
     */
    __tegra_constexpr __tegra_virtual void init(const SectionType sectionType) = __tegra_zero;

    /*!
     * \brief Creating and implementing the content of a tree in configuration files requires this function.
     * \param fileType as types of configuration file.
     * \returns true if the creating and implementing was successful.
     */
    __tegra_constexpr __tegra_virtual bool create(const FileType& fileType) = __tegra_zero;

    /*!
     * \brief We need to register files inside the project to read and write.
     * \param files as a list string.
     */
    __tegra_virtual void registerFile(const VectorString& files) = __tegra_zero;

    /*!
     * \brief We need to get each file to check more details.
     * \returns list of files as string.
     */
    __tegra_virtual VectorString files() = __tegra_zero;

    /*!
     * \brief status of configuration system.
     * \returns true if there is no problem inside the config.
     */
    __tegra_virtual bool status() = __tegra_zero;

    /*!
     * \brief get function will gets value based on variable types.
     * \returns value based on it's type.
     */
    __tegra_virtual std::optional<VariableType> get() = __tegra_zero;

    /*!
     * \brief Writing in the configuration file requires sending information of variable type.
     * \param variable of multi types.
     */
    __tegra_virtual void write(const KeyValueType& variable) = __tegra_zero;

    /*!
     * \brief Updating in the configuration file requires sending information of variable type.
     * \param variable of multi types.
     */
    __tegra_virtual void update(const KeyValueType& variable) = __tegra_zero;

    /*!
     * \brief Removing in the configuration file requires sending information of variable type.
     * \param variable of multi types.
     */
    __tegra_virtual void remove(const KeyValueType& variable) = __tegra_zero;

    /*!
     * \brief It is sometimes necessary to reset all configuration variables.
     * \returns true if file resets.
     */
    __tegra_virtual bool reset() = __tegra_zero;

    /*!
     * \brief We may sometimes change the permission level of the file to prevent possible changes.
     * \returns true if permission changed.
     */
    __tegra_virtual bool lock() = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractConfiguration)
};

TEGRA_NAMESPACE_END

#endif  // CONFIGURATION_ABSTRACT_HPP
