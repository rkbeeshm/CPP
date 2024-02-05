#include "header/readSTLfile.hpp"
#include "header/mapping.hpp"
#include "header/getSTLsection.hpp"
#include <filesystem>

int main() {

    std::filesystem::path filePath;
    std::vector<Vertex> vertices;
    std::map<Vertex, int> vertexMap;

    std::cout << "Enter your file path to the STL file: " << std::endl;
    std::cin >> filePath;

    std::vector<Triangle> triangles = readSTLfile(filePath, vertices, vertexMap);

    std::cout << "Number of unique vertices: " << vertices.size() << std::endl;
    std::cout << "Number of triangles: " << triangles.size() << std::endl;
    
    return 0;
} 

