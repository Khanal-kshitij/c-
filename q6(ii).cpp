#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] < key) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6, key = 5;

    int result = binarySearchIterative(arr, n, key);
    (result != -1) ? cout << "Element found at index " << result : cout << "Element not found";
    return 0;
}
