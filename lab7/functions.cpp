#include "functions.h"

double f(double x) {
    return pow(x, 2) - 5*x + 6;
}

double df(double x, double y) {
    return (pow(y + x - 2, 2) - pow(y, 2)) / pow(x-2, 2);
}

double f1(double x) {
    return (1 + x + pow(x, 2)) * exp(x) - 3;
}

double f2(double x) {
    return 2 * (exp(x) + x * exp(x) - 1);
}

double df1(double y1, double y2) {
    return 2 * y2 - y1 + 1;
}

double df2(double y1, double y2) {
    return 3 * y2 - 2 * y1;
}
