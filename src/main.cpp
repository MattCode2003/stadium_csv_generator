#include <iostream>
#include <string>
//#include <OpenXLSX.hpp>
#include "../include/loading_data.hpp"

int main();
void main_menu();


// Deals with main menu user inputs
int main()
{
    int user_selection = 0;

    while (user_selection != 3)
    {
        main_menu();
        if (!(std::cin >> user_selection))
        {
            std::cout << "\nInvalid input. Please enter a number between 1 and 3\n";
        }

        switch (user_selection)
        {
            case 1:
            {
                std::cout << "dsifohdioshg";
            }
            break;
            
            case 2:
            {
                std::cout << "dsifohdioshg";
            }
            break;
            
            default:
            {
                std::cout << "\n";
                break;
            }
        }
    }
    load_universities("data/uni_codes.csv");

    std::cout << uni_lookup["Oxford"].code << "\n";
}



void main_menu()
{
    std::cout << "\n==============================\n";
    std::cout << "      Create Stadium CSV        \n";
    std::cout << "==============================\n";
    std::cout << "1. BUCS Induviduals\n";
    std::cout << "2. TTE Event\n";
    std::cout << "3. Exit\n";
    std::cout << "Selection: ";
}