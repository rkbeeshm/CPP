#include "../header/geometry.hpp"
#include "../header/filesystem.hpp"

void drawTri(struct geoObject go) {

    dataFilePath /= "data/triangle_coordinate.dat"; // Append file path with data file name

    std::ofstream dataFile(dataFilePath);
    std::vector<float> x, y;
    for (int n = 0; n < MAX; ++n) {
        x.push_back(n * go.triangle.b / (MAX - 1));
        y.push_back(( go.triangle.h / go.triangle.b) * x[n]);
        dataFile << x[n] << " " << y[n] <<std::endl;
    }
    dataFile << go.triangle.b << " " << 0 <<std::endl;
    dataFile << 0 << " " << 0 <<std::endl;
    dataFile.close();

    scriptFilePath /= "data/triangle_script.gnu"; // Append file path with script file name

    std::ofstream scriptFile(scriptFilePath);
    scriptFile << "plot " << dataFilePath << "with lines" <<std::endl;
    scriptFile.close();

    std::string command = "gnuplot -p " + scriptFilePath.string(); // Script to run gnuplot with file path
    system(command.c_str()); // Execute the command
}