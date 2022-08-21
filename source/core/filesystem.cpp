#include "filesystem.hpp"

#if defined(PLATFORM_MAC) && !defined(PLATFORM_MOBILE)
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <mach-o/dyld.h>
//#include <IOKit/IOKitLib.h>
//#include <ApplicationServices/ApplicationServices.h>
//#include <ImageIO/ImageIO.h>
#elif defined(PLATFORM_MAC) && defined(PLATFORM_MOBILE)
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <mach-o/dyld.h>
//#include <IOKit/IOKitLib.h>
//#include <ApplicationServices/ApplicationServices.h>
#include <ImageIO/ImageIO.h>
#elif defined(PLATFORM_LINUX)
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX
#elif defined(PLATFORM_FREEBSD)
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#elif defined(PLATFORM_WINDOWS)
#include <Windows.h>
#include <Iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#elif defined (PLATFORM_ANDROID)
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#endif
TEGRA_NAMESPACE_BEGIN(Tegra::FileSystem)

Path::Path()
{
}

Path::~Path()
{
}

std::string Path::getExecutablePath() {
    std::string expath{};
#if defined(PLATFORM_MOBILE) && defined(PLATFORM_ANDROID)
    expath = "assets:/";
#elif defined(PLATFORM_MOBILE) && defined(PLATFORM_IOS)
    std::string res = {"/"};
#elif defined(PLATFORM_MAC)
    expath = "/";
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        std::string v = path;
        expath = v.substr(0, v.find_last_of("\\/")) + "/";
    }
#elif defined(PLATFORM_LINUX)
    char buff[PATH_MAX];
    ssize_t len = ::readlink(expath.c_str(), buff, sizeof(buff)-1);
    if (len != -1) {
        buff[len] = '\0';
        return std::string(buff);
    }
#elif defined(PLATFORM_WINDOWS)
    expath = "/";
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    expath = std::string(buffer).substr(0, pos);
#elif defined(PLATFORM_FREEBSD)
    expath = "/";
    res = "FreeBSD does not support yet!"
#elif defined(PLATFORM_SOLARIS)
    expath = "/";
    res = "Solaris does not support yet!"
#endif
    return expath;
}

bool Path::exists(const std::string& file) {
    struct stat buffer;
    return (stat (file.c_str(), &buffer) == 0);
}

TEGRA_NAMESPACE_END
