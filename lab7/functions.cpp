#include "functions.h"

double f(double x) {
    return pow(x, 2) - 5*x + 6;
}

double df(double x, double y) {
    return (pow(y + x - 2, 2) - pow(y, 2)) / pow(x-2, 2);
}