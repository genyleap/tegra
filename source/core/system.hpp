/*!
 * @file        system.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System structure for hardware information.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_SYSTEM_HPP
#define TEGRA_SYSTEM_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::System)

class SystemInfo;
/*!
 * \brief The SystemInfo class
 */
class SystemInfo {
public:
    SystemInfo();
    ~SystemInfo();

    /*!
     * \brief getHostUserName function gets local host username.
     * \returns string of host username.
     */
    static std::string getHostUserName();

    /*!
     * \brief getHostName function gets local host name.
     * \returns string of host name.
     */
    static std::string getHostName();

    /*!
     * \brief getOsName function will gets os name.
     * \returns string of os name.
     */
    static std::string getOsName();

    /*!
     * \brief macAddressAsByteArray
     */
    static std::string macAddressAsByteArray(unsigned char MACData[]);
    /*!
     * \brief getMacAddress function gets Mac Address.
     * \returns string of Mac address.
     */
    static std::string getMacAddress();

    /*!
     * \brief getIpAddress function gets Ip Version 4 Address.
     * \returns as string of ip address.
     */
    static std::string getIpV4Address();

    /*!
     * \brief getIpV6Address function gets Ip Version 6 Address.
     * \returns as string of ip address.
     */
    static std::string getIpV6Address();

    /*!
     * \brief getMachineUniqueId function gets machine unique id.
     * \returns string of uniqueId
     */
    static std::string getMachineUniqueId();

    /*!
     * \brief getSerialNumber function gets setial number
     * \returns as string.
     */
    static std::string getSerialNumber();

    /*!
     * \brief getStorageDiskModel function gets storage disk model.
     * \returns as string.
     */
    static std::string getStorageDiskModel();

    /*!
     * \brief getStorageDiskSerialNumber function gets storage disk model.
     * \returns as string.
     */
    static std::string getStorageDiskSerialNumber();

    /*!
     * \brief getGpuModel function gets gpu type.
     * \returns as string of gpu type.
     */
    static std::string getGpuModel();

private:
    std::list<std::string> m_macAddressList{};

};


TEGRA_NAMESPACE_END

#endif // TEGRA_SYSTEM_HPP
