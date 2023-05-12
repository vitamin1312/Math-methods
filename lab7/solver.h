#ifndef SOVER_H
#define SOLVER_H

#include <vector>

void runge_kutta(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save=false) ;

void milne(std::vector<double> &x, std::vector<double> &y,
                 double h, double (*f)(double, double), bool save=false);

#endif