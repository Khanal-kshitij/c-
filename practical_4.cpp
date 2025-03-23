#include <iostream>
using namespace std;

// Function to calculate string length using pointers
int length(char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// Function to show address of each character
void showAddress(char* str) {
    cout << "Address of each character in string:\n";
    while (*str != '\0') {
        cout << "Character '" << *str << "' at address: " << (void*)str << "\n";
        str++;
    }
}

// Function to concatenate two strings
void concatenate(char* str1, char* str2) {
    char* temp = str1;
    while (*temp != '\0') {
        temp++;
    }
    while (*str2 != '\0') {
        *temp = *str2;
        temp++;
        str2++;
    }
    *temp = '\0';
}

// Function to compare two strings
int compare(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2; // Return difference if characters differ
        }
        str1++;
        str2++;
    }
    return length(str1) - length(str2); // If one is prefix of other
}

// Function to convert lowercase to uppercase
void toUppercase(char* str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32; // ASCII difference between lowercase and uppercase
        }
        str++;
    }
}

// Function to reverse a string
void reverse(char* str) {
    int len = length(str);
    char* start = str;
    char* end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to insert one string into another at a position
void insertString(char* mainStr, char* insertStr, int pos) {
    int mainLen = length(mainStr);
    int insertLen = length(insertStr);
    
    if (pos < 0 || pos > mainLen) {
        cout << "Invalid position!\n";
        return;
    }

    // Shift characters to make space
    char temp[100]; // Temporary buffer (assumes max length)
    char* src = mainStr + mainLen;
    char* dest = src + insertLen;
    while (src >= mainStr + pos) {
        *dest = *src;
        src--;
        dest--;
    }

    // Insert the string
    src = insertStr;
    dest = mainStr + pos;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
}

int main() {
    char str1[100], str2[100];
    int choice, pos;

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show address of each character\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of the string\n";
        cout << "5. Convert to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert a string at position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
            case 1:
                showAddress(str1);
                break;

            case 2:
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                concatenate(str1, str2);
                cout << "Concatenated string: " << str1 << "\n";
                break;

            case 3:
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                if (compare(str1, str2) == 0)
                    cout << "Strings are equal\n";
                else if (compare(str1, str2) < 0)
                    cout << "First string is less than second\n";
                else
                    cout << "First string is greater than second\n";
                break;

            case 4:
                cout << "Length of string: " << length(str1) << "\n";
                break;

            case 5:
                toUppercase(str1);
                cout << "Uppercase string: " << str1 << "\n";
                break;

            case 6:
                reverse(str1);
                cout << "Reversed string: " << str1 << "\n";
                break;

            case 7:
                cout << "Enter string to insert: ";
                cin.getline(str2, 100);
                cout << "Enter position: ";
                cin >> pos;
                cin.ignore();
                insertString(str1, str2, pos);
                cout << "Resulting string: " << str1 << "\n";
                break;

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}