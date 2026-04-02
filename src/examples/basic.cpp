#include "persistence.hpp"
#include <iostream>
#include <windows.h>

int main(void)
{
    std::string path = get_self_path();

    while (1)
    {
        int choice;
        std::cout << path << std::endl;

        std::cout << "\n1. install\n";
        std::cout << "2. detect\n";
        std::cout << "3. remove\n";
        std::cout << "> ";
        std::cin >> choice;

        if (choice == 1)
        {
            if (persist_install(REGISTRY, path))
                std::cout << "installed\n";
            else
                std::cout << "fail\n";
        }
        else if (choice == 2)
        {
            if (persist_detect(REGISTRY))
                std::cout << "detected\n";
            else
                std::cout << "not found\n";
        }
        else if (choice == 3)
        {
            if (persist_remove(REGISTRY))
                std::cout << "removed\n";
            else
                std::cout << "fail\n";
        }

        Sleep(500);
    }

    return 0;
}