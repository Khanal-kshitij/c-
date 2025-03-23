#include <iostream>
using namespace std;

// a. Binary Search with Recursion
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        
        // If element is found at mid
        if (arr[mid] == key) {
            return mid;
        }
        
        // If element is smaller than mid, search left half
        if (arr[mid] > key) {
            return binarySearchRecursive(arr, left, mid - 1, key);
        }
        
        // If element is larger than mid, search right half
        return binarySearchRecursive(arr, mid + 1, right, key);
    }
    return -1; // Element not found
}

// b. Binary Search without Recursion
int binarySearchIterative(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        
        // If element is found at mid
        if (arr[mid] == key) {
            return mid;
        }
        
        // If element is smaller than mid, search left half
        if (arr[mid] > key) {
            right = mid - 1;
        }
        // If element is larger than mid, search right half
        else {
            left = mid + 1;
        }
    }
    return -1; // Element not found
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, key, choice;
    
    // Input array size and elements
    cout << "Enter the number of elements (N): ";
    cin >> N;
    int arr[N];
    cout << "Enter " << N << " sorted elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    printArray(arr, N);
    
    // Input element to search
    cout << "Enter the element to search: ";
    cin >> key;
    
    // Menu for choosing method
    cout << "\nChoose search method:\n";
    cout << "1. Recursive Binary Search\n";
    cout << "2. Iterative Binary Search\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    
    int result;
    switch (choice) {
        case 1:
            result = binarySearchRecursive(arr, 0, N - 1, key);
            if (result != -1) {
                cout << "Element " << key << " found at index " << result << " (Recursive)\n";
            } else {
                cout << "Element " << key << " not found (Recursive)\n";
            }
            break;
            
        case 2:
            result = binarySearchIterative(arr, N, key);
            if (result != -1) {
                cout << "Element " << key << " found at index " << result << " (Iterative)\n";
            } else {
                cout << "Element " << key << " not found (Iterative)\n";
            }
            break;
            
        default:
            cout << "Invalid choice!\n";
            return 1;
    }
    
    return 0;
}