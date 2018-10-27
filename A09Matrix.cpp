/* 
 * File:   A09Matrix.cpp
 * Author: omkar
 *
 * Created on October 27, 2018, 3:33 PM
 */

/*Write C / C++ program for storing matrix.Write functions for
 a) Check whether given matrix is upper triangular or not
 b) Compute summation of diagonal elements
 c) Compute transpose of matrix
 d) Add, subtract and multiply two matrices */

#include<iostream>
#include<cstdlib>
#define SIZE 50
using namespace std;

class Matrix {
private:
    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    size_t noOfRows1;
    size_t noOfColumn1;
    size_t noOfRows2;
    size_t noOfColumn2;

public:
    Matrix();
    void setMatrix1();
    void setMatrix2();
    void displayMatrix1();
    void displayMatrix2();
    void addMatrix();
    void subMatrix();
    void mulMatrix();
    void daigonalSumOfMat();
    void matTranspose();
    void isTriangular();

};

Matrix::Matrix() {
    matrix1[SIZE][SIZE] = 0;
    matrix2[SIZE][SIZE] = 0;
    noOfRows1 = 0;
    noOfColumn1 = 0;
    noOfRows2 = 0;
    noOfColumn2 = 0;

}

void Matrix::setMatrix1() {
    cout << "Enter Number of row in Matrix 1: ";
    cin>>noOfRows1;
    cout << "Enter Number of column in Matrix 1: ";
    cin>>noOfColumn1;

    cout << "Enter the elements of Matrix 1 (row wise) : ";
    for (size_t i = 0; i < noOfRows1; ++i) {
        for (size_t j = 0; j < noOfColumn1; ++j) {
            cin >> matrix1[i][j];
        }
    }

}

void Matrix::setMatrix2() {
    cout << "Enter Number of row in Matrix 2: ";
    cin>>noOfRows2;
    cout << "Enter Number of column in Matrix 2: ";
    cin>>noOfColumn2;

    cout << "Enter the elements of Matrix 2 (row wise) : ";
    for (size_t i = 0; i < noOfRows2; ++i) {
        for (size_t j = 0; j < noOfColumn2; ++j) {
            cin >> matrix2[i][j];
        }
    }
    system("CLEAR");
}

void Matrix::displayMatrix1() {
    cout << "   **Matrix 1** \n";
    for (size_t i = 0; i < noOfRows1; ++i) {
        for (size_t j = 0; j < noOfColumn1; ++j) {
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::displayMatrix2() {
    cout << "   **Matrix 2** \n";
    for (size_t i = 0; i < noOfRows2; ++i) {
        for (size_t j = 0; j < noOfColumn2; ++j) {
            cout << matrix2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::addMatrix() {
    int matSum[SIZE][SIZE];
    if (noOfRows1 == noOfRows2 && noOfColumn1 == noOfColumn2) {
        cout << "  Addition of Matrix1 and Matrix2 \n";
        for (size_t i = 0; i < noOfRows1; ++i) {
            for (size_t j = 0; j < noOfColumn1; ++j) {
                matSum[i][j] = matrix1[i][j] + matrix2[i][j];
                cout << matSum[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cerr << "\n\tAddition of this matrices is not possible !\n";
    }
}

void Matrix::subMatrix() {
    int matSub[SIZE][SIZE];
    if (noOfRows1 == noOfRows2 && noOfColumn1 == noOfColumn2) {
        cout << "  Subtraction of Matrix1 and Matrix2 \n";
        for (size_t i = 0; i < noOfRows1; ++i) {
            for (size_t j = 0; j < noOfColumn1; ++j) {
                matSub[i][j] = matrix1[i][j] - matrix2[i][j];
                cout << matSub[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cerr << "\n\tSubtraction of this matrices is not possible !\n";
    }
}

void Matrix::mulMatrix() {
    int matMul[SIZE][SIZE];

    if (noOfColumn1 == noOfRows2) {
        cout << "  Multiplication of Matrix1 and Matrix2 \n";
        for (size_t i = 0; i < noOfRows1; ++i) {
            for (size_t j = 0; j < noOfColumn1; ++j) {
                matMul[i][j] = 0;
                for (size_t k = 0; k < noOfColumn1; ++k) {
                    matMul[i][j] = matMul[i][j] + (matrix1[i][k] * matrix2[k][j]);

                }
                cout << matMul[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cerr << "\n\tMultiplication of This Matrices is not possible\n";
    }
}

void Matrix::daigonalSumOfMat() {
    int sum = 0;
    if (noOfRows1 == noOfColumn1) {
        for (size_t i = 0; i < noOfRows1; ++i) {
            for (size_t j = 0; j < noOfColumn1; ++j) {
                if (i == j) {
                    sum = sum + matrix1[i][j];
                }
            }
        }
        cout << "Summation of diagonal elements of Matrix 1 = " << sum << endl;
    }

    if (noOfRows2 == noOfColumn2) {
        sum = 0;
        for (size_t i = 0; i < noOfRows2; ++i) {
            for (size_t j = 0; j < noOfColumn2; ++j) {
                if (i == j) {
                    sum = sum + matrix2[i][j];
                }
            }
        }
        cout << "Summation of diagonal elements of Matrix 2 = " << sum << endl;
    }
}

void Matrix::matTranspose() {
    int transMat[SIZE][SIZE];

    cout << "Transpose of Matrix 1 \n";
    for (size_t i = 0; i < noOfColumn1; ++i) {
        for (size_t j = 0; j < noOfRows1; ++j) {
            transMat[i][j] = matrix1[j][i];
            cout << transMat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Transpose of Matrix 2 \n";
    for (size_t i = 0; i < noOfColumn2; ++i) {
        for (size_t j = 0; j < noOfRows2; ++j) {
            transMat[i][j] = matrix2[j][i];
            cout << transMat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::isTriangular() {
    size_t upperCount = 0;
    size_t lowerCount = 0;
    size_t daigonalCount = 0;
    if (noOfRows1 == noOfColumn1) {
        size_t temp = noOfRows1;
        for (size_t i = 0; i < noOfRows1; ++i) {
            for (size_t j = 0; j < noOfColumn1; ++j) {
                if (i == j) {
                    if (matrix1[i][j] != 0)
                        daigonalCount++;
                }

                if (i < j) {
                    if (matrix1[i][j] == 0)
                        lowerCount++;
                }

                if (i > j) {
                    if (matrix1[i][j] == 0)
                        upperCount++;
                }
            }
        }
        if (lowerCount == (temp * (temp - 1) / 2) && upperCount == (temp * (temp - 1) / 2) && daigonalCount == (temp * (temp - 1) / 2)) {
            cout << "The Matrix 1 is Upper and Lower Triangular Matrix.\n";
        } else if (upperCount == (temp * (temp - 1) / 2)) {
            cout << "The Matrix 1 is Upper triangular Matrix.\n";
        } else if (lowerCount == (temp * (temp - 1) / 2)) {
            cout << "The Matrix 1 is Lower triangular Matrix.\n";
        } else {
            cerr << "\n\tMatrix 1 is not triangular Matrix\n";
        }
    } else {
        cerr << "\n\tMatrix 1 is not triangular Matrix\n";
    }
}

int main() {
    Matrix mat;
    mat.setMatrix1();
    mat.setMatrix2();
    mat.displayMatrix1();
    mat.displayMatrix2();
    mat.addMatrix();
    mat.subMatrix();
    mat.mulMatrix();
    mat.daigonalSumOfMat();
    mat.matTranspose();
    mat.isTriangular();
}

