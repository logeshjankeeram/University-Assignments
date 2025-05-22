#include "Utils.hpp"
#include <unistd.h>
#include <limits.h>
#include <string>
#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

std::string getExecutableDir()
{
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    if (count == -1)
    {
#ifdef __APPLE__
        uint32_t size = PATH_MAX;
        if (_NSGetExecutablePath(result, &size) == 0)
        {
            std::string path(result);
            return path.substr(0, path.find_last_of("/"));
        }
        return "";
#else
        return "";
#endif
    }
    std::string path(result, count);
    return path.substr(0, path.find_last_of("/"));
}