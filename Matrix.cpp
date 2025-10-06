#include "Matrix.h"

#include <cstdlib>
#include <stdexcept>

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        this->matrix[i] = new int[cols];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete matrix[i];
    }
    delete matrix;
}

int & Matrix::at(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Elements are out of range");
    }
    return matrix[row][col];
}

Matrix & Matrix::operator=(std::initializer_list<std::initializer_list<int>> list){
    if (list.size() != rows)
        throw std::invalid_argument("Provided brace-enclosed initializer list does not match current numer of rows");

    int rowIndex = 0;
    int columnIndex = 0;

    for (std::initializer_list<int> row : list) {
        if (row.size() != cols)
                throw std::invalid_argument("Provided brace-enclosed initializer list does not match the current numer of columns at row " + std::to_string(rowIndex));
        columnIndex = 0;
        for (int col: row) {
            matrix[rowIndex][columnIndex] = col;
            columnIndex++;
        }
        rowIndex++;
    }

    return *this;
}

Matrix& Matrix::operator+(Matrix& b) {
    if (rows != b.rows || cols != b.cols) {
        throw std::runtime_error("Cannot add matrices of different sizes");
    }
    Matrix* result = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result->matrix[i][j] = matrix[i][j] + b.matrix[i][j];
        }
    }
    return *result;
}

Matrix& Matrix::operator-(Matrix& b) {
    if (rows != b.rows || cols != b.cols) {
        throw std::runtime_error("Cannot substract matrices of different sizes");
    }
    Matrix* result = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result->matrix[i][j] = matrix[i][j] - b.matrix[i][j];
        }
    }
    return *result;
}

Matrix& Matrix::operator*(Matrix& b) {
    if (cols != b.rows) {
        throw std::runtime_error("The number of columns in the first matrix must be equal to the number of rows in the second matrix");
    }
    Matrix* result = new Matrix(rows, b.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result->matrix[i][j] += matrix[i][k] * b.matrix[k][j];
            }
        }
    }
    return *result;
}

Matrix & Matrix::operator*(int n) {
    Matrix* result = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result->matrix[i][j] = matrix[i][j] * n;
        }
    }
    return *result;
}
