//! Tegra's Terminal.
#ifdef __has_include
# if __has_include("terminal.hpp")
#   include "terminal.hpp"
#else
#   error "Tegra's terminal was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra::Terminal)

void NativeTerminal::setColor([[maybe_unused]]const NativeTerminal::ColorType &color) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(color));
#else
    //      std::string beginStyle  = __tegra_null_str;
    //      std::string endStyle    = __tegra_null_str;
    //      beginStyle  = "\033[0;90m";
    //      endStyle    = "\033[0m";
    // ToDo...
#endif
}

void NativeTerminal::resetColor() {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    // ToDo...
#endif
}

std::ostream &NativeTerminal::Default(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(7));
#else
    stream << "\033[0;37m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Info(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::GRAY));
#else
    stream << "\033[0;37m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Warning(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::YELLOW));
#else
    stream << "\033[0;33m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Critical(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::LIGHTRED));
#else
    stream << "\033[0;31m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Error(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::RED));
#else
    stream << "\033[1;91m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Success(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::GREEN));
#else
    stream << "\033[1;32m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Done(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::LIGHTGREEN));
#else
    stream << "\033[1;92m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Paused(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::CYAN));
#else
    stream << "\033[0;96m";
#endif
    return stream;
}

std::ostream &NativeTerminal::InProgress(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::BROWN));
#else
    stream << "\033[0;93m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Reset(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::LIGHTGRAY));
#else
    stream << "\033[0;37m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Primary(std::ostream &stream) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            static_cast<WORD>(FOREGROUND_COLORS::BROWN));
#else
    stream << "\033[0;35m";
#endif
    return stream;
}

TEGRA_NAMESPACE_END
