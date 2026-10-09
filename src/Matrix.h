#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
class Matrix
{
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;
public:
    Matrix(int rows, int cols);
    void set(int row, int col, double value);
    double get(int row, int col) const;
    int getRows() const;
    int getCols() const;
    void print() const;
    Matrix add(const Matrix& other) const;
    Matrix subtract(const Matrix& other) const;
    Matrix multiply(double scalar) const;
    Matrix multiply(const Matrix& other) const;
};

#endif