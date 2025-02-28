#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <cstdlib>
#include <cctype>
#include <limits>
#include "lib/matrix.h"

using namespace std;

// Gauss Elimination Method
vector<double> gaussElimination(const Matrix &A, const vector<double> &b);

// Gauss-Jordan elimination
vector<double> gaussJordan(const Matrix &A, const vector<double> &b);

// Inverse matrix
Matrix inverseMatrix(const Matrix &A);

// LU Factorization
tuple<Matrix, Matrix, vector<size_t>> luFactorization(const Matrix &A);
vector<double> forwardSubstitution(const Matrix &L, const vector<double> &b);
vector<double> backwardSubstitution(const Matrix &U, const vector<double> &y);
vector<double> applyPermutation(const vector<double> &b, const vector<size_t> &perm);

// Display
void printMatrix(const Matrix &matrix);
int printTitleScreen();
Matrix fillMatrixInteractive();
vector<double> fillVectorInteractive(size_t rowSize);

int main() {
    while (true) {
        int choice = printTitleScreen();
        Matrix A = fillMatrixInteractive();

        if (choice == 1) {
            vector<double> b = fillVectorInteractive(A.numRows());
            vector<double> result = gaussElimination(A, b);

            cout << "Gauss Elimination Solution:" << endl;
            for (size_t i = 0; i < result.size(); ++i) {
                cout << "x" << i << " = " << result[i] << endl;
            }
        } else if (choice == 2) {
            vector<double> b = fillVectorInteractive(A.numRows());
            vector<double> result = gaussJordan(A, b);

            cout << "Gauss-Jordan Elimination Solution:" << endl;
            for (size_t i = 0; i < result.size(); ++i) {
                cout << "x" << i << " = " << result[i] << endl;
            }
        } else if (choice == 3) {
            auto result = luFactorization(A);

            Matrix L = get<0>(result);
            Matrix U = get<1>(result);
            vector<size_t> perm = get<2>(result);

            cout << "U Solution:" << endl;
            printMatrix(U);
            cout << endl << "L Solution:" << endl;
            printMatrix(L);
            cout << endl << "Permutation:" << endl;
            for (size_t i = 0; i < perm.size(); ++i) {
                cout << perm[i] << "\t";
            }
            cout << endl;

            char userInput;
            cout << "Would you like to use this to solve the linear problem? [Y, n] : ";
            cin >> userInput;

            userInput = tolower(userInput);

            if (userInput == 'y') {
                vector<double> b = fillVectorInteractive(A.numRows());

                //Permute b to get pb = P*b
                vector<double> pb = applyPermutation(b, perm);

                // Solve Ly = b using forward substitution
                vector<double> y = forwardSubstitution(L, pb);

                // Solve Ux = y using backward substitution
                vector<double> x = backwardSubstitution(U, y);

                cout << "LU Factorization linear problem result: " << endl;
                for (size_t i = 0; i < x.size(); ++i) {
                    cout << "x" << i << " = " << x[i] << endl;
                }
            }
        } else if (choice == 4) {
            Matrix result = inverseMatrix(A);
            cout << "Inverse Matrix Solution:" << endl;
            printMatrix(result);
        } else {
            break;
        }

        cout << "Press any key to continue..." << endl;
        while (true) {
            if (cin.get()) {
                break;  // Break the loop when a key is pressed
            }
        }
    }
    
    return 0;
}

