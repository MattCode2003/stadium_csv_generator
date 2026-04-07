#include <iostream>

void bucs_menu()
{
    int user_selection = 0;
    std::cout << "\n\n";

    while (user_selection != 3)
    {
        std::cout << "\n==============================\n";
        std::cout << "          BUCS Events         \n";
        std::cout << "==============================\n";
        std::cout << "1. Player Rankings\n";
        std::cout << "2. Create CSV\n";
        std::cout << "3. Back\n";
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
                std::cout << "you chose 1";
                break;
            
            case 2:
                std::cout << "you chose 2";
                break;

            case 3:
                return;
            
            default:
                std::cout << "\nChoice " << user_selection << " is not a valid choice";
                break;
        }
    }
}