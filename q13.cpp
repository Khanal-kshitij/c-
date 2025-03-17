#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string studentClass;
    int year;
    float totalMarks;

    void input() {
        cout << "Enter Roll No: "; cin >> rollNo;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Class: "; cin >> studentClass;
        cout << "Enter Year: "; cin >> year;
        cout << "Enter Total Marks: "; cin >> totalMarks;
    }

    void display() {
        cout << rollNo << " " << name << " " << studentClass << " " << year << " " << totalMarks << endl;
    }
};

int main() {
    Student students[5];

    // Writing to file
    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cout << "Error opening file!";
        return 1;
    }

    cout << "Enter details of 5 students:\n";
    for (int i = 0; i < 5; i++) {
        students[i].input();
        outFile.write((char*)&students[i], sizeof(students[i]));
    }
    outFile.close();

    // Reading from file
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file!";
        return 1;
    }

    cout << "\nStudent records from file:\n";
    Student temp;
    while (inFile.read((char*)&temp, sizeof(temp))) {
        temp.display();
    }
    inFile.close();

    return 0;
}
