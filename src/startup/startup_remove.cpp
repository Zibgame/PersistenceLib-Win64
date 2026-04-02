#include "persistence.hpp"
#include <cstdlib>
#include <shlobj.h>

static std::string get_startup_path(void)
{
    char path[MAX_PATH];

    SHGetFolderPathA(NULL, CSIDL_STARTUP, NULL, 0, path);

    return std::string(path);
}

bool startup_remove(void)
{
    std::string startup = get_startup_path();
    std::string link = startup + "\\PERSIST_LIB.lnk";

    return (DeleteFileA(link.c_str()) != 0);
}