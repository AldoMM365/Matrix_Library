#include "Matrix.h"

#include <cstdlib>

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


int & Matrix::get(int row, int col) {
    return matrix[row][col];
}
