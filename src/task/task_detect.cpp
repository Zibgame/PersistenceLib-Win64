#include "persistence.hpp"
#include <cstdlib>

bool task_detect(void)
{
    std::string cmd =
        "schtasks /query /tn \"" TASK_NAME "\" >nul 2>&1";

    int res = system(cmd.c_str());

    return (res == 0);
}