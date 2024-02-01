#include <cmath>
#include "../header/geometry.hpp"

void drawElli(struct geoObject go) {
    std::ofstream dataFile("ellipse_coordinate.dat");
    std::vector<float> x, y;
    for (int n = 0; n <= MAX; n++ ){
        x.push_back(go.ellipse.a*cos(n));
        y.push_back(go.ellipse.b*sin(n));
        dataFile << x[n] << " " << y[n] <<std::endl;
    }
    dataFile.close();
}