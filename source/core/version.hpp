/*!
 * @file        version.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System version structure.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_VERSION_HPP
#define TEGRA_VERSION_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The Version class
 */
class __tegra_export Version
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Version)

    __tegra_enum_class ReleaseType : u8
    {
        PreAlpha            = 0x1,       ///< Pre-alpha refers to all activities performed during the software project before formal testing.
        Alpha               = 0x2,       ///< The alpha phase of the release life cycle is the first phase of software testing (alpha is the first letter of the Greek alphabet, used as the number 1).
        Beta                = 0x3,       ///< Beta, named after the second letter of the Greek alphabet, is the software development phase following alpha.
        ReleaseCandidate    = 0x4,       ///< A release candidate (RC), also known as "going silver", is a beta version with potential to be a stable product, which is ready to release unless significant bugs emerge.
        StableRelease       = 0x5        ///< Also called production release, the stable release is the last release candidate (RC) which has passed all verifications / tests. The remaining bugs are considered as acceptable.
    };

    /*!
     * \brief setVersion will sets value to version.
     * \param version is parameter as SemanticVersion.
     */
    void setVersion(const SemanticVersion& version, const ReleaseType releaseType);

    /*!
     * \brief getVersion will gets version data.
     * \returns SemanticVersion.
     */
    SemanticVersion getVersion() __tegra_noexcept;

    /*!
     * \brief getAsString will gets version data as string.
     * \returns string of version.
     */
    std::string getAsString() __tegra_const __tegra_noexcept;

private:
    SemanticVersion* m_SemanticVersion{};
    TEGRA_DISABLE_COPY(Version)
    TEGRA_DISABLE_MOVE(Version)
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_VERSION_HPP
