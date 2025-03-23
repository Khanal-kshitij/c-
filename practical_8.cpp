#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data; // 2D array for matrix elements

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Input matrix elements
    void input() {
        cout << "Enter elements for " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Display matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // a. Sum of two matrices
    Matrix sum(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw "Incompatible matrices for addition: Dimensions do not match";
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // b. Product of two matrices
    Matrix product(const Matrix& other) const {
        if (cols != other.rows) {
            throw "Incompatible matrices for multiplication: Columns of first must equal rows of second";
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // c. Transpose of the matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() {
    int rows1, cols1, rows2, cols2, choice;

    // Input dimensions for first matrix
    cout << "Enter rows and columns for first matrix: ";
    cin >> rows1 >> cols1;
    Matrix m1(rows1, cols1);
    m1.input();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Sum of two matrices\n";
        cout << "2. Product of two matrices\n";
        cout << "3. Transpose of first matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    cout << "Enter rows and columns for second matrix: ";
                    cin >> rows2 >> cols2;
                    Matrix m2(rows2, cols2);
                    m2.input();
                    cout << "First Matrix:\n";
                    m1.display();
                    cout << "Second Matrix:\n";
                    m2.display();
                    Matrix sumResult = m1.sum(m2);
                    cout << "Sum of matrices:\n";
                    sumResult.display();
                    break;
                }

                case 2: {
                    cout << "Enter rows and columns for second matrix: ";
                    cin >> rows2 >> cols2;
                    Matrix m2(rows2, cols2);
                    m2.input();
                    cout << "First Matrix:\n";
                    m1.display();
                    cout << "Second Matrix:\n";
                    m2.display();
                    Matrix prodResult = m1.product(m2);
                    cout << "Product of matrices:\n";
                    prodResult.display();
                    break;
                }

                case 3: {
                    cout << "Original Matrix:\n";
                    m1.display();
                    Matrix transResult = m1.transpose();
                    cout << "Transpose of matrix:\n";
                    transResult.display();
                    break;
                }

                case 4:
                    cout << "Exiting...\n";
                    return 0;

                default:
                    cout << "Invalid choice! Try again.\n";
            }
        } catch (const char* error) {
            cout << "Error: " << error << endl;
        }
    }

    return 0;
}