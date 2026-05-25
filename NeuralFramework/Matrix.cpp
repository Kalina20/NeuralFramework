#include "Matrix.h"

#include <cstddef>
#include <random>
#include <stdexcept>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows * cols, 0.0) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix shape must be positive");
    }
}

double& Matrix::operator()(int row, int col) {
    return data[static_cast<std::size_t>(row) * cols + col];
}

double Matrix::operator()(int row, int col) const {
    return data[static_cast<std::size_t>(row) * cols + col];
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

Matrix Matrix::multiply(const Matrix& a, const Matrix& b) {
    if (a.getCols() != b.getRows()) {
        throw std::runtime_error("Matrix size mismatch in multiply");
    }

    Matrix result(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < b.getCols(); ++j) {
            double sum = 0.0;
            for (int k = 0; k < a.getCols(); ++k) {
                sum += a(i, k) * b(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

Matrix Matrix::transpose(const Matrix& m) {
    Matrix result(m.getCols(), m.getRows());
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            result(j, i) = m(i, j);
        }
    }
    return result;
}

Matrix Matrix::add(const Matrix& a, const Matrix& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::runtime_error("Matrix size mismatch in add");
    }

    Matrix result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = a(i, j) + b(i, j);
        }
    }
    return result;
}

Matrix Matrix::subtract(const Matrix& a, const Matrix& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::runtime_error("Matrix size mismatch in subtract");
    }

    Matrix result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = a(i, j) - b(i, j);
        }
    }
    return result;
}

Matrix Matrix::hadamard(const Matrix& a, const Matrix& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::runtime_error("Matrix size mismatch in hadamard");
    }

    Matrix result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = a(i, j) * b(i, j);
        }
    }
    return result;
}

Matrix Matrix::scalarMultiply(const Matrix& m, double value) {
    Matrix result(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            result(i, j) = m(i, j) * value;
        }
    }
    return result;
}

Matrix Matrix::sumRows(const Matrix& m) {
    Matrix result(1, m.getCols());
    for (int j = 0; j < m.getCols(); ++j) {
        double sum = 0.0;
        for (int i = 0; i < m.getRows(); ++i) {
            sum += m(i, j);
        }
        result(0, j) = sum;
    }
    return result;
}

void Matrix::randomize() {
    static std::mt19937 rng(42);
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    for (double& value : data) {
        value = dist(rng);
    }
}

void Matrix::fill(double value) {
    for (double& v : data) {
        v = value;
    }
}
