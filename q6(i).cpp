#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right) 
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == key) 
        return mid;
    else if (arr[mid] > key) 
        return binarySearchRecursive(arr, left, mid - 1, key);
    else 
        return binarySearchRecursive(arr, mid + 1, right, key);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6, key = 5;

    int result = binarySearchRecursive(arr, 0, n - 1, key);
    (result != -1) ? cout << "Element found at index " << result : cout << "Element not found";
    return 0;
}
