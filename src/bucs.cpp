#include "bucs.hpp"
#include <iostream>
#include "../include/loading_data.hpp"
#include <nfd.hpp>


// menu
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
                std::cout << "NOT Implemented";
                break;
            
            case 2:
            {
                std::string file_path = pick_file();
                std::cout << file_path;
                break;
            }

            case 3:
                return;
            
            default:
                std::cout << "\nChoice " << user_selection << " is not a valid choice";
                break;
        }
    }
}


// Opens gui to get file path of selected
std::string pick_file()
{
    NFD::Init();
    NFD::UniquePath out_path;
    nfdfilteritem_t filter_item[1] = { {"Excel Files", "xlsx"} };

    nfdresult_t result = NFD::OpenDialog(out_path, filter_item, 1);

    if (result == NFD_OKAY)
    {
        std::string path = out_path.get();
        NFD::Quit();
        return path;
    }

    NFD::Quit();
    return "";

}