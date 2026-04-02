#include "persistence.hpp"
#include <iostream>
#include <windows.h>

static void clear_input(void)
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

static PersistType choose_type(void)
{
    int t;

    while (1)
    {
        std::cout << "\nPersistence type:\n";
        std::cout << "1. Registry\n";
        std::cout << "2. WMI\n";
        std::cout << "3. Task\n";
        std::cout << "4. Startup\n";
        std::cout << "> ";

        if (!(std::cin >> t))
        {
            clear_input();
            continue;
        }

        if (t == 1)
            return REGISTRY;
        if (t == 2)
            return WMI;
        if (t == 3)
            return TASK;
        if (t == 4)
            return STARTUP;
    }
}

static const char *type_to_str(PersistType type)
{
    if (type == REGISTRY)
        return "Registry";
    if (type == WMI)
        return "WMI";
    if (type == TASK)
        return "Task";
    if (type == STARTUP)
        return "Startup";
    return "Unknown";
}

int main(void)
{
    std::string path = get_self_path();

    while (1)
    {
        int choice;
        PersistType type;

        std::cout << "\n=============================\n";
        std::cout << "PATH: " << path << "\n";
        std::cout << "=============================\n";

        std::cout << "\n1. install\n";
        std::cout << "2. detect\n";
        std::cout << "3. remove\n";
        std::cout << "4. exit\n";
        std::cout << "> ";

        if (!(std::cin >> choice))
        {
            clear_input();
            continue;
        }

        if (choice == 4)
            break;

        type = choose_type();

        std::cout << "\n[+] Using: " << type_to_str(type) << "\n";

        if (choice == 1)
        {
            if (persist_install(type, path))
                std::cout << "[OK] installed\n";
            else
                std::cout << "[FAIL] install\n";
        }
        else if (choice == 2)
        {
            if (persist_detect(type))
                std::cout << "[OK] detected\n";
            else
                std::cout << "[--] not found\n";
        }
        else if (choice == 3)
        {
            if (persist_remove(type))
                std::cout << "[OK] removed\n";
            else
                std::cout << "[FAIL] remove\n";
        }

        Sleep(500);
    }

    return (0);
}