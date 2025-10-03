#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
    Matrix(int rows, int cols);
    ~Matrix();
    int & get(int row, int col);
private:
    int rows;
    int cols;
    int **matrix;
};


#endif //MATRIX_H