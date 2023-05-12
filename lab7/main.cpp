#include <iostream>
#include "utils.h"
#include "functions.h"
#include "solver.h"

int main() {
    double start = 0;
    double end = 1;
    std::vector<double> step = {0.1, 0.01, 0.001};

    for (double h : step) {

        std::vector<double> x = get_x(start, end, h);
        std::vector<double> y_correct;
        std::vector<double> y = {6};

        fill_values(x, y_correct, f);
        milne(x, y, h, df);
        
        std::cout << "step: " << h << std::endl;
        // std::cout << "correct values: " << y_correct << std::endl;
        // std::cout << "founded values: " << y << std::endl;
    }
    



    return 0;
}