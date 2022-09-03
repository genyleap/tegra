/*!
 * @file        view.hpp
 * @brief       This file is part of the Tegra System.
 * @details     View index for templates structure.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_VIEW_HPP
#define TEGRA_VIEW_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::View)

//!System view indexes.
struct SYSTEM_VIEW_INDEX final
{
    static constexpr std::string_view   PREINSTALL  = "preinstall";
    static constexpr std::string_view   INDEX       = "index";
    static constexpr std::string_view   HOME        = "home";
    static constexpr std::string_view   SETUP       = "setup";
    static constexpr std::string_view   ERROR       = "error";
    static constexpr std::string_view   UNKNOWN     = "unknown";
};

enum class UserViewType : u8
{
    Guest,
    User,
    Admin,
    Moder,
    Extra
};

#define SYSTEM_GUEST_VIEW_ROOT   "templates::guest"
#define SYSTEM_USER_VIEW_ROOT    "templates::user"
#define SYSTEM_ADMIN_VIEW_ROOT   "templates::admin"
#define SYSTEM_MODER_VIEW_ROOT   "templates::moder"
#define SYSTEM_EXTRA_VIEW_ROOT   "templates::extra"

/*!
 * \class View
 */
class __tegra_export ViewIndex
{
public:
    ViewIndex();
    ~ViewIndex();

    __tegra_no_discard std::map<std::string, std::string> defaultView(const UserViewType userType) __tegra_noexcept;

    void registerView(const UserViewType userType, const std::string& key, const std::string& value);

private:
    std::map<std::string, std::string> m_view{};

};

TEGRA_NAMESPACE_END

#endif // TEGRA_VIEW_HPP
