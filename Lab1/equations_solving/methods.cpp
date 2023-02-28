#include "utils.h"
#include <cmath>
#include <vector>

using namespace std;


vector<double> newton(double x,
              double a,
              double b,
              double (*f)(double),
              double (*df)(double)) {

    vector<double> all_x;
    double m = find_m(a, b, 1000, df);

    double x_previous;

    do {
        all_x.push_back(x);
        x_previous = x;
        x = x - f(x) / df(x);

        if (all_x.size() > 100) {
            return all_x;
        }

    } while (abs(x - x_previous) > abs(f(x)/m));

    return all_x;
}


vector<double> iterations(double x,
                  double a,
                  double b,
                  double eps,
                  double (*f)(double),
                  double (*df)(double),
                  double (*fi)(double, double, double (*f)(double)),
                  double (*dfi)(double, double, double (*f)(double))) {

    vector<double> all_x;

    double x_previos;
    double m = find_m(a, b, 1000, df);
    double M = find_M(a, b, 1000, df);
    double alpha = 1 / ((abs(m) > abs(M)) ? m : M);
    double q = find_M(a, b, 1000, alpha, df, dfi);

    double gamma = (q > 0.5) ? (1 - q) / q * eps : eps;

    do {
        all_x.push_back(x);
        x_previos = x;
        x = fi(alpha, x, f);

        if (all_x.size() > 100) {
            return all_x;
        }

    } while (abs(x - x_previos) > gamma);

    return all_x;
}


vector<double> chords(double x,
              double a,
              double b,
              double eps,
              double (*f)(double),
              double (*d2f)(double)) {
    
    vector<double> all_x;

    double x_previos;

    do {

        all_x.push_back(x);
        x_previos = x;

        if (f(b)*d2f(b) > 0)
            x = x - f(x) * (b - x) / (f(b) - f(x));
        else
            x = x - f(x) * (x - a) / (f(x) - f(a));
        
        if (all_x.size() > 100) {
            return all_x;
        }
        
    } while (abs(x - x_previos) > eps);

    return all_x;
}


vector<pair<double, double>> iterations_system(double x,
                  double y,
                  double eps,
                  double (*fi1)(double, double),
                  double (*fi2)(double, double)) {

    vector<pair<double, double>> all_x_y;
    double x_previos, y_previos;

    do {
        all_x_y.push_back(make_pair(x, y));
        x_previos = x;
        y_previos = y;
        x = fi1(x, y);
        y = fi2(x, y);


        if (all_x_y.size() > 100) {
            return all_x_y;
        }

    } while (abs(x - x_previos) > eps
             || abs(y - y_previos) > eps);
             
    return all_x_y;
}