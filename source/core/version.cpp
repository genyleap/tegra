//! Tegra's Version.
#ifdef __has_include
# if __has_include("version.hpp")
#   include "version.hpp"
#else
#   error "Tegra's version was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs version class.
 */
Version::Version()
{
    __tegra_safe_instance(m_SemanticVersion, SemanticVersion);
}

/*!
 * \brief Destroys the version class.
 */
Version::~Version()
{
    __tegra_safe_delete(m_SemanticVersion);
}

void Version::setVersion(const SemanticVersion& version, const ReleaseType releaseType)
{
    m_SemanticVersion->Major        =   version.Major;
    m_SemanticVersion->Minor        =   version.Minor;
    m_SemanticVersion->Patch        =   version.Patch;

    switch (releaseType) {
    case ReleaseType::PreAlpha:
        m_SemanticVersion->PreRelease = "pre-alpha";
        break;
    case ReleaseType::Alpha:
        m_SemanticVersion->PreRelease = "alpha";
        break;
    case ReleaseType::Beta:
        m_SemanticVersion->PreRelease = "beta";
        break;
    case ReleaseType::ReleaseCandidate:
        m_SemanticVersion->PreRelease = "rc";
        break;
    case ReleaseType::StableRelease:
        m_SemanticVersion->PreRelease = "final";
        break;
    default:
        m_SemanticVersion->PreRelease = __tegra_unknown;
        break;
    }
}

SemanticVersion Version::getVersion() noexcept
{
    return *m_SemanticVersion;
}

std::string Version::getAsString() __tegra_const __tegra_noexcept
{
    std::string temp{};

    temp.append(std::to_string(m_SemanticVersion->Major));
    temp.append(".");
    temp.append(std::to_string(m_SemanticVersion->Minor));
    temp.append(".");
    temp.append(std::to_string(m_SemanticVersion->Patch));
    temp.append("-");
    temp.append(m_SemanticVersion->PreRelease.value_or(__tegra_unknown));

    return temp;
}

TEGRA_NAMESPACE_END


