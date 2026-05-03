#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* ==========================================
   SYSTEM OF EQUATIONS BEING SOLVED
   ------------------------------------------
   Original System:
   Eq 1:  5x - 2y + 3z = -1
   Eq 2: -3x + 9y +  z =  2
   Eq 3:  2x -  y - 7z =  3

   Rearranged for Jacobi Method:
   x = (-1 + 2y - 3z) / 5
   y = ( 2 + 3x -  z) / 9
   z = ( 3 - 2x +  y) / -7
   ========================================== */

// 1. Predefine our rearranged equations
double getNewX(double y, double z) {
    return (-1.0 + 2.0 * y - 3.0 * z) / 5.0;
}

double getNewY(double x, double z) {
    return (2.0 + 3.0 * x - z) / 9.0;
}

double getNewZ(double x, double y) {
    return (3.0 - 2.0 * x + y) / -7.0;
}

int main() {
    cout << "--- Jacobi Iterative Solver ---" << endl;

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    
    double new_x, new_y, new_z;

    cout << fixed << setprecision(5);

    for (int i = 0; i < 10; i++) {
        
        new_x = getNewX(y, z);
        new_y = getNewY(x, z);
        new_z = getNewZ(x, y);

        x = new_x;
        y = new_y;
        z = new_z;

        cout << "Iteration " << i + 1 << ": x = " << x << " | y = " << y << " | z = " << z << endl;
    }

    cout << "\nFinal estimated roots:" << endl;
    cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;

    return 0;
}