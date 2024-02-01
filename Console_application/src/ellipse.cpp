//#include "../header/ellipse.hpp"
#include <math.h>

/*
// function to compute area of ellipse
float ellipse::ellipse_area(float a, float b){
    SMaj_axis = a;
    SMin_axis = b;
    return (M_PI*SMaj_axis*SMin_axis);    
}
*/

#include "../header/geometry.hpp"
#include <iostream>

void areaElli(struct geoObject go) {
    std::cout<<"Area is:\t"<<M_PI * go.ellipse.a * go.ellipse.b<<std::endl;
}