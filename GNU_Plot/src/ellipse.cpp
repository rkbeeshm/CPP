#include <cmath>
#include "../header/geometry.hpp"
#include "../header/filesystem.hpp"

void drawElli(struct geoObject go) {

    dataFilePath /= "data/ellipse_coordinate.dat"; // Append file path with data file name

    std::ofstream dataFile(dataFilePath);
    std::vector<float> x, y;
    for (int n = 0; n <= MAX; n++ ){
        x.push_back(go.ellipse.a*cos(n));
        y.push_back(go.ellipse.b*sin(n));
        dataFile << x[n] << " " << y[n] <<std::endl;
    }
    dataFile.close();

    scriptFilePath /= "data/ellipse_script.gnu"; // Append file path with script file name

    std::ofstream scriptFile(scriptFilePath);
    scriptFile << "plot " << dataFilePath <<std::endl;
    scriptFile.close();

    std::string command = "gnuplot -p " + scriptFilePath.string(); // Script to run gnuplot with file path
    system(command.c_str()); // Execute the command
}