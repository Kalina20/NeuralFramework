#pragma once

#include "Layer.h"

class Dense : public Layer {
private:
    int inSize;
    int outSize;
    Matrix weights;
    Matrix bias;
    Matrix cachedInput;

public:
    Dense(int inputSize, int outputSize);

    Matrix forward(const Matrix& input) override;
    Matrix backward(const Matrix& gradOutput, double learningRate) override;
    int inputSize() const override;
    int outputSize() const override;
};
