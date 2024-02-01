#ifndef FILESYSTEM_HELPER_HPP
#define FILESYSTEM_HELPER_HPP

#include <iostream>
#include <cstdlib>
#include <filesystem>

// Get path the working directory
std::filesystem::path dataFilePath = std::filesystem::current_path();
std::filesystem::path scriptFilePath = std::filesystem::current_path();

#endif