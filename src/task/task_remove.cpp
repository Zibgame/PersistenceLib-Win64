#include "persistence.hpp"
#include <cstdlib>

bool task_remove(void)
{
    std::string cmd =
        "schtasks /delete /tn \"" TASK_NAME "\" /f >nul 2>&1";

    int res = system(cmd.c_str());

    return (res == 0);
}