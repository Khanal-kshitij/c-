#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5, 6, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]);   

    int uniqueArr[n]; 
    int uniqueSize = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        
        for (int j = 0; j < uniqueSize; j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            uniqueArr[uniqueSize] = arr[i];
            uniqueSize++;
        }
    }
    cout << "Unique elements: ";
    for (int i = 0; i < uniqueSize; i++) {
        cout << uniqueArr[i] << " ";
    }
    return 0;
}