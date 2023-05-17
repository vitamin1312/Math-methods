#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T>& v) {
    for (T elem : v)
        os << elem << ' ';
    return os;
}

void to_file(std::vector<double> &v, std::string f_name, std::string mode);

void fill_values(std::vector<double> &x, std::vector<double> &y, double (*f)(double));

double absolute_error(double pred, double targ);

double relative_error(double pred, double targ);

std::vector<double> get_x(double start, double end, double step);


#endif