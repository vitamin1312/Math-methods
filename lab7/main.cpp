#include <iostream>
#include <iomanip>
#include "utils.h"
#include "functions.h"
#include "solver.h"

int main() {
    double start = 0;
    double end = 1;

    // std::cout << std::fixed << std::showpoint;
    // std::cout << std::setprecision(20);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Solving of ODE" << std::endl << std::endl;
    std::vector<double> step = {0.1, 0.01, 0.001};

    for (double h : step) {

        std::vector<double> x = get_x(start, end, h);
        std::vector<double> y_correct;
        std::vector<double> y_rk = {6};
        std::vector<double> y_m = {6};
        int idx_end = (end - start) / h;
        int idx_mid = (idx_end) / 2;

        fill_values(x, y_correct, f);
        runge_kutta(x, y_rk, h, df, false);
        milne(x, y_m, h, df, false);
        
        std::cout << "step: " << h << std::endl;
        std::cout << "x = 0.5, y correct: " << y_correct[idx_mid]
                  << "; x = 1, y correct: " << y_correct[idx_end] << ";" << std::endl;
        std::cout << "Runge-Kutta method absolute error in x = "
                  << x[idx_mid] << ", y = " << y_rk[idx_mid]
                  << ": " << absolute_error(y_rk[idx_mid], y_correct[idx_mid]) << std::endl;
        std::cout << "Milne method absolute error in x = "
                  << x[idx_mid] << ", y = " << y_m[idx_mid]
                  << ": " << absolute_error(y_m[idx_mid], y_correct[idx_mid]) << std::endl;
        std::cout << "Runge-Kutta method relative error in x = "
                  << x[idx_mid] << ", y = " << y_rk[idx_mid]
                  << ": " << relative_error(y_rk[idx_mid], y_correct[idx_mid]) << std::endl;
        std::cout << "Milne method relative error in x = "
                  << x[idx_mid] << ", y = " << y_m[idx_mid]
                  << ": " << relative_error(y_m[idx_mid], y_correct[idx_mid]) << std::endl;
        std::cout << std::endl;

        std::cout << "Runge-Kutta method absolute error in x = "
                  << x[idx_end] << ", y = " << y_rk[idx_end]
                  << ": " << absolute_error(y_rk[idx_end], y_correct[idx_end]) << std::endl;
        std::cout << "Milne method absolute error in x = "
                  << x[idx_end] << ", y = " << y_m[idx_end]
                  << ": " << absolute_error(y_m[idx_end], y_correct[idx_end]) << std::endl;
        std::cout << "Runge-Kutta method relative error in x = "
                  << x[idx_end] << ", y = " << y_rk[idx_end]
                  << ": " << relative_error(y_rk[idx_end], y_correct[idx_end]) << std::endl;
        std::cout << "Milne method relative error in x = "
                  << x[idx_end] << ", y = " << y_m[idx_end]
                  << ": " << relative_error(y_m[idx_end], y_correct[idx_end]) << std::endl;
        std::cout << std::endl;
    }
    

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl << std::endl << "Solving of ODE system" << std::endl << std::endl;

    double h = 0.1;
    int idx_end = (end - start) / h;
    std::vector<double> x = get_x(start, end, h);
    std::vector<double> y1_correct;
    std::vector<double> y2_correct;
    std::vector<double> y1 = {-2};
    std::vector<double> y2 = {0};

    fill_values(x, y1_correct, f1);
    fill_values(x, y2_correct, f2);
    runge_kutta_system(x, y1, y2, h, df1, df2, true);

    std::cout << "x = 1, y1 correct: " << y1_correct[idx_end]
              << ", y2 correct: " << y2_correct[idx_end] << ";" << std::endl;

    std::cout << "Runge-Kutta method absolute error for f1 in x = "
                  << x[idx_end] << " y = " << y1[idx_end] << " : " 
                  << absolute_error(y1[idx_end], y1_correct[idx_end]) << std::endl;
    std::cout << "Runge-Kutta method relative error for f1 in x = "
                  << x[idx_end] << " y = " << y1[idx_end] << " : " 
                  << relative_error(y1[idx_end], y1_correct[idx_end]) << std::endl;
    std::cout << "Runge-Kutta method absolute error for f2 in x = "
                  << x[idx_end] << " y = " << y2[idx_end] << " : " 
                  << absolute_error(y2[idx_end], y2_correct[idx_end]) << std::endl;
    std::cout << "Runge-Kutta method relative error for f2 in x = "
                  << x[idx_end] << " y = " << y2[idx_end] << " : " 
                  << relative_error(y2[idx_end], y2_correct[idx_end]) << std::endl;


    return 0;
}
