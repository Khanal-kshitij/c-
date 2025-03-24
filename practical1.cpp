#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double computeSeriesSum(int n) {
    double sum = 0.0;
    int sign = 1;  
    
    for (int i = 1; i <= n; i++) {
        
        sum += sign * (1.0 / pow(i, i));
        sign = -sign;  
    }
    
    return sum;
}

int main(int argc, char* argv[]) {
    int n;
    
    
    if (argc > 1) {
        n = atoi(argv[1]);  
        if (n <= 0) {
            cout << "Please enter a positive number of terms." << endl;
            return 1;
        }
    } else {
        
        cout << "Enter the number of terms (n): ";
        cin >> n;
        
        
        if (n <= 0) {
            cout << "Please enter a positive number of terms." << endl;
            return 1;
        }
    }
    
    
    double result = computeSeriesSum(n);
    cout << "Sum of the first " << n << " terms of the series is: " << result << endl;
    
    return 0;
}
