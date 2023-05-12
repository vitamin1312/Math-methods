#include "utils.h"

void to_file(std::vector<double> &v, std::string f_name, std::string mode) {
    
    std::ofstream out;
    if (mode == "a")
        out.open(f_name, std::ios_base::app);
    else
        out.open(f_name);


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
