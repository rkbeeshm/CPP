//#include "../header/square.hpp"
/*
// function to compute area of square
float square::square_area(float l){
    length = l;
    return (length*length);    
}
*/

#include "../header/geometry.hpp"
#include <iostream>

void areaSqu(struct geoObject go) {
    std::cout<<"Area is:\t"<<go.square.s*go.square.s<<std::endl;
}