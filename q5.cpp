#include <iostream>
#include <algorithm> // For sorting
using namespace std;

int main() {
    int arr1[] = {1, 3, 5, 7, 9};  
    int arr2[] = {2, 4, 6};         

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged_size = size1 + size2;
    int merged[merged_size]; 


    int index = 0;
    for (int i = 0; i < size1; i++) {
        merged[index] = arr1[i];
        index++;
    }


    for (int i = 0; i < size2; i++) {
        merged[index] = arr2[i];
        index++;
    }


    for (int i = 0; i < merged_size - 1; i++) {
        for (int j = i + 1; j < merged_size; j++) {
            if (merged[i] > merged[j]) {
                int temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }

    cout << "Merged and sorted array: ";
    for (int i = 0; i < merged_size; i++)
        cout << merged[i] << " ";

    return 0;
}

 