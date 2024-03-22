/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>

const int N = 3; // Assuming N is a static constant

void readMatrixFromFile(int matrix[N][N], const std::string& filename, int matrixNumber) {
    std::ifstream file(filename);
    if (file.is_open()) {
        // Skip lines based on matrixNumber to reach the desired matrix
        for (int i = 0; i < matrixNumber * N; ++i) {
            std::string line;
            std::getline(file, line);
        }

        // Read the matrix data
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                file >> matrix[i][j];
            }
        }

        file.close();
    } else {
        std::cerr << "Unable to open file.";
    }
}

void printMatrix(const int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void addMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void updateMatrixElement(int matrix[N][N], int row, int col, int newValue) {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column.";
    }
}

int getMaxValue(const int matrix[N][N]) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

void transposeMatrix(const int matrix[N][N], int transposed[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
}

int main() {
    const std::string filename = "matrix_input.txt";
    int matrix1[N][N], matrix2[N][N], result[N][N], transposed[N][N];

    // Read matrix1 from file
    readMatrixFromFile(matrix1, filename, 0);

    // Read matrix2 from file
    readMatrixFromFile(matrix2, filename, 1);

    std::cout << "Matrix 1:\n";
    printMatrix(matrix1);

    std::cout << "\nMatrix 2:\n";
    printMatrix(matrix2);

    // Add matrices
    addMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix 1 + Matrix 2:\n";
    printMatrix(result);

    // Multiply matrices
    multiplyMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix 1 * Matrix 2:\n";
    printMatrix(result);

    // Subtract matrices
    subtractMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix 1 - Matrix 2:\n";
    printMatrix(result);

    // Update matrix element
    updateMatrixElement(matrix1, 1, 1, 99);
    std::cout << "\nMatrix 1 after updating element (1, 1) with 99:\n";
    printMatrix(matrix1);

    // Get max value of matrix
    int maxVal = getMaxValue(matrix1);
    std::cout << "\nMax value in Matrix 1: " << maxVal << "\n";

    // Transpose matrix
    transposeMatrix(matrix1, transposed);
    std::cout << "\nTranspose of Matrix 1:\n";
    printMatrix(transposed);

    return 0;
}
