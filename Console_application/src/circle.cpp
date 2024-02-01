//#include "../header/circle.hpp"
#include <math.h>

/*
// function to compute area of circle
float circle::circle_area(float r){
    radius = r;
    return (M_PI*r*r);    
}
*/

#include "../header/geometry.hpp"
#include <iostream>

void areaCir(struct geoObject go) {
    std::cout<<"Area is:\t"<<M_PI * go.circle.r * go.circle.r<<std::endl;
}