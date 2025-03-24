#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    string className;
    int year;
    double totalMarks;

public:
    
    Student(int r = 0, string n = "", string c = "", int y = 0, double m = 0.0)
        : rollNo(r), name(n), className(c), year(y), totalMarks(m) {}

    
    void input() {
        cout << "Enter Roll No.: ";
        cin >> rollNo;
        cin.ignore(); 
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Class: ";
        getline(cin, className);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Total Marks: ";
        cin >> totalMarks;
        cin.ignore();
    }

    // Display method
    void display() const {
        cout << "Roll No.: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << className << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }

    // Write to file
    void writeToFile(ofstream& outFile) const {
        outFile.write(reinterpret_cast<const char*>(&rollNo), sizeof(rollNo));
        size_t nameSize = name.size();
        outFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        outFile.write(name.c_str(), nameSize);
        size_t classSize = className.size();
        outFile.write(reinterpret_cast<const char*>(&classSize), sizeof(classSize));
        outFile.write(className.c_str(), classSize);
        outFile.write(reinterpret_cast<const char*>(&year), sizeof(year));
        outFile.write(reinterpret_cast<const char*>(&totalMarks), sizeof(totalMarks));
    }

    // Read from file
    void readFromFile(ifstream& inFile) {
        inFile.read(reinterpret_cast<char*>(&rollNo), sizeof(rollNo));
        size_t nameSize;
        inFile.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        char* nameBuffer = new char[nameSize + 1];
        inFile.read(nameBuffer, nameSize);
        nameBuffer[nameSize] = '\0';
        name = string(nameBuffer);
        delete[] nameBuffer;

        size_t classSize;
        inFile.read(reinterpret_cast<char*>(&classSize), sizeof(classSize));
        char* classBuffer = new char[classSize + 1];
        inFile.read(classBuffer, classSize);
        classBuffer[classSize] = '\0';
        className = string(classBuffer);
        delete[] classBuffer;

        inFile.read(reinterpret_cast<char*>(&year), sizeof(year));
        inFile.read(reinterpret_cast<char*>(&totalMarks), sizeof(totalMarks));
    }
};

int main() {
    const int NUM_STUDENTS = 5;
    Student students[NUM_STUDENTS];
    const string filename = "students.dat";

    // Writing to file
    cout << "Enter details for 5 students:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].input();
    }

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < NUM_STUDENTS; i++) {
        students[i].writeToFile(outFile);
    }
    outFile.close();
    cout << "\nData successfully written to file.\n";

    // Reading from file
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nRetrieving and displaying student records from file:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        Student temp;
        temp.readFromFile(inFile);
        cout << "\nStudent " << i + 1 << ":\n";
        temp.display();
        cout << "------------------------\n";
    }
    inFile.close();

    return 0;
}
