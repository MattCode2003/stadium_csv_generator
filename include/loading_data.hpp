#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct university
{
    std::string name;
    std::string code;
    std::string full_name;
};

inline std::unordered_map<std::string, university>uni_lookup;


void load_universities(const std::string& file_name);
std::vector<std::string> parse_csv_line(const std::string& line);