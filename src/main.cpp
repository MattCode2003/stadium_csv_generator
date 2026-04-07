#include <iostream>
#include <string>
#include "../include/bucs.hpp"

int main();


// Deals with main menu user inputs
int main()
{
    int user_selection = 0;

    while (user_selection != 3)
    {
        std::cout << "\n==============================\n";
        std::cout << "      Create Stadium CSV        \n";
        std::cout << "==============================\n";
        std::cout << "1. BUCS Induviduals\n";
        std::cout << "2. TTE Event\n";
        std::cout << "3. Exit\n";
        std::cout << "Selection: ";
        
        if (!(std::cin >> user_selection))
        {
            std::cout << "\n[Error] Please enter a valid number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (user_selection)
        {
            case 1:
            {
                bucs_menu();
            }
            break;
            
            case 2:
            {
                std::cout << "Not Implemented";
            }
            break;

            case 3:
                {
                    return 0;
                }
            
            default:
            {
                std::cout << "\nChoice " << user_selection << " is not a valid choice";
                break;
            }
        }
    }
}
