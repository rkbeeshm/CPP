#include "../header/geometry.hpp"

void drawSqu(struct geoObject go) {
    std::ofstream dataFile("triangle_coordinate.dat");
    std::stack<float> x, y;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            x.push(i * go.square.s / (MAX - 1));
            y.push(j * go.square.s / (MAX - 1));
        }
    }
    while(!x.empty() && !y.empty()){
        dataFile << x.top() << " " << y.top() << "\n";
        x.pop();
        y.pop();
    }
    dataFile.close();
}