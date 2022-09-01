/*!
 * @file        terminal.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Terminal system for console output.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */
#ifndef TEGRA_TERMINAL_HPP
#define TEGRA_TERMINAL_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Terminal)

class __tegra_export NativeTerminal {
public:
    NativeTerminal() = default;
    NativeTerminal(const NativeTerminal& rhsNativeTerminal) = delete;
    NativeTerminal(NativeTerminal&& rhsNativeTerminal) noexcept = delete;
    NativeTerminal& operator=(const NativeTerminal& rhsNativeTerminal) = delete;
    NativeTerminal& operator=(NativeTerminal&& rhsNativeTerminal) noexcept = delete;
    ~NativeTerminal() = default;

    enum class ColorType : u8
    {
        BLACK,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        GREY,
        DARKGREY,
        LIGHTBLUE,
        LIGHTGREEN,
        LIGHTCYAN,
        LIGHTRED,
        LIGHTMAGENTA,
        YELLOW,
        WHITE
    };

#ifdef PLATFORM_WINDOWS

    /* Enum to store Foreground colors */
    enum class FOREGROUND_COLORS : u8
    {
        BLACK           = 0,
        BLUE            = 1,
        GREEN           = 2,
        CYAN            = 3,
        RED             = 4,
        MAGENTA         = 5,
        BROWN           = 6,
        LIGHTGRAY       = 7,
        GRAY            = 8,
        LIGHTBLUE       = 9,
        LIGHTGREEN      = 10,
        LIGHTCYAN       = 11,
        LIGHTRED        = 12,
        LIGHTMAGENTA    = 13,
        YELLOW          = 14,
        WHITE           = 15
    };

    /*Enum to store Background colors*/
    enum class BACKGROUND_COLORS : u8
    {
        NAVYBLUE    = 16,
        GREEN       = 32,
        TEAL        = 48,
        MAROON      = 64,
        PURPLE      = 80,
        OLIVE       = 96,
        SILVER      = 112,
        GRAY        = 128,
        BLUE        = 144,
        LIME        = 160,
        CYAN        = 176,
        RED         = 192,
        MAGENTA     = 208,
        YELLOW      = 224,
        WHITE       = 240

    };

#endif

    /*!
     * \brief setColor function will sets color to content.
     * \param color as color type.
     */
    void setColor(const ColorType& color);

    /*!
     * \brief resetColor function will resets the style of content to default state.
     */
    void resetColor();

    static std::ostream& Default(std::ostream& stream);
    static std::ostream& Info(std::ostream& stream);
    static std::ostream& Warning(std::ostream& stream);
    static std::ostream& Critical(std::ostream& stream);
    static std::ostream& Error(std::ostream& stream);
    static std::ostream& Success(std::ostream& stream);
    static std::ostream& Done(std::ostream& stream);
    static std::ostream& Paused(std::ostream& stream);
    static std::ostream& InProgress(std::ostream& stream);
    static std::ostream& Primary(std::ostream& stream);

    /*!
     * \brief Reset will reset all configured colors.
     * \param stream
     * \return default color of console/terminal.
     */
    static std::ostream& Reset(std::ostream& stream);
private:
    uint m_color;
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_TERMINAL_HPP
