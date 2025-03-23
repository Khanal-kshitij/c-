#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    // Constructor with validation
    Triangle(double s1, double s2, double s3) {
        // Check if sides are positive
        if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
            throw invalid_argument("All sides must be greater than 0");
        }
        
        // Check triangle inequality theorem
        if (s1 + s2 <= s3 || s2 + s3 <= s1 || s1 + s3 <= s2) {
            throw invalid_argument("Sum of any two sides must be greater than the third side");
        }
        
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    // Area for right-angled triangle (base and height)
    double area(double base, double height) const {
        // Assuming this is called for right-angled triangle
        return 0.5 * base * height;
    }

    // Area using Heron's formula (for any triangle)
    double area() const {
        // Calculate semi-perimeter
        double s = (side1 + side2 + side3) / 2.0;
        
        // Heron's formula: Area = sqrt(s(s-a)(s-b)(s-c))
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Display sides
    void display() const {
        cout << "Triangle sides: " << side1 << ", " << side2 << ", " << side3 << endl;
    }
};

int main() {
    double s1, s2, s3;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create triangle and calculate area (Heron's formula)\n";
        cout << "2. Calculate area of right-angled triangle\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }

        try {
            cout << "Enter three sides of the triangle: ";
            cin >> s1 >> s2 >> s3;

            // Create Triangle object
            Triangle tri(s1, s2, s3);
            tri.display();

            switch (choice) {
                case 1: {
                    double areaHeron = tri.area();
                    cout << "Area using Heron's formula: " << areaHeron << endl;
                    break;
                }

                case 2: {
                    double base, height;
                    cout << "Enter base and height for right-angled triangle: ";
                    cin >> base >> height;
                    double areaRight = tri.area(base, height);
                    cout << "Area of right-angled triangle: " << areaRight << endl;
                    break;
                }

                default:
                    cout << "Invalid choice! Try again.\n";
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        } catch (const exception& e) {
            cout << "Unexpected error: " << e.what() << endl;
        }
    }

    return 0;
}