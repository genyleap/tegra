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
#if defined(PLATFORM_MOBILE) && defined(PLATFORM_ANDROID)
    std::string res = {"assets:/"};
#elif defined(PLATFORM_MOBILE) && defined(PLATFORM_IOS)
    std::string res = {"/"};
#elif defined(PLATFORM_MAC)
    std::string res = {"/"};
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        std::string v = path;
        res = v.substr(0, v.find_last_of("\\/")) + "/";
    }
#elif defined(PLATFORM_LINUX)
    char res[ PATH_MAX ];
    ssize_t count = readlink("/", res, PATH_MAX);
    return std::string(res, (count > 0) ? count : 0);
#elif defined(PLATFORM_WINDOWS)
    std::string res = {"/"};
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    res = std::string(buffer).substr(0, pos);
#elif defined(PLATFORM_FREEBSD)
    std::string res = {"/"};
    res = "FreeBSD does not support yet!"
#elif defined(PLATFORM_SOLARIS)
    std::string res = {"/"};
    res = "Solaris does not support yet!"
#endif
    return res;
}

bool Path::exists(const std::string& file) {
    struct stat buffer;
    return (stat (file.c_str(), &buffer) == 0);
}

TEGRA_NAMESPACE_END
