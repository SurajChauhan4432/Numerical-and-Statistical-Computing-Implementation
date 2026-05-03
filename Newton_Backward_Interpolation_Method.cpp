#include <iostream>
#include <iomanip>

using namespace std;

// TWEAK 1: Backward 'u' term multipliers use ADDITION
// Example: if n=3, it calculates u * (u + 1) * (u + 2)
double calculateU(double u, int n) {
    double temp = u;
    for (int i = 1; i < n; i++) {
        temp = temp * (u + i); // Changed from (u - i) to (u + i)
    }
    return temp;
}

// Factorial remains exactly the same
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    cout << "--- Newton Backward Interpolation ---" << endl;

    // PREDEFINE THE DATASET
    int n = 4; 
    double x[] = {45.0, 50.0, 55.0, 60.0};
    
    double y[4][4]; 
    y[0][0] = 0.7071;
    y[1][0] = 0.7660;
    y[2][0] = 0.8192;
    y[3][0] = 0.8660;

    // We use 58.0 because backward interpolation is for values near the END
    double target_x = 58.0; 

    // --- PHASE 1: BUILD THE DIFFERENCE TABLE ---
    // We adjust the loops slightly to build the table from the bottom up.
    // This pushes all our required backward differences to the very bottom row.
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    // (Optional) Print the difference table
    cout << "\nBackward Difference Table:" << endl;
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i] << "\t";
        // We only print up to 'i' to show the lower triangle
        for (int j = 0; j <= i; j++) { 
            cout << setw(10) << y[i][j] << "\t";
        }
        cout << endl;
    }

    // --- PHASE 2: APPLY THE NEWTON FORMULA ---
    double h = x[1] - x[0]; 
    
    // TWEAK 2: Calculate 'u' using the LAST x value (x[n-1])
    double u = (target_x - x[n - 1]) / h;

    // TWEAK 3: Start the sum with the LAST Y value (y[n-1][0])
    double final_y = y[n - 1][0]; 

    // Loop through the BOTTOM row of our difference table
    for (int i = 1; i < n; i++) {
        // Notice we are grabbing y[n - 1][i] instead of y[0][i]
        final_y = final_y + (calculateU(u, i) * y[n - 1][i]) / factorial(i);
    }

    cout << "\n=======================================" << endl;
    cout << "The value of y at x = " << target_x << " is " << final_y << endl;

    return 0;
}