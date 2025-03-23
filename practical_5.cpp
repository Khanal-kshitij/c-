#include <iostream>
using namespace std;

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0; // Index for arr1
    int j = 0; // Index for arr2
    int k = 0; // Index for result array

    // Merge while there are elements in both arrays
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1, if any
    while (i < size1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2, if any
    while (j < size2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;

    // Input for first array
    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter " << size1 << " sorted elements: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    // Input for second array
    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter " << size2 << " sorted elements: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    // Create result array with size = size1 + size2
    int result[size1 + size2];

    // Merge the arrays
    mergeArrays(arr1, size1, arr2, size2, result);

    // Print the arrays
    cout << "First array: ";
    printArray(arr1, size1);
    cout << "Second array: ";
    printArray(arr2, size2);
    cout << "Merged sorted array: ";
    printArray(result, size1 + size2);

    return 0;
}