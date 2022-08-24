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

#ifndef TEGRA_REGEX_HPP
#define TEGRA_REGEX_HPP

#include <locale.h>
#include <iostream>
#include <sstream>
#include <string>

#include "common.hpp"

TEGRA_NAMESPACE_BEGIN(Tegra::Regexation)

// Defines for IPv4 and v6
#define VALID_IPV4 0x1  // 1 is valid ip : 127.0.0.1
#define VALID_IPV6 0x1 // 1 is valid ipv6 = // 92001:cdba:0000:0000:0000:0000:3257:9652)-(2001:cdba:0:0:0:0:3257:9652) // - (2001:cdba::3257:9652)
#define INVALID_IPV6 0x0  // 0 is invalid ip v4
#define INVALID_IPV4 0x0  // 0 is invalid ip v6

// Modes for password types
#define PASSWORD_MODE_0 0x0  // 1 is simple mode
#define PASSWORD_MODE_1 0x1  // 0 is complex mode
#define VALID_PASSWORD \
    0x1  // 1 is valid Simple : (Kambiz1234@#$@) Complex : Kambiz1234!@#$%
#define INVALID_PASSWORD 0x0  // 0 is invalid

// Defines for mac address
#define VALID_MAC 0x1    // 1 is valid Example: (76:54:2E:D5:D8:45)
#define INVALID_MAC 0x0  // 0 is invalid

// Defines for domain

#define VALID_DOMAIN 0x1    // 1 is valid
#define INVALID_DOMAIN 0x0  // 0 is invalid

// Defines for http and https
#define VALID_HTTP 0x1     // 1 is valid
#define VALID_HTTPS 0x1    // 1 is valid
#define INVALID_HTTP 0x0   // 0 is invalid
#define INVALID_HTTPS 0x0  // 0 is invalid

// Defines for ftp
#define VALID_FTP 0x1    // 1 is valid
#define INVALID_FTP 0x0  // 0 is invalid

// Defines for alphanumeric
#define VALID_ALPHANUMERIC 0x1    // 1 is valid
#define INVALID_ALPHANUMERIC 0x0  // 0 is invalid

// Defines for variable
#define VALID_VARIABLE 0x1    // 1 is valid
#define INVALID_VARIABLE 0x0  // 0 is invalid

// Defines for variable
#define VALID_NUMERIC 0x1    // 1 is valid
#define INVALID_NUMERIC 0x0  // 0 is invalid

// Defines for URL
#define VALID_URL 0x1    // 1 is valid
#define INVALID_URL 0x0  // 0 is invalid

// Defines for Username
#define VALID_USERNAME 0x1    // 1 is valid
#define INVALID_USERNAME 0x0  // 0 is invalid

// Defines for Mobile
#define VALID_MOBILE 0x1    // 1 is valid
#define INVALID_MOBILE 0x0  // 0 is invalid

// Defines for Hex
#define VALID_HEX 0x1    // 1 is valid
#define INVALID_HEX 0x0  // 0 is invalid

// Defines for Html
#define VALID_HTML 0x1    // 1 is valid
#define INVALID_HTML 0x0  // 0 is invalid

// Defines for base64
#define VALID_BASE64 0x1    // 1 is valid
#define INVALID_BASE64 0x0  // 0 is invalid

// Defines for ISBN code
#define VALID_ISBN 0x1    // 1 is valid
#define INVALID_ISBN 0x0  // 0 is invalid

// Defines for Persian language
#define VALID_PERSIAN 0x1    // 1 is valid
#define INVALID_PERSIAN 0x0  // 0 is invalid

/*!
 * \brief The Regex class
 */
class Regex
{
public:
    Regex() = default;
    ~Regex() = delete;

    /*!
     * @brief reverse
     * @param s
     */
    void reverse(char s[]);

    /*!
     * @brief isEmailValid
     * @param email
     * @return
     */
    bool isEmailValid(const std::string& email);

    /*!
     * @brief vowelReplace
     * @param input
     * @return
     */
    std::string vowelReplace(const std::string& input);

    /*!
     * @brief strReplace
     * @param input
     * @param find
     * @param replace
     * @return
     */
    std::string strReplace(const std::string& input, const std::string& find, const std::string& replace);

    /*!
     * @brief changeRoot
     * @param item
     * @param newroot
     * @return
     */
    std::string changeRoot(const std::string& item, const std::string& newroot);

    /*!
     * @brief repeatedWord
     * @param input
     * @return
     */
    std::string repeatedWord(const std::string& input);

    /*!
     * @brief isUrlValid
     * @param url
     * @return
     */
    bool isUrlValid(const std::string& url);

    /*!
     * @brief isIpv4Valid
     * @param input
     * @return
     */
    bool isIpv4Valid(const std::string& input);

    /*!
     * @brief isIpv6Valid
     * @param input
     * @return
     */
    bool isIpv6Valid(const std::string& input);

    /*===============================================
     * Matching Mac Addresses (Physical address)    #
     * ==============================================
     *
     * A MAC address is a unique identifier assigned to most network adapters or
     * network interface cards (NICs) by the manufacturer for identification,
     * IEEE 802 standards use 48 bites or 6 bytes to represent a MAC address. This
     * format gives 281,474,976,710,656 possible unique MAC addresses.*/

