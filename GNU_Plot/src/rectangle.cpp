#include "../header/geometry.hpp"
#include "../header/filesystem.hpp"

void drawRec(struct geoObject go) {

    dataFilePath /= "data/rectangle_coordinate.dat"; // Append file path with data file name

    std::ofstream dataFile(dataFilePath);
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

    scriptFilePath /= "data/rectangle_script.gnu"; // Append file path with script file name

    std::ofstream scriptFile(scriptFilePath);
    scriptFile << "plot " << dataFilePath <<std::endl;
    scriptFile.close();

    std::string command = "gnuplot -p " + scriptFilePath.string(); // Script to run gnuplot with file path
    system(command.c_str()); // Execute the command
}