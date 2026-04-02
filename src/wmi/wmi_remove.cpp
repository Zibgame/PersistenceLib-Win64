#include "persistence.hpp"

bool wmi_remove(void)
{
    std::string cmd =
        "powershell -Command \""
        
        "$f = Get-WmiObject -Namespace root\\subscription -Class __EventFilter "
        "| Where-Object {$_.Name -eq 'PersistFilter'}; "
        
        "$c = Get-WmiObject -Namespace root\\subscription -Class CommandLineEventConsumer "
        "| Where-Object {$_.Name -eq 'PersistConsumer'}; "
        
        "$b = Get-WmiObject -Namespace root\\subscription -Class __FilterToConsumerBinding "
        "| Where-Object {$_.Filter -like '*PersistFilter*'}; "
        
        "if ($b) { $b | Remove-WmiObject }; "
        "if ($c) { $c | Remove-WmiObject }; "
        "if ($f) { $f | Remove-WmiObject }; "
        
        "exit 0\"";

    int res = system(cmd.c_str());

    return (res == 0);
}