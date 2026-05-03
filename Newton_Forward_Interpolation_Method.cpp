#include <iostream>
#include <iomanip>

using namespace std;

// Helper function 1: Calculates the 'u' term multipliers
// Example: if n=3, it calculates u * (u - 1) * (u - 2)
double calculateU(double u, int n) {
    double temp = u;
    for (int i = 1; i < n; i++) {
        temp = temp * (u - i);
    }
    return temp;
}

// Helper function 2: Calculates the factorial (n!)
// Example: if n=3, it calculates 1 * 2 * 3 = 6
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    cout << "--- Newton Forward Interpolation ---" << endl;

    // 1. PREDEFINE THE DATASET
    int n = 4; // Number of data points
    double x[] = {45.0, 50.0, 55.0, 60.0};
    
    // We create a 2D array to hold the Y values AND the difference table.
    // The first column [0] holds the original Y values.
    double y[4][4]; 
    y[0][0] = 0.7071;
    y[1][0] = 0.7660;
    y[2][0] = 0.8192;
    y[3][0] = 0.8660;

    // The value we want to find the answer for (must be near the beginning of the data)
    double target_x = 52.0; 

    // --- PHASE 1: BUILD THE DIFFERENCE TABLE ---
    // We calculate the differences by subtracting the row above from the current row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // (Optional) Print the difference table so we can see the math
    cout << "\nForward Difference Table:" << endl;
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << setw(10) << y[i][j] << "\t";
        }
        cout << endl;
    }

    // --- PHASE 2: APPLY THE NEWTON FORMULA ---
    // Calculate 'u': (Target X - First X) / Step Size
    double h = x[1] - x[0]; // Step size between x values
    double u = (target_x - x[0]) / h;

    // Start the sum with the very first Y value (y0)
    double final_y = y[0][0]; 

    // Loop through the top row of our difference table and add the formula terms
    for (int i = 1; i < n; i++) {
        final_y = final_y + (calculateU(u, i) * y[0][i]) / factorial(i);
    }

    cout << "\n=======================================" << endl;
    cout << "The value of y at x = " << target_x << " is " << final_y << endl;

    return 0;
}