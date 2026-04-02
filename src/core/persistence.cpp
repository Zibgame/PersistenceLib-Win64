#include "persistence.hpp"

bool persist_install(PersistType type, const std::string& path)
{
    if (type == REGISTRY && !registry_detect())
    {
        return (registry_install(path));
    }
    return (false);
}

bool persist_detect(PersistType type)
{
    if (type == REGISTRY)
    {
        return (registry_detect());
    }
    return (false);
}

bool persist_remove(PersistType type)
{
    if (type == REGISTRY)
    {
        return (registry_remove());
    }
    return (false);
}