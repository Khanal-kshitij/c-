#include <iostream>
using namespace std;

// Function to remove duplicates and return new size
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;  // No duplicates possible
    }

    // Temporary array to store unique elements
    int temp[n];
    int j = 0;  // Index for temp array

    // Traverse the array and keep unique elements
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[n - 1];  // Add the last element

    // Copy unique elements back to original array
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    return j;  // Return new size
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Note: This method assumes array is sorted
    int newSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
