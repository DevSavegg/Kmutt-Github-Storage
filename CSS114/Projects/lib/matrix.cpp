#include "matrix.h"

// Constructor
Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows * cols) {
    // Fill all elements in data with INT_MAX
    fill(data.begin(), data.end(), INT_MAX);
}

// Element access
double& Matrix::at(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw out_of_range("Index out of bounds");
    }
    return data[row * cols + col];
}
const double& Matrix::at(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw out_of_range("Index out of bounds");
    }
    return data[row * cols + col];
}

// Getters
size_t Matrix::numRows() const {
    return rows;
}
size_t Matrix::numCols() const {
    return cols;
}

// Helper function: swap
void Matrix::swapRows(size_t row1, size_t row2) {
    if (row1 >= rows || row2 >= rows)
        throw out_of_range("Row index out of range");

    for (size_t j = 0; j < cols; ++j) {
        swap(at(row1, j), at(row2, j));
    }
}

// Helper function: creates a submatrix by excluding a given row and column
Matrix Matrix::subMatrix(size_t excludedRow, size_t excludedCol) const {
    if (rows <= 1 || cols <= 1)
        throw invalid_argument("Cannot form submatrix from matrix with dimension <= 1");

    Matrix sub(rows - 1, cols - 1);
    size_t r = 0;
    for (size_t i = 0; i < rows; ++i) {
        if (i == excludedRow) continue;
        size_t c = 0;
        for (size_t j = 0; j < cols; ++j) {
            if (j == excludedCol) continue;
            sub.at(r, c) = at(i, j);
            ++c;
        }
        ++r;
    }
    return sub;
}

// Operator overload
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw invalid_argument("Matrix dimensions must agree for addition");

    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw invalid_argument("Matrix dimensions must agree for addition");

    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows)
        throw invalid_argument("Matrix dimensions must agree for multiplication");

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < cols; ++k) {
                sum += this->at(i, k) * other.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }
    return result;
}

// Determinant (only for square matrix)
double Matrix::determinant() const {
    if (rows != cols) {
        throw invalid_argument("Determinant is only defined for square matrices");
    }

    Matrix temp(*this); // work on a copy
    double det = 1.0;
    for (size_t i = 0; i < rows; ++i) {
        // Find pivot row.
        size_t pivotRow = i;
        double maxVal = abs(temp.at(i, i));
        for (size_t k = i + 1; k < rows; ++k) {
            if (abs(temp.at(k, i)) > maxVal) {
                maxVal = abs(temp.at(k, i));
                pivotRow = k;
            }
        }
        // If the pivot element is zero (or nearly zero), the determinant is zero
        if (abs(temp.at(pivotRow, i)) < 1e-9)
            return 0.0;

        // Swap rows if necessary
        if (pivotRow != i) {
            temp.swapRows(i, pivotRow);
            det = -det;
        }
        det *= temp.at(i, i);

        // Eliminate entries below the pivot
        for (size_t j = i + 1; j < rows; ++j) {
            double factor = temp.at(j, i) / temp.at(i, i);
            for (size_t k = i; k < cols; ++k) {
                temp.at(j, k) -= factor * temp.at(i, k);
            }
        }
    }

    return det;
}

// Cofactor
double Matrix::cofactor(size_t row, size_t col) const {
    if (rows != cols)
        throw invalid_argument("Cofactor is only defined for square matrices");

    Matrix sub = subMatrix(row, col);
    double subDet = sub.determinant();
    double sign = ((row + col) % 2 == 0) ? 1.0 : -1.0;
    
    return sign * subDet;
}

// Augment the matrix with a vector
Matrix Matrix::augment(const vector<double>& vec) const {
    if (vec.size() != rows)
        throw invalid_argument("Vector size must match the number of rows in matrix");

    Matrix augmented(rows, cols + 1); // Copy original matrix.
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            augmented.at(i, j) = at(i, j);
        }
        augmented.at(i, cols) = vec[i];
    }
    return augmented;
}

// Transpose the matrix
Matrix Matrix::transpose() const {
    Matrix transposed(cols, rows);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            transposed.at(j, i) = at(i, j);
        }
    }

    return transposed;
}

// Is matrix singular (determinant nearly zero).
bool Matrix::isSingular() const {
    if (rows != cols)
        throw invalid_argument("Singularity is only defined for square matrices");
    return abs(determinant()) < 1e-9;
}