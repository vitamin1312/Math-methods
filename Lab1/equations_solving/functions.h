#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double f1(double x);

double df1(double x);

double d2f1(double x);

double fi(double alpha, double x, double (*f)(double));

double dfi(double alpha, double x, double (*f)(double));

double f2(double x);

double df2(double x);

double d2f2(double x);

double fi1(double x, double y);

double fi2(double x, double y);

double fi11(double x, double y);

double fi22(double x, double y);

#endif