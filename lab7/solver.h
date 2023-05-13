#ifndef SOVER_H
#define SOLVER_H

#include <vector>

void runge_kutta(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save=false);

void milne(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save=false);

void runge_kutta_system(std::vector<double> &x, std::vector<double> &y1, std::vector<double> &y2,
                        double h, double (*f1)(double, double), double (*f2)(double, double), bool save);

#endif