//#include "../header/rectangle.hpp"
/*
// function to compute area of rectangle
float rectangle::rectangle_area(float l, float b){
    length = l;
    breadth = b;
    return (length*length);    
}
*/

#include "../header/geometry.hpp"
#include <iostream>

void areaRec(struct geoObject go) {
    std::cout<<"Area is:\t"<<go.rectangle.l * go.rectangle.w<<std::endl;
}