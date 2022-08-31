/*!
 * @file        regex.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Regular expression system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_REGEX_DEFINES_HPP
#define TEGRA_REGEX_DEFINES_HPP

#include "common.hpp"

TEGRA_NAMESPACE_BEGIN(Tegra::Regexation)

//! Defines for IPv4 and v6
#define TEGRA_REGEX_VALID_IPV4              0x1     // 1 is valid ip : 127.0.0.1
#define TEGRA_REGEX_VALID_IPV6              0x1     // 1 is valid ipv6 = // 92001:cdba:0000:0000:0000:0000:3257:9652)-(2001:cdba:0:0:0:0:3257:9652) // - (2001:cdba::3257:9652)
#define TEGRA_REGEX_INVALID_IPV6            0x0     // 0 is invalid ip v4
#define TEGRA_REGEX_INVALID_IPV4            0x0     // 0 is invalid ip v6

//! Modes for password types
#define TEGRA_REGEX_PASSWORD_MODE_0         0x0     // 1 is simple mode
#define TEGRA_REGEX_PASSWORD_MODE_1         0x1     // 0 is complex mode
#define TEGRA_REGEX_VALID_PASSWORD          0x1     // 1 is valid Simple : (Kambiz1234@#$@) Complex : Kambiz1234!@#$%
#define TEGRA_REGEX_INVALID_PASSWORD        0x0     // 0 is invalid

//! Defines for mac address
#define TEGRA_REGEX_VALID_MAC               0x1     // 1 is valid Example: (76:54:2E:D5:D8:45)
#define TEGRA_REGEX_INVALID_MAC             0x0     // 0 is invalid

//! Defines for domain

#define TEGRA_REGEX_VALID_DOMAIN            0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_DOMAIN          0x0     // 0 is invalid

//! Defines for http and https
#define TEGRA_REGEX_VALID_HTTP              0x1     // 1 is valid
#define TEGRA_REGEX_VALID_HTTPS             0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_HTTP            0x0     // 0 is invalid
#define TEGRA_REGEX_INVALID_HTTPS           0x0     // 0 is invalid

//! Defines for ftp
#define TEGRA_REGEX_VALID_FTP               0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_FTP             0x0     // 0 is invalid

//! Defines for alphanumeric
#define TEGRA_REGEX_VALID_ALPHANUMERIC      0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_ALPHANUMERIC    0x0     // 0 is invalid

//! Defines for variable
#define TEGRA_REGEX_VALID_VARIABLE          0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_VARIABLE        0x0     // 0 is invalid

//! Defines for variable
#define TEGRA_REGEX_VALID_NUMERIC           0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_NUMERIC         0x0     // 0 is invalid

//! Defines for URL
#define TEGRA_REGEX_VALID_URL               0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_URL             0x0     // 0 is invalid

//! Defines for Username
#define TEGRA_REGEX_VALID_USERNAME          0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_USERNAME        0x0     // 0 is invalid

//! Defines for Mobile
#define TEGRA_REGEX_VALID_MOBILE            0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_MOBILE          0x0     // 0 is invalid

//! Defines for Hex
#define TEGRA_REGEX_VALID_HEX               0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_HEX             0x0     // 0 is invalid

//! Defines for Html
#define TEGRA_REGEX_VALID_HTML              0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_HTML            0x0     // 0 is invalid

//! Defines for base64
#define TEGRA_REGEX_VALID_BASE64            0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_BASE64          0x0     // 0 is invalid

//! Defines for ISBN code
#define TEGRA_REGEX_VALID_ISBN              0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_ISBN            0x0     // 0 is invalid

//! Defines for Persian language
#define TEGRA_REGEX_VALID_PERSIAN           0x1     // 1 is valid
#define TEGRA_REGEX_INVALID_PERSIAN         0x0     // 0 is invalid

TEGRA_NAMESPACE_END

#endif  // TEGRA_REGEX_HPP
