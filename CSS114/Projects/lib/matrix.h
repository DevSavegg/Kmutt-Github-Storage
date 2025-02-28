// matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>

using namespace std;

class Matrix {
    public:
        // Constructor
        Matrix(size_t rows, size_t cols);

        // Element access
        double& at(size_t row, size_t col);
        const double& at(size_t row, size_t col) const;

        // Swap helper
        void swapRows(size_t row1, size_t row2);

        // Getters
        size_t numRows() const;
        size_t numCols() const;
        
        // Operator overload (+, -, *)
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;

        // Determinant (only for square matrix)
        double determinant() const;

        // Cofactor (only for square matrix)
        double cofactor(size_t row, size_t col) const;

        // Augment the matrix with a vector
        Matrix augment(const vector<double>& vec) const;

        // Transpose the matrix
        Matrix transpose() const;

        // Is matrix singular (determinant nearly zero) (only for square matrix)
        bool isSingular() const;
    private:
        size_t rows;
        size_t cols;

        // 1D vector to store the matrix elements
        vector<double> data;

        // Helper function to create a submatrix by excluding the given row and column
        Matrix subMatrix(size_t excludedRow, size_t excludedCol) const;
};

#endif