vector<double> gaussElimination(const Matrix &A, const vector<double> &b) {
    // Ensure A is square and matches b's dimension
    if (A.numRows() != A.numCols() || b.size() != A.numRows()) {
        throw invalid_argument("Matrix A must be square and vector b must have matching dimensions.");
    }
    
    // Check if the matrix is singular
    if (A.isSingular()) {
        throw runtime_error("Matrix is singular or nearly singular.");
    }

    // Create an augmented matrix
    Matrix M = A.augment(b);
    size_t n = A.numRows();

    // Forward elimination with partial pivoting
    for (size_t i = 0; i < n; ++i) {
        // Find the pivot row
        size_t pivotRow = i;
        double maxVal = abs(M.at(i, i));

        for (size_t k = i + 1; k < n; ++k) {
            if (abs(M.at(k, i)) > maxVal) {
                maxVal = abs(M.at(k, i));
                pivotRow = k;
            }
        }

        // Check for nearly singular pivot
        if (abs(M.at(pivotRow, i)) < 1e-9) {
            throw runtime_error("Matrix is singular or nearly singular during elimination.");
        }

        // Swap rows if needed
        if (pivotRow != i) {
            M.swapRows(i, pivotRow);
        }

        // Eliminate entries below the pivot
        for (size_t j = i + 1; j < n; ++j) {
            double factor = M.at(j, i) / M.at(i, i);

            for (size_t k = i; k < n + 1; ++k) {
                M.at(j, k) -= factor * M.at(i, k);
            }
        }
    }

    // Back substitution
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        double sum = M.at(i, n); // Start with the augmented column value

        for (size_t j = i + 1; j < n; ++j) {
            sum -= M.at(i, j) * x[j];
        }

        x[i] = sum / M.at(i, i);
    }
    return x;
}

vector<double> gaussJordan(const Matrix &A, const vector<double> &b) {
    size_t n = A.numRows();
    if (A.numCols() != n || b.size() != n)
        throw invalid_argument("Matrix A must be square and vector b must have matching dimensions.");
    
    // Check if the matrix is singular
    if (A.isSingular())
        throw runtime_error("Matrix is singular or nearly singular.");

    // Create an augmented matrix
    Matrix M = A.augment(b);

    // Process each pivot column
    for (size_t i = 0; i < n; ++i) {
        // Find the pivot row
        size_t pivotRow = i;
        double maxVal = abs(M.at(i, i));
        for (size_t k = i + 1; k < n; ++k) {
            if (abs(M.at(k, i)) > maxVal) {
                maxVal = abs(M.at(k, i));
                pivotRow = k;
            }
        }
        // Check for a nearly zero pivot element
        if (abs(M.at(pivotRow, i)) < 1e-9)
            throw runtime_error("Matrix is singular or nearly singular during elimination.");
        
        // Swap current row with the pivot row (if needed)
        if (pivotRow != i) {
            M.swapRows(i, pivotRow);
        }
        
        // Normalize the pivot row so that the pivot becomes 1
        double pivot = M.at(i, i);
        for (size_t j = i; j < n + 1; ++j) {
            M.at(i, j) /= pivot;
        }
        
        // Eliminate the pivot column entry in all other rows
        for (size_t r = 0; r < n; ++r) {
            if (r != i) {
                double factor = M.at(r, i);
                for (size_t j = i; j < n + 1; ++j) {
                    M.at(r, j) -= factor * M.at(i, j);
                }
            }
        }
    }
    
    // Extract the solution vector from the last column
    vector<double> x(n, 0.0);
    for (size_t i = 0; i < n; ++i) {
        x[i] = M.at(i, n);
    }
    return x;
}

