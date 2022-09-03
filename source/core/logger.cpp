//! Tegra's Logger.
#ifdef __has_include
# if __has_include("logger.hpp")
#   include "logger.hpp"
#else
#   error "Tegra's logger was not found!"
# endif
#endif

//! Tegra's Terminal.
#ifdef __has_include
# if __has_include("terminal.hpp")
#   include "terminal.hpp"
#else
#   error "Tegra's terminal was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Terminal;

TEGRA_NAMESPACE_BEGIN(Tegra::eLogger)

Logger::~Logger()
{
    std::ostream& streamInStyle  = std::cout;
    streamInStyle << NativeTerminal::Reset << __tegra_newline;
}

void Logger::echo(const unsigned int    counter,
                  const time_t          occurTime,
                  const unsigned int    line,
                  std::string_view      function,
                  std::string_view      file,
                  std::string_view      message,
                  const int             type)
{
    std::thread::id threadId = std::this_thread::get_id();
    std::stringstream strThreadId;
    strThreadId << threadId;

    std::mutex           mutex_l;
    std::string          typeStr         = __tegra_null_str;
    std::ostream&        streamInStyleV1   = std::cout; //Buffered version.
    std::ostream&        streamInStyleV2   = std::clog; //UnBuffered version.
    std::string          beginStyle      = __tegra_null_str;
    std::string          endStyle        = __tegra_null_str;

    switch (type) {
    case LoggerType::Default:
        typeStr     =  "Default";
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Default;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Default;
            break;
        }
        beginStyle  = "\033[0;90m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Info:
        typeStr =  "Info" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Info;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Info;
            break;
        }
        beginStyle  = "\033[0;37m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Warning:
        typeStr =  "Warning" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Warning;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Warning;
            break;
        }
        beginStyle  = "\033[0;33m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Critical:
        typeStr =  "Critical" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Critical;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Critical;
            break;
        }
        beginStyle  = "\033[0;31m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Failed:
        typeStr =  "Failed" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Error;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Error;
            break;
        }
        beginStyle  = "\033[1;91m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Success:
        typeStr =  "Success" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Success;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Success;
            break;
        }
        beginStyle  = "\033[0;32m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Done:
        typeStr =  "Done" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Done;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Done;
            break;
        }
        beginStyle  = "\033[1;92m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Paused:
        typeStr =  "Paused" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::Paused;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::Paused;
            break;
        }
        beginStyle  = "\033[1;96m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::InProgress:
        typeStr =  "InProgress" ;
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1       << NativeTerminal::InProgress;
            break;
        case LogeState::ForceToError:
            streamInStyleV2       << NativeTerminal::InProgress;
            break;
        }
        beginStyle  = "\033[1;93m";
        endStyle    = "\033[0m";
        break;
    }

    if(LoggerModel == Mode::User) {
        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1 << " => Log Id : [" << counter
                            << "] : ["  << typeStr << "] "
                            << message << " { DateTime: "
                            << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                            << NativeTerminal::Reset << __tegra_newline;
            break;
        case LogeState::ForceToError:
            streamInStyleV2   << " => Log Id : [" << counter
                            << "] : ["  << typeStr << "] "
                            << message << " { DateTime: "
                            << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                            << NativeTerminal::Reset << __tegra_newline;
            break;
        }

        std::lock_guard<std::mutex> lock(mutex_l);

    } else if(LoggerModel == Mode::Developer) {

        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1 << " => Log Id : [" << counter  << "]"
                            << "[ Line : "  << line << "] "
                            << "[ Function : "  << function << "] "
                            << "[ Thread Id : "  << strThreadId.str() << "] "
                            << "[ File : "  << file << "] "
                            << "] : ["    << typeStr << "] "
                            << message    << " { DateTime: "
                            << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                            << NativeTerminal::Reset << __tegra_newline;
            break;
        case LogeState::ForceToError:
            streamInStyleV2 << " => Log Id : [" << counter  << "]"
                            << "[ Line : "  << line << "] "
                            << "[ Function : "  << function << "] "
                            << "[ Thread Id : "  << strThreadId.str() << "] "
                            << "[ File : "  << file << "] "
                            << "] : ["    << typeStr << "] "
                            << message    << " { DateTime: "
                            << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                            << NativeTerminal::Reset << __tegra_newline;
            break;
        }

        std::lock_guard<std::mutex> lock(mutex_l);

    } else if(LoggerModel == Mode::DataMining) {

        switch (LoggerState) {
        case LogeState::Normal:
            streamInStyleV1 << " => Log Id : [" << counter  << "]"
                            << "[ Line : "  << line << "] "
                            << "[ Function : "  << function << "] "
                            << "[ Thread Id : "  << strThreadId.str() << "] "
                            << "[ File : "  << file << "] "
                            << "] : ["    << typeStr << "] "
                            << message    << " { DateTime: "
                            << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                            << NativeTerminal::Reset << __tegra_newline;
            break;
        case LogeState::ForceToError:
            streamInStyleV2 << " => Log Id : [" << counter  << "]"
                            << "[ Line : "  << line << "] "
                            << "[ Function : "  << function << "] "
                            << "[ Thread Id : "  << strThreadId.str() << "] "
                            << "[ File : "  << file << "] "
                            << "] : ["    << typeStr << "] "
                            << message    << " { DateTime: "
                            << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                            << NativeTerminal::Reset << __tegra_newline;
            break;
        }
        std::lock_guard<std::mutex> lock(mutex_l);
    }
}


TEGRA_NAMESPACE_END
