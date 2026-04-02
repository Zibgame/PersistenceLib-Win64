#pragma once

#include <string>
#include <iostream>
#include <windows.h>

enum PersistType
{
    REGISTRY
};  

bool persist_install(PersistType type, const std::string& path);
bool persist_detect(PersistType type);
bool persist_remove(PersistType type);
std::string get_self_path(void);

#define REG_TAG "PERSIST_LIB"
bool registry_install(const std::string& path);
bool registry_remove(void);
bool registry_detect(void);