#include <iostream>
#include <fstream>
#include "../include/loading_data.hpp"


// Creates the university lookup for the unis
void load_universities(const std::string& file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cerr << "Faild to open file \n";
        return;
    }

    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line))
    {
        auto fields = parse_csv_line(line);

        if (fields.size() < 3)
            continue;
        
        university uni;
        uni.name = fields[0];
        uni.code = fields[1];
        uni.full_name = fields[2];

        uni_lookup[uni.name] = uni;
    }

    return;
}


// handles values that contain "," in them
std::vector<std::string> parse_csv_line(const std::string& line)
{
    std::vector<std::string> result;
    std::string current;
    bool in_quotes = false;

    for (size_t i = 0; i < line.size(); ++i)
    {
        char c = line[i];
        
        if (c == '"')
        {
            if (in_quotes && i + 1 < line.size() && line[i + 1] == '"')
            {
                current += '"';
                ++i;
            }
            else
                in_quotes = !in_quotes;
        }

        else if (c == ',' && !in_quotes)
        {
            result.push_back(current);
            current.clear();
        }
        else
            current += c;
    }

    result.push_back(current);
    return result;
}