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
    if (matrix == nullptr) {
        throw std::runtime_error("Uninitialized matrix");
    }
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Elements are out of range");
    }
    return matrix[row][col];
}

Matrix & Matrix::operator=(std::initializer_list<std::initializer_list<int>> list){
    int rowIndex = 0;
    int columnIndex = 0;
    if (list.size() != rows)
        throw std::invalid_argument("Provided brace-enclosed initializer list does not match current numer of rows");

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
