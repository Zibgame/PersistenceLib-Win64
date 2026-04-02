#include "persistence.hpp"
#include <iostream>
#include <windows.h>

std::string get_self_path(void)
{
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    return std::string(buffer);
}