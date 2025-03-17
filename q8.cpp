#include <iostream>
using namespace std;

class Matrix {
public:
    int mat[3][3];
    
    void input() {
        cout << "Enter matrix elements (3x3):\n";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> mat[i][j];
    }
    
    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    Matrix sum(Matrix m) {
        Matrix result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
        return result;
    }

    Matrix product(Matrix m) {
        Matrix result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
            }
        return result;
    }

    Matrix transpose() {
        Matrix result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                result.mat[i][j] = mat[j][i];
        return result;
    }
};

int main() {
    Matrix m1, m2, result;
    m1.input();
    m2.input();

    result = m1.sum(m2);
    cout << "Sum of matrices:\n";
    result.display();

    result = m1.product(m2);
    cout << "Product of matrices:\n";
    result.display();

    result = m1.transpose();
    cout << "Transpose of first matrix:\n";
    result.display();

    return 0;
}
