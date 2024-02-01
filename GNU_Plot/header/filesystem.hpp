#ifndef FILESYSTEM_HELPER_HPP
#define FILESYSTEM_HELPER_HPP

#include <iostream>
#include <cstdlib>
#include <filesystem>

// Get path of the current working directory
extern std::filesystem::path dataFilePath;
extern std::filesystem::path scriptFilePath;

/*
multiple definition of 'currentFilePath[abi:cxx11]'" indicates that there is a conflict 
with the definition of the variable currentFilePath. 
This usually happens when the same variable is defined in multiple source files!
*/
//std::filesystem::path currentFilePath = std::filesystem::current_path();

#endif