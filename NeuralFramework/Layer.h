#pragma once

#include "Matrix.h"

class Layer {
public:
    virtual ~Layer() = default;
    virtual Matrix forward(const Matrix& input) = 0;
    virtual Matrix backward(const Matrix& gradOutput, double learningRate) = 0;
    virtual int inputSize() const = 0;
    virtual int outputSize() const = 0;
};
