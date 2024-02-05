#ifndef READSTLFILE_HPP
#define READSTLFILE_HPP

#include "mapping.hpp"
#include <fstream>
#include <vector>
#include <map>
#include <string>

std::vector<Triangle> readSTLfile(const std::string& , std::vector<Vertex>& , std::map<Vertex, int>&);

#endif