//! Tegra's View.
#ifdef __has_include
# if __has_include("view.hpp")
#   include "view.hpp"
#else
#   error "Tegra's view was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::View)

ViewIndex::ViewIndex()
{
}

ViewIndex::~ViewIndex()
{
}

__tegra_no_discard std::map<std::string, std::string> ViewIndex::defaultView(const UserViewType userType) __tegra_noexcept
{
    //!Default indexes.
    switch (userType) {
    case UserViewType::User:
        m_view.insert(std::pair<std::string, std::string>("home"         , SYSTEM_USER_VIEW_ROOT + FROM_TEGRA_STRING("::home")));
        m_view.insert(std::pair<std::string, std::string>("index"        , SYSTEM_USER_VIEW_ROOT + FROM_TEGRA_STRING("::index")));
        m_view.insert(std::pair<std::string, std::string>("setup"        , SYSTEM_USER_VIEW_ROOT + FROM_TEGRA_STRING("::install")));
        m_view.insert(std::pair<std::string, std::string>("error"        , SYSTEM_USER_VIEW_ROOT + FROM_TEGRA_STRING("::error")));
        m_view.insert(std::pair<std::string, std::string>("preinstall"   , SYSTEM_USER_VIEW_ROOT + FROM_TEGRA_STRING("::preinstall")));
        break;
    case UserViewType::Admin:
        m_view.insert(std::pair<std::string, std::string>("dashboard"    , SYSTEM_ADMIN_VIEW_ROOT + FROM_TEGRA_STRING("::dashboard")));
        m_view.insert(std::pair<std::string, std::string>("index"        , SYSTEM_ADMIN_VIEW_ROOT + FROM_TEGRA_STRING("::index")));
        m_view.insert(std::pair<std::string, std::string>("setup"        , SYSTEM_ADMIN_VIEW_ROOT + FROM_TEGRA_STRING("::install")));
        m_view.insert(std::pair<std::string, std::string>("error"        , SYSTEM_ADMIN_VIEW_ROOT + FROM_TEGRA_STRING("::error")));
        break;
    case UserViewType::Moder:
        m_view.insert(std::pair<std::string, std::string>("dashboard"    , SYSTEM_MODER_VIEW_ROOT + FROM_TEGRA_STRING("::dashboard")));
        m_view.insert(std::pair<std::string, std::string>("index"        , SYSTEM_MODER_VIEW_ROOT + FROM_TEGRA_STRING("::index")));
        m_view.insert(std::pair<std::string, std::string>("setup"        , SYSTEM_MODER_VIEW_ROOT + FROM_TEGRA_STRING("::install")));
        m_view.insert(std::pair<std::string, std::string>("error"        , SYSTEM_MODER_VIEW_ROOT + FROM_TEGRA_STRING("::error")));
        break;
    case UserViewType::Guest:
        m_view.insert(std::pair<std::string, std::string>("index"        , SYSTEM_GUEST_VIEW_ROOT + FROM_TEGRA_STRING("::index")));
        m_view.insert(std::pair<std::string, std::string>("error"        , SYSTEM_GUEST_VIEW_ROOT + FROM_TEGRA_STRING("::error")));
        m_view.insert(std::pair<std::string, std::string>("preinstall"   , SYSTEM_GUEST_VIEW_ROOT + FROM_TEGRA_STRING("::preinstall")));
        break;
    case UserViewType::Extra:
        m_view.insert(std::pair<std::string, std::string>("index"        , SYSTEM_EXTRA_VIEW_ROOT + FROM_TEGRA_STRING("::index")));
        m_view.insert(std::pair<std::string, std::string>("error"        , SYSTEM_EXTRA_VIEW_ROOT + FROM_TEGRA_STRING("::error")));
        break;
    default:
        break;
    }
    return m_view;
}

void ViewIndex::registerView(const UserViewType userType, const std::string& key, const std::string& value)
{
    switch (userType) {
    case UserViewType::User:
        m_view.insert(std::pair<std::string, std::string>(key,  SYSTEM_USER_VIEW_ROOT + FROM_TEGRA_STRING("::" + value)));
        break;
    case UserViewType::Admin:
        m_view.insert(std::pair<std::string, std::string>(key,  SYSTEM_ADMIN_VIEW_ROOT + FROM_TEGRA_STRING("::" + value)));
        break;
    case UserViewType::Moder:
        m_view.insert(std::pair<std::string, std::string>(key,  SYSTEM_MODER_VIEW_ROOT + FROM_TEGRA_STRING("::" + value)));
        break;
    case UserViewType::Guest:
        m_view.insert(std::pair<std::string, std::string>(key,  SYSTEM_GUEST_VIEW_ROOT + FROM_TEGRA_STRING("::" + value)));
        break;
    case UserViewType::Extra:
        m_view.insert(std::pair<std::string, std::string>(key,  SYSTEM_EXTRA_VIEW_ROOT + FROM_TEGRA_STRING("::" + value)));
        break;
    default:
        break;
    }
}

TEGRA_NAMESPACE_END
