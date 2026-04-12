#include "bucs.hpp"
#include <iostream>
#include "../include/loading_data.hpp"
#include <nfd.hpp>
#include <OpenXLSX.hpp>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;


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
                bucs_excel_to_csv();
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


void bucs_excel_to_csv()
{
    // Gets file path
    std::cout << "Select your player .xlsx file\n";
    std::string player_excel_path = pick_file();

    // Error handling
    if (player_excel_path == "")
    {
        std::cout << "[Error] No file was selected.\n";
        return;
    }

    // Gets player info and stores them in struct
    get_players(player_excel_path);

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


// Get player info and store in struct
void get_players(std::string file_path)
{
    // Checks if the file is password protected or not
    OpenXLSX::XLDocument doc;
    int password_required = 0;
    const fs::path temp_file_location = fs::temp_directory_path();
    const std::string file_name = "players.xlsx";
    
    try
    {
        doc.open(file_path);
    }

    // file is encrypted and needs password
    catch (const std::exception& e)
    {
        fs::path exe_path;
        std::string password;

        #if defined(_WIN32)
            exe_path = fs::current_path() / "excel_decryption_win.exe";
        #elif defined(__APPLE__)
            exe_path = fs::current_path() / "excel_decryption_mac";
        #elif defined(__linux__)
            exe_path = fs::current_path() / "excel_decryption_linux";
        #endif

        std::cout << "Enter Password: ";
        std::cin >> password;

        std::string command = " \" \"" + exe_path.string() + "\" " +
                      "\"" + file_path + "\" " +
                      "\"" + password + "\" " +
                      "\"" + (temp_file_location / "players.xlsx").string() + "\" \" ";
        
        std::system(command.c_str());

        doc.open((temp_file_location / "players.xlsx").string());
    }

    // Gets all player info
    auto wks = doc.workbook().worksheet(1);

    uint32_t row_count = wks.rowCount();
    uint32_t col_count = wks.columnCount();

}