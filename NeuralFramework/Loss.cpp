#include "Loss.h"

#include <stdexcept>

namespace {
double safeCount(const Matrix& m) {
    return static_cast<double>(m.getRows() * m.getCols());
}
}

double MSELoss::value(const Matrix& yTrue, const Matrix& yPred) const {
    if (yTrue.getRows() != yPred.getRows() || yTrue.getCols() != yPred.getCols()) {
        throw std::runtime_error("MSE value size mismatch");
    }

    double sum = 0.0;
    for (int i = 0; i < yTrue.getRows(); ++i) {
        for (int j = 0; j < yTrue.getCols(); ++j) {
            const double diff = yPred(i, j) - yTrue(i, j);
            sum += diff * diff;
        }
    }
    return sum / safeCount(yTrue);
}

Matrix MSELoss::gradient(const Matrix& yTrue, const Matrix& yPred) const {
    if (yTrue.getRows() != yPred.getRows() || yTrue.getCols() != yPred.getCols()) {
        throw std::runtime_error("MSE gradient size mismatch");
    }

    Matrix grad(yTrue.getRows(), yTrue.getCols());
    const double scale = 2.0 / safeCount(yTrue);

    for (int i = 0; i < yTrue.getRows(); ++i) {
        for (int j = 0; j < yTrue.getCols(); ++j) {
            grad(i, j) = (yPred(i, j) - yTrue(i, j)) * scale;
        }
    }

    return grad;
}
