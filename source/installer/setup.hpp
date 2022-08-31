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

#ifndef SETUP_HPP
#define SETUP_HPP

#include "setupdata.hpp"
#include "common.hpp"
#include "core/core.hpp"
#include "core/application.hpp"
#include "translator/language.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra::Installer)

/*!
 * \brief The Setup class
 */
class __tegra_export Setup
{
public:
    Setup() = delete;
    Setup(const ApplicationData& appData, const InstallerData& installerData);
    ~Setup();

    /*!
     * \brief installableApps
     * \returns installable applications as array based on key and value.
     */
    std::map<std::string, bool> installableApps();

    /*!
     * \brief defaultBaseApps
     * \returns list of default unchangeable applications based on key and value.
     */
    const std::map<std::string, bool> defaultBaseApps() __tegra_noexcept;

    /*!
     * \brief defaultAppsList
     * \returns list of default applications based on key and value.
     */
    std::map<std::string, bool> defaultAppsList() __tegra_noexcept;

    /*!
     * \brief requiresList will gets list of requirements.
     * \returns as array.
     */
    RequireList requiresList();

    /*!
     * \brief registerRequires will sets requirement items.
     * \param rlist as array.
     */
    void registerRequires(const RquireTypes& rlist);

    /*!
     * \brief requirementList will gets final requirments by status.
     * \returns array as key and value.
     */
    RquireTypes requirementList();

    /*!
     * \brief checkRequire will checks system status for install.
     * \returns true if system is not installed.
     */
    bool checkRequire() __tegra_noexcept;

    /*!
     * \brief checkRequire will checks end-user license agreement.
     * \returns true if system is in phase eula.
     */
    bool eula(const bool read) __tegra_noexcept;

    /*!
     * \brief application will sets application for your system.
     * \returns true if system is in phase application.
     */
    bool application(const std::map<std::string, bool>& appList) __tegra_noexcept;

    /*!
     * \brief serverDertail will sets system inputs for server config.
     * \returns true if system is in phase serverDertail.
     */
    bool serverDertail(const ServerData& serverData) __tegra_noexcept;

    /*!
     * \brief customization will sets user custom layout, theme and admin's data.
     * \returns true if system is in phase customization.
     */
    bool customization() __tegra_noexcept;

    /*!
     * \brief installation will starts the system to install.
     * \returns true if system is in phase installation.
     */
    bool installation() __tegra_noexcept;

    /*!
     * \brief finished function calls the final level for system.
     * \returns true if system is in phase finished.
     */
    bool finished() __tegra_noexcept;

    /*!
     * \brief setupLevelInfo
     * \returns information of server data.
     */
    SetupLevelInfo setupLevelInfo();

private:
    SetupAppData m_setupAppData{};
    ApplicationData* appDataPtr{};
    InstallerData* m_installerDataPtr{};
    ServerData m_serverData;
    RequireList m_requireList;
    RquireTypes m_rlist;
    std::map<std::string, bool> m_installableApps;
    std::map<std::string, bool> m_defaultAppsList;
    PrivateInstallerData m_privateInstallerData;
    Scope<Multilangual::Language> languagePtr{};
    SetupLevelInfo m_setupLevelInfo{};

private:
    TEGRA_DISABLE_COPY(Setup)

};

TEGRA_NAMESPACE_END

#endif // SETUP_HPP
