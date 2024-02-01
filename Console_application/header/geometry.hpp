#ifndef geometry_HPP
#define geometry_HPP

struct geoObject
{
    // you could skip enum by directly inputting [i-1]
    // AreaFunc AreaArray[] = {areaCir, areaElli, areaRec, areaSqu, areaTri};
    // however for very large code figuring out what i-1 points to becomes a
    // tedious task rather you could just input gCode.CIRCLE for better readablility  
    enum {CIRCLE = 0, ELLIPSE, RECTANGLE, SQUARE, TRIANGLE} gCode ; 
    
    // we woudn't know what the user might select hence allocating memory for
    // all variable before hand seems to be an unwanted wastage of memory
    // therefore union (philosophy is to write scalable codes) 
    union 
    {
        struct {float r; } circle;
        struct {float a, b; } ellipse;
        struct {float l, w; } rectangle;
        struct {float s; } square;
        struct {float b, h ;} triangle;
    };
    
};

// declare function
void areaCir(struct geoObject);
void areaElli(struct geoObject);
void areaRec(struct geoObject);
void areaSqu(struct geoObject);
void areaTri(struct geoObject);

#endif