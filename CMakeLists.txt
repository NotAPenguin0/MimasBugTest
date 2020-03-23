cmake_minimum_required(VERSION 3.12)

project(Bug)

add_subdirectory(mimas)

add_executable(App main.cpp file_dialog.cpp)
target_compile_options(App PUBLIC -std=c++17)
target_link_libraries(App PUBLIC mimas shlwapi.lib propsys.lib)
target_include_directories(App PUBLIC mimas/public)