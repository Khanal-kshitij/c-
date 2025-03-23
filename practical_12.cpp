#include <iostream>
#include <fstream>
#include <cctype> // For isspace()
using namespace std;

void copyWithoutWhitespace(const string& sourceFile, const string& destFile) {
    // Open source file for reading
    ifstream inFile(sourceFile);
    if (!inFile) {
        cerr << "Error: Unable to open source file '" << sourceFile << "'\n";
        return;
    }

    // Open destination file for writing
    ofstream outFile(destFile);
    if (!outFile) {
        cerr << "Error: Unable to open destination file '" << destFile << "'\n";
        inFile.close();
        return;
    }

    char ch;
    bool contentWritten = false;

    // Read character by character
    while (inFile.get(ch)) {
        // Write only non-whitespace characters
        if (!isspace(ch)) {
            outFile.put(ch);
            contentWritten = true;
        }
    }

    // Check if any content was written
    if (!contentWritten) {
        cout << "Warning: No non-whitespace content found in source file.\n";
    } else {
        cout << "Content successfully copied to '" << destFile << "' without whitespace.\n";
    }

    // Close both files
    inFile.close();
    outFile.close();
}

int main() {
    string sourceFile, destFile;

    // Input file names
    cout << "Enter source file name (e.g., input.txt): ";
    getline(cin, sourceFile);
    cout << "Enter destination file name (e.g., output.txt): ";
    getline(cin, destFile);

    // Call function to copy without whitespace
    copyWithoutWhitespace(sourceFile, destFile);

    return 0;
}