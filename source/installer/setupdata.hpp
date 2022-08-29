/*!
 * @file        setup.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Installer system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef SETUP_DATA_HPP
#define SETUP_DATA_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra::Installer)

using RquireTypes = std::map<std::string, bool>;
using RquireTypesPair = std::pair<std::string, bool>;

#define PairEnable(key, value)\
    std::pair<std::string, bool>(key, value)

struct SetupLevelInfo final
{
    OptionalString name         {__tegra_null_str};     ///< Level name as code.
    OptionalString title        {__tegra_null_str};     ///< Level title.
    OptionalString description  {__tegra_null_str};     ///< Level description.
    OptionalString details      {__tegra_null_str};     ///< Level details.
    OptionalString message      {__tegra_null_str};     ///< Level message.
};

/*!
 * \brief The SetupLevel enum
 */
enum class SetupLevel : u8 
{
    Requirements    = 0x1,      ///< L1: Check the details and prerequisites for installation.
    Eula            = 0x2,      ///< L2: Evaluation phase of license for use and an end-user license agreement.
    Application     = 0x3,      ///< L3: The stage of choosing the desired program as application or service.
    ServerDetail    = 0x4,      ///< L4: Server and database information.
    Finalize        = 0x5,      ///< L5: Finalizing structures, data and information for installing.
    Customize       = 0x6,      ///< L6: Customization for user and website.
    Install         = 0x7,      ///< L7: Install system.
    Done            = 0x8       ///< L8: Completion of the installation process.
};

struct InstallerData final 
{
    OptionalBool requirements               {false};
    OptionalBool eula                       {false};
    OptionalBool application                {false};
    OptionalBool serverDertail              {false};
    OptionalBool customization              {false};
    OptionalBool installation               {false};
    OptionalBool finished                   {false};
    SetupLevel level                        {SetupLevel::Requirements};
};

struct RequireList final
{
    OptionalBool openssl    {false};
    OptionalBool curl       {false};
    OptionalBool mysql      {false};
    OptionalBool postgresql {false};
    OptionalBool framework  {false};
    OptionalBool compiler   {false};
};

struct PrivateInstallerData final
{
    OptionalBool done       {false};
    OptionalBool success    {false};
};

struct SetupAppData final
{
    OptionalString  code     {__tegra_null_str};
    OptionalString  name     {__tegra_null_str};
    SemanticVersion version  {__tegra_zero};
    OptionalString  author   {__tegra_null_str};

    OptionalBool   value     {false};
    OptionalBool   lock      {false};
    OptionalBool   status    {false};
};

struct ServerData final
{
    std::string  hostName    {__tegra_null_str};
    std::string  dbname      {__tegra_null_str};
    std::string  dbpass      {__tegra_null_str};
    std::string  driver      {__tegra_null_str};
    std::string  charset     {__tegra_null_str};
    std::string  tablePrefix {__tegra_null_str};
    std::string  dbCharset   {__tegra_null_str};
    std::string  username    {__tegra_null_str};
    std::string  password    {__tegra_null_str};
    std::string  email       {__tegra_null_str};
    std::string  firstName   {__tegra_null_str};
    std::string  lastName    {__tegra_null_str};

    unsigned int cdn         {__tegra_zero};
    unsigned int dbPort      {__tegra_zero};
};

TEGRA_NAMESPACE_END

#endif // SETUP_DATA_HPP
