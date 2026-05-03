#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calFuncValue(double x){
    return exp(x) - 3 * x;
}

int main(){
    double a, b;
    cout << "--- Regula Falsi Root Finder ---" << endl;
    cout << "Enter the first value (a): ";
    cin >> a;
    cout << "Enter the second value (b): ";
    cin >> b;

    if (calFuncValue(a) * calFuncValue(b) >= 0) {
        cout << "Error: The root is not bracketed by this interval. Try different values." << endl;
        return 0;
    }

    double new_root;
    cout << fixed << setprecision(6);
    cout << "\nStarting iterations...\n";

    for(int i = 0; i < 10; i++){
        new_root = a - (((b - a) / (calFuncValue(b) - calFuncValue(a))) * calFuncValue(a));
        
        cout << "Iteration " << i + 1 << ": Root = " << new_root << endl;

        if(calFuncValue(new_root) == 0.0){
            break;
        }
        else if(calFuncValue(a) * calFuncValue(new_root) < 0){
            b = new_root;
        }
        else{
            a = new_root;
        }
    }
    
    return 0;
}