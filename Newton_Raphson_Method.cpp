#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Predefine the original function: f(x) = x^4 - x - 10
double f(double x){
    return pow(x, 4) - x - 10;
}

// Predefine the derivative function: f'(x) = 4x^3 - 1
double df(double x){
    return 4 * pow(x, 3) - 1;
}

int main(){
    double a, b, x;

    cout << "--- Newton-Raphson Root Finder ---" << endl;
    cout << "Equation: x^4 - x - 10 = 0" << endl;
    cout << "Enter the first value of the interval (a): ";
    cin >> a;
    cout << "Enter the second value of the interval (b): ";
    cin >> b;

    if (abs(f(a)) < abs(f(b))) {
        x = a;
        cout << "\nf(" << a << ") is closer to 0. Choosing x0 = " << a << endl;
    } else {
        x = b;
        cout << "\nf(" << b << ") is closer to 0. Choosing x0 = " << b << endl;
    }

    cout << fixed << setprecision(6);
    cout << "\nStarting exactly 10 iterations...\n";

    for(int i = 0; i < 10; i++){
        
        if (df(x) == 0.0) {
            cout << "Error: Derivative is zero. The tangent is completely flat." << endl;
            return 0;
        }

        double new_x = x - (f(x) / df(x));
        
        cout << "Iteration " << i + 1 << ": x = " << new_x << endl;

        x = new_x;
    }
    
    cout << "\nFinal estimated root after 10 iterations: " << x << endl;
    
    return 0;
}