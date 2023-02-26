#ifndef METHODS_H
#define METHODS_H

#include <vector>

using namespace std;

vector<double> newton(double x,
              double a,
              double b,
              double (*f)(double),
              double (*df)(double));

vector<double> iterations(double x,
                  double a,
                  double b,
                  double eps,
                  double (*f)(double),
                  double (*df)(double),
                  double (*fi)(double, double, double (*f)(double)),
                  double (*dfi)(double, double, double (*f)(double)));

vector<double> chords(double x,
              double a,
              double b,
              double eps,
              double (*f)(double),
              double (*d2f)(double));

vector<pair<double, double>> iterations_system(double x,
                  double y,
                  double eps,
                  double (*fi1)(double, double),
                  double (*fi2)(double, double));

#endif