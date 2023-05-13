#include "utils.h"

std::vector<double> get_x(double start, double end, double step) {

    end = end + step/10;
    std::vector<double> x;

    for (double interm_value = start; interm_value <= end; interm_value += step)
        x.push_back(interm_value);

    return x;
}

void to_file(std::vector<double> &v, std::string f_name, std::string mode) {
    
    std::ofstream out;
    if (mode == "a")
        out.open(f_name + ".txt", std::ios_base::app);
    else
        out.open(f_name + ".txt");


    if (out.is_open()) {
        for (double elem : v)
            out << elem << ' ';
        out << std::endl;
    }

    out.close();
}

void fill_values(std::vector<double> &x, std::vector<double> &y, double (*f)(double)) {
    for (double elem : x)
            y.push_back(f(elem));
}

double absolute_error(double pred, double targ) {
    return abs(pred - targ);
}

double relative_error(double pred, double targ) {
    return abs(pred - targ) / targ * 100;
}
