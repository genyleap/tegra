/*!
 * @file        main.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System user-defined entry point.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#include "config.hpp" // CMake config.
#include "core/config.hpp"
#include "installer/setup.hpp"
#include "core/core.hpp"
#include "core/database.hpp"
#include "core/version.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Database;
TEGRA_USING_NAMESPACE Tegra::eLogger;

inline void preInit()
{
    auto appData = ApplicationData();              ///< Application Data
    auto version = Version();                      ///< Version
    auto semanticVersion = SemanticVersion();      ///< Semantic Version
    auto con = Connection();                       ///< Connection
    auto config = Configuration(ConfigType::File); ///< Configuration
    // Configuration before use
    config.init(SectionType::SystemCore);
    {   // Set from cmake config.hpp.in
        semanticVersion.Major = PROJECT_VERSION_MAJOR;
        semanticVersion.Minor = PROJECT_VERSION_MINOR;
        semanticVersion.Patch = PROJECT_VERSION_PATCH;
        semanticVersion.PreRelease = PROJECT_VERSION_TYPE;
        version.setVersion(semanticVersion, Tegra::Version::ReleaseType::Alpha);
    }
    // App Data
    {
        appData.path = __tegra_null_str;
        appData.module = "main";
        appData.semanticVersion = semanticVersion;
        appData.releaseType = Tegra::Version::ReleaseType::Alpha;
        appData.systemInfo.version = appData.semanticVersion;
        appData.systemInfo.codeName = "concept";
        appData.systemInfo.name = PROJECT_NAME;
        appData.systemInfo.compiledDate = __tegra_compiled_date;
        appData.systemInfo.license = SystemLicense::Free;
        appData.systemInfo.type = SystemType::General;
    }
    auto application = Application(appData); ///< Application
    if (application.engine->initialize()) {
        application.start();
        try {
            con.connect();
        } catch (const Exception& e) {
            Log("Error on connection!", LoggerType::Failed);
        }
    }
}

int main()
{
    //! Set HTTP listener address and port
    Framework::app().addListener("0.0.0.0", 80);
    AppFramework::application().loadConfigFile(std::string(CONFIG::FRAMEWORK_CONFIG_FILE));
    //! Pre-Initialization
    preInit();
    //! Application Framework Starter
    AppFramework::application().run();

    return 0;
}
