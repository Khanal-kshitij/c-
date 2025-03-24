#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double computeSeriesSum(int n) {
    double sum = 0.0;
    int sign = 1;  // To alternate between + and -
    
    for (int i = 1; i <= n; i++) {
        // Add term: sign * 1/(i^i)
        sum += sign * (1.0 / pow(i, i));
        sign = -sign;  // Flip sign for next term
    }
    
    return sum;
}

int main(int argc, char* argv[]) {
    int n;
    
    // Check if command line argument is provided
    if (argc > 1) {
        n = atoi(argv[1]);  // Convert string argument to integer
        if (n <= 0) {
            cout << "Please enter a positive number of terms." << endl;
            return 1;
        }
    } else {
        // Prompt user for input if no command line argument
        cout << "Enter the number of terms (n): ";
        cin >> n;
        
        // Validate input
        if (n <= 0) {
            cout << "Please enter a positive number of terms." << endl;
            return 1;
        }
    }
    
    // Compute and display the result
    double result = computeSeriesSum(n);
    cout << "Sum of the first " << n << " terms of the series is: " << result << endl;
    
    return 0;
}
