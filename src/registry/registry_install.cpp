#include "persistence.hpp"

bool registry_install(const std::string& path)
{
    LONG res = RegSetKeyValueA(
        HKEY_CURRENT_USER,
        "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        REG_TAG,
        REG_SZ,
        path.c_str(),
        path.size() + 1);

    return (res == ERROR_SUCCESS);
}