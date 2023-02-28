
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

double find_m(double a, double b, double n, double (*f)(double));

double find_M(double a, double b, double n, double (*f)(double));

double find_M(double a,
              double b,
              double n,
              double alpha,
              double (*f)(double),
              double (*fi)(double, double, double (*f)(double)));

vector<pair<double, double>> get_intervals(double a, double b, double (*f)(double));

bool to_file(vector<double> vect, string f_name);

bool to_file(vector<pair<double, double>> vect, string f_name);

#endif
