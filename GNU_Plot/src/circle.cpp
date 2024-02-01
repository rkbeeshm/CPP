#include <cmath>
#include "../header/geometry.hpp"

void drawCir(struct geoObject go) {
    std::ofstream dataFile("circle_coordinate.dat");
    std::vector<float> x, y;
    for (int n = 0; n <= MAX; n++ ){
        x.push_back(go.circle.r*cos(n));
        y.push_back(go.circle.r*sin(n));
        dataFile << x[n] << " " << y[n] <<std::endl;
    }
    dataFile.close();
}