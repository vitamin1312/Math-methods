#include "utils.h"
#include <vector>


using namespace std;

double find_m(double a, double b, double n, double (*f)(double)) {
    
    double h = (b - a) / n;
    double m = f(a);

    while (a < b) {
        a += h;
        m = min(m, f(a));
    }

    return m;
}


double find_M(double a, double b, double n, double (*f)(double)) {
    
    double h = (b - a) / n;
    double M = f(a);

    while (a < b) {
        a += h;
        M = max(M, f(a));
    }

    return M;
}


double find_M(double a,
              double b,
              double n,
              double alpha,
              double (*f)(double),
              double (*fi)(double, double, double (*f)(double))) {
    
    double h = (b - a) / n;
    double M = fi(alpha, a, f);

    while (a < b) {
        a += h;
        M = max(M, fi(alpha, a, f));
    }

    return M;
}


vector<pair<double, double>> get_intervals(double a, double b, double (*f)(double)) {

    double h = (b - a) / 100;
    vector<pair<double, double>> intervals;

    while(a < b){
        if (f(a)*f(a+h) < 0){
            intervals.push_back(make_pair(a, a+h));
        }
        a += h;
    }
    return intervals;
}

bool to_file(vector<double> vect, string f_name) {
    std::ofstream file;
	file.open(f_name + ".txt", ios_base::app);

	if (file.is_open()) {
        for (double elem : vect)
            file << elem << ' ';
        file << endl;
        return true;
    }
    return false;
}


bool to_file(vector<pair<double, double>> vect, string f_name) {
    std::ofstream file;
	file.open(f_name + ".txt", ios_base::app);

	if (file.is_open()) {
        for (auto [a, b] : vect)
            file << a << ';' << b << ' ';
        file << endl;
        return true;
    }
    return false;
}
