#include <iostream>
using namespace std;

class Person {
public:
    string name;
    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
public:
    string course;
    int marks, year;

    void display() override {
        cout << "Student: " << name << ", Course: " << course << ", Marks: " << marks << ", Year: " << year << endl;
    }
};

class Employee : public Person {
public:
    string department;
    double salary;

    void display() override {
        cout << "Employee: " << name << ", Department: " << department << ", Salary: " << salary << endl;
    }
};

int main() {
    Person* p;
    Student s;
    Employee e;

    s.name = "John"; s.course = "CS"; s.marks = 85; s.year = 2;
    e.name = "Jane"; e.department = "HR"; e.salary = 50000;

    p = &s; p->display();
    p = &e; p->display();

    return 0;
}
