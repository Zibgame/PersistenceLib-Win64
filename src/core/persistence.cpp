#include "persistence.hpp"

bool persist_install(PersistType type, const std::string& path)
{
    if (type == REGISTRY && !registry_detect())
    {
        return (registry_install(path));
    }
    if (type == WMI)
    {
        return (wmi_install(path));
    }
    return (false);
}

bool persist_detect(PersistType type)
{
    if (type == REGISTRY)
    {
        return (registry_detect());
    }
    if (type == WMI)
    {
        return (wmi_detect());
    }
    return (false);
}

bool persist_remove(PersistType type)
{
    if (type == REGISTRY)
    {
        return (registry_remove());
    }
    if (type == WMI)
    {
        return (wmi_remove());
    }
    return (false);
}