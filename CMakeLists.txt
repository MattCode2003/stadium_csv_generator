cmake_minimum_required(VERSION 4.3)
project(Stadium)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. CREATE the target first
add_executable(stadium 
    src/main.cpp
    src/loading_data.cpp
)

# 2. APPLY settings to the target (Must use 'stadium' lowercase to match)
target_include_directories(stadium PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 3. LINK libraries
find_package(OpenXLSX REQUIRED)
target_link_libraries(stadium PRIVATE OpenXLSX::OpenXLSX)