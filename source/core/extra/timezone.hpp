/*!
 * @file        timezone.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Timezone for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_TIMEZONE_HPP
#define TEGRA_TIMEZONE_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

///!Concept of constans.
struct TimeZoneConstants final
{
    static constexpr u16   AFRICA       = 1;
    static constexpr u16   AMERICA      = 2;
    static constexpr u16   ANTARCTICA   = 4;
    static constexpr u16   ARCTIC       = 8;
    static constexpr u16   ASIA         = 16;
    static constexpr u16   ATLANTIC     = 32;
    static constexpr u16   AUSTRALIA    = 64;
    static constexpr u16   EUROPE       = 128;
    static constexpr u16   INDIAN       = 256;
    static constexpr u16   PACIFIC      = 512;
    static constexpr u16   UTC          = 1024;
    static constexpr u16   ALL          = 2047;
    static constexpr u16   ALL_WITH_BC  = 4095;
    static constexpr u16   PER_COUNTRY  = 4096;

};

/*!
 * \brief The Timezone class
 */
class __tegra_export Timezone
{
public:
    Timezone();
    ~Timezone();
    ///! ToDo and wating for c++20 timezone support.
    /// We can use https://github.com/HowardHinnant/date too.
    //!Get more information... ToDo...

private:
    TEGRA_DISABLE_COPY(Timezone)
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_TIMEZONE_HPP