    bool isMacValid(const std::string& input);

    /* ==============================================
     # Domain validation                            #
     * ==============================================
     *
     * The domain name is a component of a uniform resource locator (URL) used to
     access web sites, for example:
     * URL: http://www.example.net/index.html
     * Top-level domain: net
     * Second-level domain: example
     * Host name: www
     * A domain name may point to multiple IP addresses to provide server
     redundancy for the services offered, a feature that is used to manage the
     traffic of large, popular web sites.
     * Web hosting services, on the other hand, run servers that are typically
     assigned only one or a few addresses while serving websites for many domains,
     a technique referred to as virtual web hosting. Such IP address overloading
     requires that each request identifies the domain name being referenced, for
     instance by using the HTTP request header field Host:, or Server Name
     Indication.
    */

    bool isDomainValid(const std::string& input);

    /* =============================================
     * Http validation
     * =============================================
     *
     * The Hypertext Transfer Protocol (HTTP) is an application protocol for
     * distributed, collaborative, hypermedia information systems. HTTP is the
     * foundation of data communication for the World Wide Web
     */

    bool isHttpValid(const std::string& input);

    /* =============================================
     * Https validation
     * =============================================
     *
     * HTTPS (also called HTTP over TLS, HTTP over SSL, and HTTP Secure) is a
     * protocol for secure communication over a computer network which is widely
     * used on the Internet. HTTPS consists of communication over Hypertext
     * Transfer Protocol (HTTP) within a connection encrypted by Transport Layer
     * Security or its predecessor, Secure Sockets Layer. The main motivation for
     * HTTPS is authentication of the visited website and protection of the
     * privacy and integrity of the exchanged data.
     */

    bool isHttpsValid(const std::string& input);

    /* =============================================
     * Ftp validation
     * =============================================
     *
     * The File Transfer Protocol (FTP) is a standard network protocol used to
     * transfer computer files between a client and server on a computer network.
     * FTP is built on a client-server model architecture and uses separate
     * control and data connections between the client and the server.
     */

    /*!
     * @brief isFtpValid
     * @param input
     * @return
     */
    bool isFtpValid(const std::string& input);

    /*!
     * @brief isPasswordValid
     * @param input
     * @param mode
     * @param length
     * @return
     */
    bool isPasswordValid(const std::string& input, const int &mode, const int &length);

    /*!
     * @brief isAlphanumericValid
     * @param input
     * @return
     */
    bool isAlphanumericValid(const std::string& input);

    /*!
     * @brief isNumberValid
     * @param input
     * @return
     */
    bool isNumberValid(const std::string& input);

    /*!
     * @brief isVariableValid
     * @param input
     * @return
     */
    bool isVariableValid(const std::string& input);

    /*!
     * @brief isHttpImageurlValid
     * @param input
     * @return
     */
    bool isHttpImageurlValid(const std::string& input);

    /*!
     * @brief isUsernameValid
     * @param input
     * @return
     */
    bool isUsernameValid(const std::string& input);

    /*!
     * @brief isIrMobileValid
     * @param input
     * @return
     */
    bool isIrMobileValid(const std::string& input);

    /* =============================================
     * Hex validation
     * =============================================
     *
     * In mathematics and computing, hexadecimal (also base 16, or hex) is a
     * positional numeral system with a radix, or base, of 16. It uses sixteen
     * distinct symbols, most often the symbols 0–9 to represent values zero to
     * nine, and A, B, C, D, E, F (or alternatively a, b, c, d, e, f) to represent
     * values ten to fifteen. Hexadecimal numerals are widely used by computer
     * system designers and programmers. Several different notations are used to
     * represent hexadecimal constants in computing languages; the prefix "0x" is
     * widespread due to its use in Unix and C (and related operating systems and
     * languages). Alternatively, some authors denote hexadecimal values using a
     * suffix or subscript. For example, one could write 0x2AF3 or 2AF316,
     * depending on the choice of notation.
     */

    bool isHexValid(const std::string& input);

    /* =============================================
     * HTML tag validation
     * =============================================
     *
     * Hypertext Markup Language, a standardized system for tagging text files to
     * achieve font, colour, graphic, and hyperlink effects on World Wide Web
     * pages.
     */

    bool isHtmlValid(const std::string& input);

    /* =============================================
     * Base64_encode — Encodes data with MIME base64
     * =============================================
     *
     * Base64 is a group of similar binary-to-text encoding schemes that represent
     * binary data in an ASCII string format by translating it into a radix-64
     * representation. The term Base64 originates from a specific MIME content
     * transfer encoding.
     */

    bool isBase64Valid(const std::string& input);

    /* =============================================
     * ISBN (International Standard Book Number)
     * =============================================
     *
     * ISBN is the acronym for International Standard Book Number. This 10 or
     * 13-digit number identifies a specific book, an edition of a book, or a
     * book-like product (such as an audiobook). Since 1970 each published book
     * has a unique ISBN. In 2007, assigned ISBNs changed from 10 digits to 13.
     */

    bool isIsbnValid(const std::string& input);

    /*!
     * \brief isPersianValid
     * \param input
     * \return
     */
    bool isPersianValid(const std::wstring &input);

};

TEGRA_NAMESPACE_END

#endif  // TEGRA_REGEX_HPP
