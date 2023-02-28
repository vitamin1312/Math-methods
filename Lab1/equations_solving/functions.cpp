#include <cmath>
#include "functions.h"

using namespace std;

double e = 2.7183;

double f1(double x) {
    return pow(x, 4) - 4*pow(x, 3) - 8*pow(x, 2) + 1;
}


double df1(double x) {
    return 4*pow(x, 3) - 12*pow(x, 2) - 16*x;
}


double d2f1(double x) {
    return 12*pow(x, 2) - 24*x - 16;
}

double fi(double alpha, double x, double (*f)(double)) {
    return x - alpha * f(x);
}

double dfi(double alpha, double x, double (*df)(double)) {
    return 1 - alpha * df(x);
}


////////////////////////////
double f2(double x) {
    return pow(x, x) + 9*x - 20;
}


double df2(double x) {
    return pow(x, x) * (log(x) + 1) + 9;
}


double d2f2(double x) {
    return pow(x, x) * (pow(log(x) + 1, 2) + 1/x);
}


double fi1(double x, double y) {
    return pow(5 - pow(y, 2), 0.5);
}

double fi2(double x, double y) {
    return pow(e, -x*y);
}


double fi11(double x, double y) {
    return -log(y) / y;
}


double fi22(double x, double y) {
    return pow(5 - pow(x, 2), 0.5);
}
