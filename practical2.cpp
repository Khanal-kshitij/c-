#include <iostream>
#include <set>
using namespace std;

void removeDuplicates(int arr[], int n) {
    // Create a set from array elements (automatically removes duplicates)
    set<int> uniqueElements(arr, arr + n);

    // Copy unique elements back to array
    int i = 0;
    for (int element : uniqueElements) {
        arr[i++] = element;
    }

    // Print the result
    cout << "Array after removing duplicates: ";
    for (int j = 0; j < uniqueElements.size(); j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    removeDuplicates(arr, n);

    return 0;
}