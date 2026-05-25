#pragma once
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<double> data;

public:
    Matrix(int rows, int cols);

    double& operator()(int row, int col);
    double operator()(int row, int col) const;

    int getRows() const;
    int getCols() const;

    static Matrix multiply(const Matrix& a, const Matrix& b);
    static Matrix transpose(const Matrix& m);
    static Matrix add(const Matrix& a, const Matrix& b);
    static Matrix subtract(const Matrix& a, const Matrix& b);
    static Matrix hadamard(const Matrix& a, const Matrix& b);
    static Matrix scalarMultiply(const Matrix& m, double value);
    static Matrix sumRows(const Matrix& m);

    void randomize();
    void fill(double value);
};
