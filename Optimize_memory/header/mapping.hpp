#ifndef MAPPING_HPP
#define MAPPING_HPP

#include <iostream>
#include <tuple>

struct Vertex
{
    double x, y, z;

    // "custom sorting function for std::map " if this is not done, map would do O(n) for each comparison
    // in simple term you could just use for-loop  
    bool operator<(const Vertex& existingPoint) const{
        return std::tie(x, y, z) < std::tie(existingPoint.x, existingPoint.y, existingPoint.z);
        
        // two tuples are used to sort the points in lexicographic order
        // https://www.youtube.com/watch?v=-qx6fbRMUbk
        // https://www.codespeedy.com/how-to-create-custom-comparator-for-map-in-c/
        // https://www.geeksforgeeks.org/tuples-in-c/
    }

    // "custom compartor (equality function) for std::map"
    bool operator==(const Vertex& existingPoint) const {
        return x == existingPoint.x && y == existingPoint.y && z == existingPoint.z;
        
    }
};

struct Triangle {
    int normalVectorIndex;
    int vertex1Index, vertex2Index, vertex3Index;
};

#endif 