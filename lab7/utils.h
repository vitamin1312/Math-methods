#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
std::vector<T> get_x(T start, T end, T step) {
    
    std::vector<T> x;
    for (double interm_value = start; interm_value <= end; interm_value += step)
        x.push_back(interm_value);

    return x;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T>& v) {
    for (T elem : v)
        os << elem << ' ';
    return os;
}

void to_file(std::vector<double> &v, std::string f_name, std::string mode);

void fill_values(std::vector<double> &x, std::vector<double> &y, double *(f)(double));

#endif