#include <iostream>
using namespace std;

int gcdRecursive(int a, int b) {
    return (b == 0) ? a : gcdRecursive(b, a % b);
}
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int a = 56, b = 98;
    cout << "GCD recursive: " << gcdRecursive(a, b);
    cout << "GCD iterative: " << gcdIterative(a, b);
    return 0;
}