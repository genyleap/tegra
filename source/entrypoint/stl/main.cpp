/*!
 * MIT License
 *
 * Copyright (c) 2022 The Genyleap. All rights reserved.
 * Copyright (c) 2022 Kambiz Asadzadeh.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "core/core.hpp"
#include "core/config.hpp"
#include "core/database.hpp"
#include "core/version.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Database;
TEGRA_USING_NAMESPACE Tegra::eLogger;

inline void preInit()
{
    auto appData            = ApplicationData();                ///< Application Data
    auto version            = Version();                        ///< Version
    auto semanticVersion    = SemanticVersion();                ///< Semantic Version
    auto con                = Connection();                     ///< Connection
    auto config             = Configuration(ConfigType::File);  ///< Configuration
    //Configuration before use
    config.init(SectionType::SystemCore);
    {
        semanticVersion.Major = 0;
        semanticVersion.Minor = 2;
        semanticVersion.Patch = 300;
        semanticVersion.PreRelease = "alpha";
        version.setVersion(semanticVersion, Tegra::Version::ReleaseType::Alpha);
    }

    {
        appData.path                    =   __tegra_null_str;
        appData.module                  =   "main";
        appData.semanticVersion         =   semanticVersion;
        appData.releaseType             =   Tegra::Version::ReleaseType::Alpha;
        appData.systemInfo.version      =   appData.semanticVersion;
        appData.systemInfo.codeName     =   "concept";
        appData.systemInfo.name         =   "Tegra";
        appData.systemInfo.compiledDate =   __tegra_compiled_date;
        appData.systemInfo.license      =   SystemLicense::Free;
        appData.systemInfo.type         =   SystemType::General;
    }
    auto application = Application(appData);    ///< Application
    if(application.engine->initialize())
    {
        application.start();
        try {
            con.connect();
        } catch (const Exception& e)
        {
            Log("Error on connection!", LoggerType::Failed);
        }
    }
}

int main()
{   
    //!Set HTTP listener address and port
    Framework::app().addListener("0.0.0.0",80);
    AppFramework::application().loadConfigFile(std::string(CONFIG::FRAMEWORK_CONFIG_FILE));
    //!Pre-Initialization
    preInit();
    //! Application Framework Starter
    AppFramework::application().run();

    return 0;
}
