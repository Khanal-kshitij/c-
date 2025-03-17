#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> mat;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, vector<int>(cols));
    }

    // Function to input matrix
    void inputMatrix() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];
    }

    // Function to display matrix
    void displayMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    // Matrix Addition
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw "Matrix dimensions do not match for addition!";

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
        
        return result;
    }
};

int main() {
    try {
        Matrix m1(2, 2), m2(2, 2);
        m1.inputMatrix();
        m2.inputMatrix();
        
        Matrix sum = m1 + m2;
        cout << "Sum of matrices:\n";
        sum.displayMatrix();
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }
    return 0;
}
