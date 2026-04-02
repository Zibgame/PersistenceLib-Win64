#include "persistence.hpp"

bool registry_remove(void)
{
    HKEY key;

    if (RegOpenKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0,
        KEY_SET_VALUE,
        &key) != ERROR_SUCCESS)
        return false;

    LONG res = RegDeleteValueA(key, REG_TAG);

    if (res != ERROR_SUCCESS && res != ERROR_FILE_NOT_FOUND)
    {
        RegCloseKey(key);
        return false;
    }

    RegCloseKey(key);
    return true;
}