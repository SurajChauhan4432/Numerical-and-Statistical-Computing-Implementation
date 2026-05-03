#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "--- Gaussian Elimination Solver ---" << endl;

    int n = 3; // 3 variables (x, y, z)
    
    double mat[3][4] = {
        { 2.0,  4.0,  6.0,   22.0 },
        { 3.0,  8.0,  5.0,   27.0 },
        {-1.0,  1.0,  2.0,   2.0 }
    };

    cout << fixed << setprecision(2);

    // --- STEP 1: FORWARD ELIMINATION ---
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            
            double factor = mat[i][k] / mat[k][k]; 
            
            for (int j = k; j < n + 1; j++) {
                mat[i][j] = mat[i][j] - (factor * mat[k][j]);
            }
        }
    }

    // --- STEP 2: BACK SUBSTITUTION ---
    double answers[3];
    
    for (int i = n - 1; i >= 0; i--) {
        answers[i] = mat[i][n];
        
        for (int j = i + 1; j < n; j++) {
            answers[i] = answers[i] - (mat[i][j] * answers[j]);
        }
        
        answers[i] = answers[i] / mat[i][i]; 
    }

    cout << "\nThe exact solutions are:" << endl;
    cout << "x = " << answers[0] << endl;
    cout << "y = " << answers[1] << endl;
    cout << "z = " << answers[2] << endl;

    return 0;
}