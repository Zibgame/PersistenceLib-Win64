#include "persistence.hpp"

bool registry_detect(void)
{
    HKEY key;

    if (RegOpenKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0,
        KEY_READ,
        &key) != ERROR_SUCCESS)
        return false;

    LONG res = RegQueryValueExA(key, REG_TAG, NULL, NULL, NULL, NULL);

    RegCloseKey(key);

    return (res == ERROR_SUCCESS);
}