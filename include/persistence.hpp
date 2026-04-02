#pragma once

#include <string>
#include <iostream>
#include <windows.h>

enum PersistType
{
    REGISTRY,
    WMI // Windows Management Instrumentation
};  

bool persist_install(PersistType type, const std::string& path);
bool persist_detect(PersistType type);
bool persist_remove(PersistType type);
std::string get_self_path(void);

#define REG_TAG "PERSIST_LIB"
bool registry_install(const std::string& path);
bool registry_remove(void);
bool registry_detect(void);

bool wmi_install(const std::string& path);
bool wmi_remove(void);
bool wmi_detect(void);