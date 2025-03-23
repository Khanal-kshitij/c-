#include <iostream>
#include <cctype> // For tolower() and isalpha()
using namespace std;

// Function to count occurrences of each alphabet
void countAlphabets(char* text, int counts[]) {
    while (*text) { // Continue until null terminator
        char c = tolower(*text);
        if (isalpha(c)) {
            counts[c - 'a']++;
        }
        text++; // Move to next character
    }
}

// Function to print the table
void printTable(int counts[]) {
    cout << "Alphabet Occurrence Table:\n";
    cout << "-------------------------\n";
    cout << "Letter | Count\n";
    cout << "-------|-------\n";
    
    for (int i = 0; i < 26; i++) {
        char letter = 'a' + i;
        if (counts[i] > 0) {
            cout << "  " << letter << "    |   " << counts[i] << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <text>\n";
        cout << "Example: " << argv[0] << " \"Hello World\"\n";
        return 1;
    }

    int counts[26] = {0}; // Array to store counts for a-z

    // Process all arguments starting from argv[1]
    for (int i = 1; i < argc; i++) {
        countAlphabets(argv[i], counts);
    }

    printTable(counts);

    return 0;
}