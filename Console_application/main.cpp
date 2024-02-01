#include "header/geometry.hpp"
#include <iostream>

// Using typedef to create a type alias for a function pointer
typedef void(*AreaFunc) (struct geoObject);

// Array of function pointer
AreaFunc AreaArray[] = {areaCir, areaElli, areaRec, areaSqu, areaTri};

// Other possible way to define AreaFunc would be using AreaFunc = void(*)(struct geoObject):
// instead of 2 lines of code you could do the same in 1 line

int main(){
    
    struct geoObject go;
    int i;
    std::cout<<"To find area of different 2D shapes\n"<<std::endl;
    std::cout<<"1.Circle\n2.Ellipse\n3.Rectangle\n4.Square\n5.Triangle\n"<<std::endl;
    std::cin>>i;

    switch (i)
    {
    case 1:
        go.gCode = go.CIRCLE; // improves readability
        std::cout<<"Enter radius:\t"<<std::endl;
        std::cin>>go.circle.r;
        AreaArray[go.gCode](go);
        // calling function areaCircle with struct as an input (containg varaible r)
        break;
    
    case 2:
        go.gCode = go.ELLIPSE;
        std::cout<<"Enter Semi-major axis:\t"<<std::endl;
        std::cin>>go.ellipse.a;
        std::cout<<"Enter Semi-minor axis:\t"<<std::endl;
        std::cin>>go.ellipse.b;
        AreaArray[go.gCode](go);
        break;
    
    case 3:
        go.gCode = go.RECTANGLE;
        std::cout<<"Enter Length:\t"<<std::endl;
        std::cin>>go.rectangle.l;
        std::cout<<"Enter breadth:\t"<<std::endl;
        std::cin>>go.rectangle.w;
        AreaArray[go.gCode](go);
        break;

    case 4:
        go.gCode = go.SQUARE;
        std::cout<<"Enter side:\t"<<std::endl;
        std::cin>>go.square.s;
        AreaArray[go.gCode](go);
        break;

    case 5:
        go.gCode = go.TRIANGLE;
        std::cout<<"Enter base:\t"<<std::endl;
        std::cin>>go.triangle.b;
        std::cout<<"Enter height:\t"<<std::endl;
        std::cin>>go.triangle.h;
        AreaArray[go.gCode](go);
        break;

    default:
        break;
    }


    return 0;
}