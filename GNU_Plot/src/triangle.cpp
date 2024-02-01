#include "../header/geometry.hpp"

void drawTri(struct geoObject go) {
    std::ofstream dataFile("triangle_coordinate.dat");
    std::vector<float> x, y;
    for (int n = 0; n < MAX; ++n) {
        x.push_back(n * go.triangle.b / (MAX - 1));
        y.push_back(( go.triangle.h / go.triangle.b) * x[n]);
        dataFile << x[n] << " " << y[n] << "\n";
    }
    dataFile.close();
}