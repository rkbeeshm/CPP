#include "../header/readSTLfile.hpp"
#include "../header/mapping.hpp"
#include "../header/getSTLsection.hpp"

std::vector<Triangle> readSTLfile(const std::string& filePath, std::vector<Vertex>& vertices, std::map<Vertex, int>& vertexMap){

    std::ifstream file(filePath);
    if (!file.is_open()){
        std::cerr << "Error opening file:" << filePath << std::endl;
        return {};
    }
    
    std::string line;
    std::vector<Triangle> triangles;                            

    bool insideSolid = false;
    bool insideFacet = false;
    STLSection currentSection = STLSection::UNKNOWN;

    while (std::getline(file, line)){
        currentSection = getSTLsection(line);
        
        Triangle triangle;
        Vertex normal, vertex;

        switch (currentSection)
        {
        case STLSection::FACET_NORMAL: {

            // parsing normal vector
            if (sscanf(line.c_str(), "  facet normal %lf %lf %lf", &normal.x, &normal.y, &normal.z) != 3) {
                    std::cerr << "Error parsing normal vector." << std::endl;
                    return {};
                }

            auto normalIt = vertexMap.find(normal);
            if (normalIt != vertexMap.end()) {
                triangle.normalVectorIndex = normalIt->second;
            } else {
                vertexMap.emplace(normal, vertices.size());
                triangle.normalVectorIndex = vertices.size();
                vertices.push_back(normal);
            }

            break; // getout of case
        }
        case STLSection::OUTER_LOOP: {

            for (int i = 0; i < 3; ++i){
                std::getline(file, line);

                if (sscanf(line.c_str(), "          vertex %lf %lf %lf", &vertex.x, &vertex.y, &vertex.z) != 3) {
                    std::cerr << "Error parsing vertex vector." << std::endl;
                    return {};
                }

                auto vertexIt = vertexMap.find(vertex);
                if (vertexIt != vertexMap.end()) {
                    if (i == 0) triangle.vertex1Index = vertexIt->second;
                    else if (i == 1) triangle.vertex2Index = vertexIt->second;
                    else triangle.vertex3Index = vertexIt->second;
                } else {
                    vertexMap.emplace(vertex, vertices.size());

                    if (i == 0) triangle.vertex1Index = vertices.size();
                    else if (i == 1) triangle.vertex2Index = vertices.size();
                    else triangle.vertex3Index = vertices.size();

                    vertices.push_back(vertex); // vector<Vertex> will store unique vertex
                }
            }

            break; // getout of case
        }
        case STLSection::ENDLOOP: {

            triangles.push_back(triangle); // vector<Triangle> will store index for each vertex and normal 
            break;
        }
        case STLSection::UNKNOWN: {
            // skipping unwanted lines such as solid, end facet, end solid.
            break;
        }
        }

    }
    file.close();
    return triangles;
}