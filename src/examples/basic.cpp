#include "persistence.hpp"
#include <iostream>
#include <windows.h>

static PersistType choose_type(void)
{
    int t;

    std::cout << "\nPersistence type:\n";
    std::cout << "1. Registry\n";
    std::cout << "2. WMI\n";
    std::cout << "> ";
    std::cin >> t;

    if (t == 2)
        return WMI;
    return REGISTRY;
}

int main(void)
{
    std::string path = get_self_path();

    while (1)
    {
        int choice;
        PersistType type;

        std::cout << "\nPATH: " << path << "\n";

        std::cout << "\n1. install\n";
        std::cout << "2. detect\n";
        std::cout << "3. remove\n";
        std::cout << "4. exit\n";
        std::cout << "> ";
        std::cin >> choice;

        if (choice == 4)
            break;

        type = choose_type();

        if (choice == 1)
        {
            if (persist_install(type, path))
                std::cout << "installed\n";
            else
                std::cout << "fail\n";
        }
        else if (choice == 2)
        {
            if (persist_detect(type))
                std::cout << "detected\n";
            else
                std::cout << "not found\n";
        }
        else if (choice == 3)
        {
            if (persist_remove(type))
                std::cout << "removed\n";
            else
                std::cout << "fail\n";
        }

        Sleep(500);
    }

    return (0);
}