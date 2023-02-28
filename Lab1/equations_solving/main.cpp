#include <iostream>
#include <cmath>
#include <vector>
#include "functions.h"
#include "utils.h"
#include "methods.h"

using namespace std;


int main() {

    vector<double> all_x;
    double x;
    unsigned int N;

    vector<pair<double, double>> intervals1 = get_intervals(-10, 10, &f1);

    cout << endl << "Newton method for function 1" << endl;


    for (auto [a, b] : intervals1) {
        all_x = newton((a + b)/2, a, b, &f1, &df1); 
        N = all_x.size(); 
        x = all_x[N-1];
        to_file(all_x, "f1 newton");
        cout << "x: " << x << "; number of iterations: " << N-1 << "; f(x): " << f1(x) << endl;
    }


    cout << endl << "Iterations method for function 1" << endl;

    for (auto [a, b] : intervals1) {

        all_x = iterations((a+b)/2, a, b, 0.001, &f1, &df1, &fi, &dfi); 
        N = all_x.size();
        x = all_x[N-1];
        to_file(all_x, "f1 iterations");
        cout << "x: " << x << "; number of iterations: " << N-1 << "; f(x): " << f1(x) << endl;
    }


    cout << endl << "Chords method for function 1" << endl;

    for (auto [a, b] : intervals1) {
        all_x = chords((a+b)/2, a, b, 0.00001, &f1, &d2f1);      
        N = all_x.size();
        x = all_x[N-1];
        to_file(all_x, "f1 chords");
        cout << "x: " << x << "; number of iterations: " << N-1 << "; f(x): " << f1(x) << endl;
    }



    vector<pair<double, double>> intervals2 = get_intervals(1, 2.5, &f2);

    cout << endl << "Newton method for function 2" << endl;

    for (auto [a, b] : intervals2) {
        all_x = newton((a + b)/2, a, b, &f2, &df2);      
        N = all_x.size();
        x = all_x[N-1];
        to_file(all_x, "f2 newton");
        cout << "x: " << x << "; number of iterations: " << N-1 << "; f(x): " << f2(x) << endl;
    }

    cout << endl << "Iterations method for function 2" << endl;

    for (auto [a, b] : intervals2) {

        all_x = iterations((a+b)/2, a, b, 0.001, &f2, &df2, &fi, &dfi); 
        N = all_x.size();
        x = all_x[N-1];
        to_file(all_x, "f2 iterations");
        cout << "x: " << x << "; number of iterations: " << N-1 << "; f(x): " << f2(x) << endl;
    }

    cout << endl << "Chord method for function 2" << endl;

    for (auto [a, b] : intervals2) {
        all_x = chords((a+b)/2, a, b, 0.00001, &f2, &d2f2);      
        N = all_x.size();
        x = all_x[N-1];
        to_file(all_x, "f2 chords");
        cout << "x: " << all_x[N-1] << "; number of iterations: " << N-1 << "; f(x): " << f2(x) << endl;
    }

    cout << endl << "solving system of equentials" << endl;

    double y;

    vector<pair<double, double>> all_x_y = iterations_system(2.2, 0.4, 0.001, &fi1, &fi2);
    N = all_x_y.size();
    x = all_x_y[N-1].first;
    y = all_x_y[N-1].second;
    cout << "x: " << x << "; y: " << y << "; number of iterations: " << N-1 << endl;
    to_file(all_x_y, "system iterations");

    all_x_y = iterations_system(-0.4, 2.2, 0.001, &fi11, &fi22);
    N = all_x_y.size();
    x = all_x_y[N-1].first;
    y = all_x_y[N-1].second;
    cout << "x: " << x << "; y: " << y << "; number of iterations: " << N-1 << endl;
    to_file(all_x_y, "system iterations");

    return 0;
}
