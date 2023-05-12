#include "solver.h"
#include "utils.h"


void runge_kutta(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save=false) {

    double k1, k2, k3, k4;

    for (int i = 0; i < x.size()-1; i++) {

        k1 = f(x[i], y[i]);
        k2 = f(x[i] + h/2, y[i] + h/2*k1);
        k3 = f(x[i] + h/2, y[i] + h/2*k2);
        k4 = f(x[i] + h, y[i] + h*k3);

        y.push_back(y[i] + h/6*(k1 + 2*k2 + 2*k3 + k4));
    }
}


void milne(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save=false) {
    
    std::vector<double> x_rk = {x[0], x[1], x[2], x[3]};
    runge_kutta(x_rk, y, h, f);

    double y_pred, y_corr;

    for (int i = 3; i < x.size()-1; i++) {
        y_pred = y[i-4] + 4/3 * h * (2*f(x[i-3], y[i-3]) - f(x[i-2], y[i-2]) + 2*f(x[i-1], y[i-1]));
        y_corr = y[i - 2] + h/3 * (f(x[i-2], y[i-2]) + 4 * f(x[i-1], y[i-1]) + f(x[i], y_pred));
        y.push_back(y_corr);
    }

        if (save) {
        to_file(x, "milne_h" + std::to_string(h), "w");
        to_file(y, "milne_h" + std::to_string(h), "a");
    }

}