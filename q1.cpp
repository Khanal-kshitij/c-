#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter a value for n";
    cin >> n;
    double result;
    for (int i = 1; i<=n ; i++) {
        result += 1.0/pow(i,i   );
    }
    cout << "Result:" << result;
    return 0;
}