Matrix inverseMatrix(const Matrix &A) {
    if (A.numRows() != A.numCols()) {
        throw invalid_argument("Only square matrices have inverses.");
    }

    size_t n = A.numRows();

    // Check for singularity
    if (A.isSingular()) {
        throw runtime_error("Matrix is singular and cannot be inverted.");
    }

    // Create an augmented matrix
    Matrix aug(n, 2 * n);
    
    // Copy A into the left half of aug and set up the identity matrix in the right half
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            aug.at(i, j) = A.at(i, j);
        }

        for (size_t j = n; j < 2 * n; ++j) {
            aug.at(i, j) = (j - n == i) ? 1.0 : 0.0;
        }
    }

    // Perform Gauss–Jordan elimination.
    for (size_t i = 0; i < n; ++i) {
        // Find pivot row with maximum absolute value in column i
        size_t pivotRow = i;
        double maxVal = abs(aug.at(i, i));

        for (size_t k = i + 1; k < n; ++k) {
            if (abs(aug.at(k, i)) > maxVal) {
                maxVal = abs(aug.at(k, i));
                pivotRow = k;
            }
        }

        if (abs(aug.at(pivotRow, i)) < 1e-9) {
            throw runtime_error("Matrix is singular or nearly singular.");
        }

        // Swap current row with pivot row if necessary
        if (pivotRow != i) {
            aug.swapRows(i, pivotRow);
        }

        // Normalize the pivot row (make the pivot equal to 1)
        double pivot = aug.at(i, i);

        for (size_t j = i; j < 2 * n; ++j) {
            aug.at(i, j) /= pivot;
        }

        // Eliminate the pivot column entries in all other rows
        for (size_t r = 0; r < n; ++r) {
            if (r != i) {
                double factor = aug.at(r, i);

                for (size_t j = i; j < 2 * n; ++j) {
                    aug.at(r, j) -= factor * aug.at(i, j);
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix (right half)
    Matrix inv(n, n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            inv.at(i, j) = aug.at(i, j + n);
        }
    }
    return inv;
}

tuple<Matrix, Matrix, vector<size_t>> luFactorization(const Matrix &A) {
    if (A.numRows() != A.numCols()) {
        throw invalid_argument("LU factorization is only defined for square matrices.");
    }

    size_t n = A.numRows();
    Matrix U = A;          // Copy of A to be transformed into U
    Matrix L(n, n);        // Lower triangular matrix (initially zeros)
    vector<size_t> perm(n);  // Permutation vector

    for (size_t i = 0; i < n; ++i) {
        perm[i] = i;
    }

    // Process each column
    for (size_t k = 0; k < n; ++k) {
        // Find pivot in column k
        double maxVal = abs(U.at(k, k));
        size_t pivotRow = k;

        for (size_t i = k + 1; i < n; ++i) {
            if (abs(U.at(i, k)) > maxVal) {
                maxVal = abs(U.at(i, k));
                pivotRow = i;
            }
        }

        // Check for nearly zero pivot
        if (abs(U.at(pivotRow, k)) < 1e-9) {
            throw runtime_error("Matrix is singular or nearly singular.");
        }

        // Swap rows in U if needed
        if (pivotRow != k) {
            U.swapRows(k, pivotRow);
            swap(perm[k], perm[pivotRow]);

            // Swap corresponding rows in L for columns [0, k-1]
            for (size_t j = 0; j < k; ++j) {
                swap(L.at(k, j), L.at(pivotRow, j));
            }
        }

        // For rows below pivot, eliminate entries
        for (size_t i = k + 1; i < n; ++i) {
            double multiplier = U.at(i, k) / U.at(k, k);
            L.at(i, k) = multiplier;  // Store the multiplier in L

            for (size_t j = k; j < n; ++j) {
                U.at(i, j) -= multiplier * U.at(k, j);
            }
        }
    }

    // Set the diagonal of L to 1
    for (size_t i = 0; i < n; ++i) {
        L.at(i, i) = 1.0;
    }

    return make_tuple(L, U, perm);
}

vector<double> forwardSubstitution(const Matrix &L, const vector<double> &b) {
    size_t n = L.numRows();
    vector<double> y(n, 0.0);

    for (size_t i = 0; i < n; ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < i; ++j) {
            sum += L.at(i, j) * y[j];
        }
        // Because L's diagonal is 1.0 in the Doolittle approach, or if not, adjust accordingly
        y[i] = (b[i] - sum) / L.at(i, i);
    }
    return y;
}

vector<double> backwardSubstitution(const Matrix &U, const vector<double> &y) {
    size_t n = U.numRows();
    vector<double> x(n, 0.0);

    for (int i = static_cast<int>(n) - 1; i >= 0; --i) {
        double sum = 0.0;
        for (size_t j = i + 1; j < n; ++j) {
            sum += U.at(i, j) * x[j];
        }
        x[i] = (y[i] - sum) / U.at(i, i);
    }
    return x;
}

vector<double> applyPermutation(const vector<double> &b, const vector<size_t> &perm) {
    size_t n = b.size();
    vector<double> pb(n);
    for (size_t i = 0; i < n; ++i) {
        pb[i] = b[perm[i]];
    }
    return pb;
}

void printMatrix(const Matrix &matrix) {
    cout << "---------------------------" << endl;
    for (size_t i = 0; i < matrix.numRows(); i++) {
        for (size_t j = 0; j < matrix.numCols(); j++) {
            double value = matrix.at(i, j);
            // Check if the value is close enough to an integer.
            if (fabs(value - round(value)) < 1e-6) {
                cout << setw(10) << static_cast<int>(round(value));
            } else {
                cout << setw(10) << fixed << setprecision(3) << value;
            }
        }
        cout << endl;
    }
}

int printTitleScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    cout << "__| |_________________________________| |__" << endl;
    cout << "__   _________________________________   __" << endl;
    cout << "  | |                                 | |  " << endl;
    cout << "  | | __  __       _        _         | |  " << endl;
    cout << "  | ||  \\/  | __ _| |_ _ __(_)_  __  | |  " << endl;
    cout << "  | || |\\/| |/ _` | __| '__| \\ \\/ /| |  " << endl;
    cout << "  | || |  | | (_| | |_| |  | |>  <    | |  " << endl;
    cout << "  | ||_|  |_|\\__,_|\\__|_|  |_/_/\\_\\ | |  " << endl;
    cout << "__| |_________________________________| |__" << endl;
    cout << "__   _________________________________   __" << endl;
    cout << "  | |                                 | |   " << endl;
    cout << endl << endl;
    cout << "      1. Gauss Elimination" << endl;
    cout << "      2. Gauss-Jordan Elimation" << endl;
    cout << "      3. LU Factorization" << endl;
    cout << "      4. Inverse Matrix" << endl;
    cout << "      0. Exit" << endl;
    cout << endl;
    cout << "      Please select the choice : ";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

Matrix fillMatrixInteractive() {
    // Prompt for matrix dimensions
    cout << "Input rows and columns (m,n) >> ";

    string dims;
    getline(cin, dims);
    istringstream iss(dims);

    size_t rows, cols;

    char comma;

    if (!(iss >> rows >> comma >> cols)) {
        cerr << "Invalid format. Please enter dimensions as m,n" << endl;
        exit(1);
    }
    
    Matrix A(rows, cols);
    // Boolean vector to track which cells have been filled
    vector<bool> filled(rows * cols, false);
    
    // Lambda function to print the matrix
    auto printMatrix = [&A, &filled](int currentRow, int currentCol) {
        cout << "---------------------------" << endl;
        for (size_t i = 0; i < A.numRows(); i++) {
            for (size_t j = 0; j < A.numCols(); j++) {
                size_t idx = i * A.numCols() + j;
                // Highlight the current cell with square brackets.
                if (static_cast<int>(i) == currentRow && static_cast<int>(j) == currentCol) {
                    cout << "[_]\t";
                } 
                // If already filled, print its value.
                else if (filled[idx]) {
                    cout << " " << A.at(i, j) << "\t";
                } 
                // Otherwise, display an underscore.
                else {
                    cout << " _ \t";
                }
            }
            cout << endl;
        }
    };

    // Loop through each matrix cell.
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            printMatrix(i, j);

            cout << "Input the value for cell (" << i+1 << "," << j+1 << ") >> ";
            double value;
            cin >> value;

            A.at(i, j) = value;

            filled[i * cols + j] = true;

            // Clear any leftover input including newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    // Clear the screen and display the final matrix
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return A;
}

vector<double> fillVectorInteractive(size_t rowSize) {
    // Create a new vector of size rowSize, initialized with zeros
    vector<double> vec(rowSize, 0);
    
    // Loop through each element of the vector
    for (size_t i = 0; i < rowSize; i++) {
        // Clear the screen.
        #ifdef _WIN32
                system("cls");
        #else
                system("clear");
        #endif
        // Display the current vector state
        cout << "---------------------------" << endl;
        for (size_t j = 0; j < rowSize; j++) {
            if (j == i)
                cout << "[_]\t";   // Highlight the current element
            else
                cout << " " << vec[j] << "\t";
        }
        cout << "\n---------------------------" << endl;
        
        // Prompt for the current element value
        cout << "Input the value for element " << i + 1 << " >> ";
        double value;
        cin >> value;
        vec[i] = value;
        // Clear any leftover input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // Clear the screen and display the final vector
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return vec;
}