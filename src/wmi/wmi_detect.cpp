#include "persistence.hpp"

bool wmi_detect(void)
{
    std::string cmd =
        "powershell -Command \""
        "$f = Get-WmiObject -Namespace root\\subscription -Class __EventFilter | Where-Object {$_.Name -eq 'PersistFilter'}; "
        "$c = Get-WmiObject -Namespace root\\subscription -Class CommandLineEventConsumer | Where-Object {$_.Name -eq 'PersistConsumer'}; "
        "if ($f -and $c) { exit 0 } else { exit 1 }\"";

    int res = system(cmd.c_str());

    return (res == 0);
}