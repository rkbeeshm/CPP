//#include "../header/triangle.hpp"
/*
// function to compute area of triangle
float triangle::triangle_area(float l, float b){
    base = l;
    height = b;
    return (0.5*base*height);    
}
*/

#include "../header/geometry.hpp"
#include <iostream>

void areaTri(struct geoObject go) {
    std::cout<<"Area is:\t"<<0.5 * go.triangle.b * go.triangle.h<<std::endl;
}