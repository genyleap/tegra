/*!
 * @file        logger.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Logger for system activities.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_LOGGER_HPP
#define TEGRA_LOGGER_HPP

#include <ctime>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::eLogger)

/*!
 * \brief The LoggerType enum
 */
enum LoggerType : u8
{
    Default     =   0x0,    ///<Print as default message.
    Info        =   0x1,    ///<Print as information message.
    Warning     =   0x2,    ///<Print as warning message.
    Critical    =   0x3,    ///<Print as critical (error) message.
    Failed      =   0x4,    ///<Print as failed message.
    Success     =   0x5,    ///<Print as success message.
    Done        =   0x6,    ///<Print as done message.
    Paused      =   0x7,    ///<Print as paused message.
    InProgress  =   0x8     ///<Print as in progress message.
};

enum class Mode : u8
{
    User        =   0x0,    ///<Based on user log.
    Developer   =   0x1,    ///<Based on developer for debuging log.
    DataMining  =   0x2     ///<Based on data log.
};


#define Log(message, type)                                                                  \
Logger::echo(__tegra_compiler_counter,                                                      \
             std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()),        \
             __tegra_compiler_line,                                                         \
             __tegra_compiler_function,                                                     \
             __tegra_compiler_file,                                                         \
             message, type)

class Logger;
/*!
 * \brief The Logger class
 */
class __tegra_export Logger
{
public:
    Logger() = default;
    Logger(const Logger& rhsLogger) = delete;
    Logger(Logger&& rhsLogger) noexcept = delete;
    Logger& operator=(const Logger& rhsLogger) = delete;
    Logger& operator=(Logger&& rhsLogger) noexcept = delete;
    ~Logger();

    inline static Mode LoggerModel = Mode::User;

    /*!
     * \brief echo function will prints all data inline of usage!
     * \param counter as total called number.
     * \param occurTime shows the time of usage.
     * \param line shows the line of code.
     * \param function will gets function name.
     * \param file will gets file name [file.cpp] as example.
     * \param message gets message of information.
     * \param type gets type of log [success, warning and etc.]
     */
    __tegra_maybe_unused static void echo(
        const uint          counter,
        const time_t        occurTime,
        const uint          line,
        std::string_view    function,
        std::string_view    file,
        std::string_view    message,
        const int           type);

};

TEGRA_NAMESPACE_END

#endif  // TEGRA_LOGGER_HPP
