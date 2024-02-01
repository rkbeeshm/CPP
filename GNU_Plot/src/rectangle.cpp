#include "../header/geometry.hpp"

void drawRec(struct geoObject go) {
    std::ofstream dataFile("rectangle_coordinate.dat");
    std::stack<float> x, y;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            x.push(i * go.rectangle.l / (MAX - 1));
            y.push(j * go.rectangle.w / (MAX - 1));
        }
    }
    while(!x.empty() && !y.empty()){
        dataFile << x.top() << " " << y.top() <<std::endl;
        x.pop();
        y.pop();
    }
    dataFile.close();
}