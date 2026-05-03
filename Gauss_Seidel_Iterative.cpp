#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* ==========================================
   SYSTEM OF EQUATIONS BEING SOLVED
   ------------------------------------------
   Original System from notes:
   Eq 1: 10x1 -  x2 +  2x3        =  6
   Eq 2: -x1  + 11x2 -  x3 + 3x4  =  25
   Eq 3:  2x1 -  x2  + 10x3 - x4  = -11
   Eq 4:         3x2 -  x3 + 8x4  =  15

   Rearranged for Gauss-Seidel Method:
   x1 = (  6 +  x2 - 2x3 ) / 10
   x2 = ( 25 +  x1 +  x3 - 3x4 ) / 11
   x3 = (-11 - 2x1 +  x2 +  x4 ) / 10
   x4 = ( 15 - 3x2 +  x3 ) / 8
   ========================================== */

// 1. Predefine our rearranged equations
double getNewX1(double x2, double x3) {
    return (6.0 + x2 - 2.0 * x3) / 10.0;
}

double getNewX2(double x1, double x3, double x4) {
    return (25.0 + x1 + x3 - 3.0 * x4) / 11.0;
}

double getNewX3(double x1, double x2, double x4) {
    return (-11.0 - 2.0 * x1 + x2 + x4) / 10.0;
}

double getNewX4(double x2, double x3) {
    return (15.0 - 3.0 * x2 + x3) / 8.0;
}

int main() {
    cout << "--- Gauss-Seidel Iterative Solver (4 Variables) ---" << endl;

    // Initial guesses (starting at 0)
    double x1 = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0;

    cout << fixed << setprecision(5);

    // Run the iteration loop. 
    // Gauss-Seidel is faster, so it might stabilize before 15 loops!
    for (int i = 0; i < 15; i++) {
        
        // --- THE GAUSS-SEIDEL MAGIC ---
        // We overwrite the variables immediately. 
        // Notice how getNewX2 uses the brand new x1 we JUST calculated on the line above it!
        x1 = getNewX1(x2, x3);
        x2 = getNewX2(x1, x3, x4);
        x3 = getNewX3(x1, x2, x4);
        x4 = getNewX4(x2, x3);

        cout << "Iteration " << setw(2) << i + 1 
             << ": x1=" << setw(8) << x1 
             << " | x2=" << setw(8) << x2 
             << " | x3=" << setw(8) << x3 
             << " | x4=" << setw(8) << x4 << endl;
    }

    // --- THE TEACHER's ROUNDING REQUIREMENT ---
    double rounded_x1 = round(x1 * 10000.0) / 10000.0;
    double rounded_x2 = round(x2 * 10000.0) / 10000.0;
    double rounded_x3 = round(x3 * 10000.0) / 10000.0;
    double rounded_x4 = round(x4 * 10000.0) / 10000.0;

    cout << "\n=============================================" << endl;
    cout << "Final estimated roots (Rounded at the end):" << endl;
    cout << "x1 = " << rounded_x1 << endl;
    cout << "x2 = " << rounded_x2 << endl;
    cout << "x3 = " << rounded_x3 << endl;
    cout << "x4 = " << rounded_x4 << endl;

    return 0;
}