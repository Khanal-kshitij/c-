#include <iostream>
using namespace std;

int main() {
    string str = "hello world";  // Input string
    int n = str.length();

    char charArr[n]; // Array to store unique characters
    int countArr[n] = {0}; // Array to store count of each character
    int uniqueCounter = 0; // Unique character count

    // Count unique characters
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        bool found = false;

        // Check if character is already in charArr
        for (int j = 0; j < uniqueCounter; j++) {
            if (charArr[j] == ch) {
                countArr[j]++; // Increase count
                found = true;
                break;
            }
        }

        // If character is not found, add it to charArr
        if (!found) {
            charArr[uniqueCounter] = ch;
            countArr[uniqueCounter] = 1;
            uniqueCounter++;
        }
    }

    // Print results
    cout << "Character  Count\n";
    for (int i = 0; i < uniqueCounter; i++) {
        cout << "   " << charArr[i] << "         " << countArr[i] << endl;
    }

    return 0;
}
