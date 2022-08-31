/*!
 * @file        prestructure.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Prestructure data for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef PRESTRUCTURE_HPP
#define PRESTRUCTURE_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

/*!
 * \brief The SystemStatus enum
 */
__tegra_enum_class SystemStatus : u8
{
    Off             = 0x1, ///!< The system is off.
    On              = 0x2, ///< The system is on.
    Suspened        = 0x3, ///< The system is on suspended mode.
    Ready           = 0x4, ///< The system is ready.
    Maintainance    = 0x5, ///< The system is under maintainance.
    Unknown         = 0x6  ///< It is not clear what state the system is in.
};

/*!
 * \brief The SystemType enum
 */
__tegra_enum_class SystemType: u8
{
    Private      = 0x1, ///< Private.
    General      = 0x2, ///< General.
    Professional = 0x3, ///< Professional.
    Premium      = 0x4, ///< Premium.
    Default      = 0x5  ///< Default.
};

/*!
 * \brief The SystemLicense enum
 */
__tegra_enum_class SystemLicense: u8
{
    Free            = 0x1,  ///< This flag marks the system as the free version.
    Commercial      = 0x2   ///< This flag marks the system as the commercial version.
};

/*!
 * \brief The CompatibilityLevel struct
 */
struct CompatibilityLevel final
{
    u8 NoneCompatibility;
    u8 SimpleCompatibility;
    u8 GreenCompatibility;
    u8 PerfectCompatibility;
};

/*!
 * @title The SemanticVersion class
 * @brief Given a version number MAJOR.MINOR.PATCH, increment the:
 * ---------------------------------------------------------------
 * ---- MAJOR version when you make incompatible API changes.
 * ---- MINOR version when you add functionality in a backwards compatible manner.
 * ---- PATCH version when you make backwards compatible bug fixes.
 * Additional labels for pre-release and build metadata are available as extensions to the MAJOR.MINOR.PATCH format.
 * @version Semantic Versioning 2.0.0
 */
struct SemanticVersion final
{
    uint Major                  {};
    uint Minor                  {};
    uint Patch                  {};
    OptionalString  PreRelease  {}; ///< Software release life cycle. https://en.wikipedia.org/wiki/Software_release_life_cycle
};

/*!
 * \brief The SystemInfo struct
 */
struct SystemInfo final
{
    //!Basic Information
    OptionalString              codeName        {};
    OptionalString              name            {};
    Optional<SemanticVersion>   version         {};
    OptionalString              model           {};
    OptionalString              compiledDate    {};
    //!Extra
    Optional<SystemType>        type            {};
    Optional<SystemLicense>     license         {};
};

#endif // PRESTRUCTURE_HPP
