#ifndef MATRIX_H
#define MATRIX_H
#include <initializer_list>

class Matrix {
public:
    Matrix(int rows, int cols);
    ~Matrix();
    int & at(int row, int col);
    Matrix& operator=(std::initializer_list<std::initializer_list<int>> list);
private:
    int rows;
    int cols;
    int **matrix;
};


#endif //MATRIX_H