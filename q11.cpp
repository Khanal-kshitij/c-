#include <iostream>
using namespace std;

int main() {
    int p, q;
    cout << "Enter two numbers (p and q): ";
    cin >> p >> q;

    try {
        if (q == 0) {
            throw "Division by zero is not allowed!";
        }
        cout << "Result of p/q: " << (p / q) << endl;
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}
