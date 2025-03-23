#include <iostream>
using namespace std;

// a. GCD with Recursion (Euclidean Algorithm)
int gcdRecursive(int a, int b) {
    // Base case: if b becomes 0, return a
    if (b == 0) {
        return a;
    }
    // Recursive case: GCD(a, b) = GCD(b, a % b)
    return gcdRecursive(b, a % b);
}

// b. GCD without Recursion (Euclidean Algorithm)
int gcdIterative(int a, int b) {
    // Loop until b becomes 0
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, choice;
    
    // Input two numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    // Ensure positive numbers (GCD is defined for non-negative integers)
    num1 = abs(num1);
    num2 = abs(num2);
    
    // Menu for choosing method
    cout << "\nChoose GCD calculation method:\n";
    cout << "1. Recursive Method\n";
    cout << "2. Iterative Method\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    
    int result;
    switch (choice) {
        case 1:
            result = gcdRecursive(num1, num2);
            cout << "GCD of " << num1 << " and " << num2 << " (Recursive) = " << result << endl;
            break;
            
        case 2:
            result = gcdIterative(num1, num2);
            cout << "GCD of " << num1 << " and " << num2 << " (Iterative) = " << result << endl;
            break;
            
        default:
            cout << "Invalid choice!\n";
            return 1;
    }
    
    return 0;
}