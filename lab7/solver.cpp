#include "solver.h"
#include "utils.h"


void runge_kutta(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save) {

    double k1, k2, k3, k4;

    for (int i = 0; i < x.size()-1; i++) {

        k1 = f(x[i], y[i]);
        k2 = f(x[i] + h/2, y[i] + h/2*k1);
        k3 = f(x[i] + h/2, y[i] + h/2*k2);
        k4 = f(x[i] + h, y[i] + h*k3);

        y.push_back(y[i] + h/6*(k1 + 2*k2 + 2*k3 + k4));
    }

    if (save) {
        to_file(x, "runge_kutta_h" + std::to_string(h), "w");
        to_file(y, "runge_kutta_h" + std::to_string(h), "a");
    }
}


void milne(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save) {
    
    std::vector<double> x_rk = {x[0], x[1], x[2], x[3]};
    runge_kutta(x_rk, y, h, f);

    double y_pred, y_corr;

    for (int i = 3; i < x.size()-1; i++) {
        y_pred = y[i-3] + 4/3 * h * (2*f(x[i-2], y[i-2]) - f(x[i-1], y[i-1]) + 2*f(x[i], y[i]));
        y_corr = y[i - 1] + h/3 * (f(x[i-1], y[i-1]) + 4 * f(x[i], y[i]) + f(x[i+1], y_pred));
        y.push_back(y_corr);
    }

    if (save) {
        to_file(x, "milne_h" + std::to_string(h), "w");
        to_file(y, "milne_h" + std::to_string(h), "a");
    }
}

void runge_kutta_system(std::vector<double> &x, std::vector<double> &y1, std::vector<double> &y2,
                        double h, double (*f1)(double, double), double (*f2)(double, double), bool save) {
    
    double k11, k21, k12, k22, k13, k23, k14, k24;

    for (int i = 0; i < x.size() - 1; i++) {

        k11 = h * f1(y1[i], y2[i]);
        k21 = h * f2(y1[i], y2[i]);
        k12 = h * f1(y1[i] + k11/2, y2[i] + k21/2);
        k22 = h * f2(y1[i] + k11/2, y2[i] + k21/2);
        k13 = h * f1(y1[i] + k12/2, y2[i] + k22/2);
        k23 = h * f2(y1[i] + k12/2, y2[i] + k22/2);
        k14 = h * f1(y1[i] + k13, y2[i] + k23);
        k24 = h * f2(y1[i] + k13, y2[i] + k23);

        y1.push_back(y1[i] +  (k11 + 2*k12 + 2*k13 + k14)/6);
        y2.push_back(y2[i] +  (k21 + 2*k22 + 2*k23 + k24)/6);
    }

        if (save) {
        to_file(x, "runge_kutta_system1_h" + std::to_string(h), "w");
        to_file(y1, "runge_kutta_system1_h" + std::to_string(h), "a");

        to_file(x, "runge_kutta_system2_h" + std::to_string(h), "w");
        to_file(y2, "runge_kutta_system2_h" + std::to_string(h), "a");
    }

}
