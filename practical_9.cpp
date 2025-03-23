#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n = "Unknown") : name(n) {}

    // Virtual display method for runtime polymorphism
    virtual void display() const {
        cout << "Name: " << name << endl;
    }

    // Virtual destructor for proper cleanup in inheritance
    virtual ~Person() {}
};

class Student : public Person {
private:
    string course;
    int marks;
    int year;

public:
    Student(string n = "Unknown", string c = "N/A", int m = 0, int y = 0)
        : Person(n), course(c), marks(m), year(y) {}

    // Override display method
    void display() const override {
        cout << "Student Details:\n";
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

class Employee : public Person {
private:
    string department;
    double salary;

public:
    Employee(string n = "Unknown", string d = "N/A", double s = 0.0)
        : Person(n), department(d), salary(s) {}

    // Override display method
    void display() const override {
        cout << "Employee Details:\n";
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Array of pointers to Person for polymorphism
    Person* people[3];
    
    // Create objects
    people[0] = new Person("John Doe");
    people[1] = new Student("Alice Smith", "Computer Science", 85, 2023);
    people[2] = new Employee("Bob Johnson", "Engineering", 75000.50);
    
    // Demonstrate runtime polymorphism
    cout << "Displaying details using polymorphism:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Entry " << i + 1 << ":\n";
        people[i]->display();
        cout << "------------------------\n";
    }
    
    // Clean up memory
    for (int i = 0; i < 3; i++) {
        delete people[i];
    }
    
    return 0;
}