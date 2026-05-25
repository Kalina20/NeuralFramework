#pragma once

#include "Matrix.h"

class MSELoss {
public:
    double value(const Matrix& yTrue, const Matrix& yPred) const;
    Matrix gradient(const Matrix& yTrue, const Matrix& yPred) const;
};
