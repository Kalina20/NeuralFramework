#pragma once

#include "Layer.h"

enum class ActivationType {
    ReLU,
    Sigmoid
};

class Activation : public Layer {
private:
    ActivationType type;
    int features;
    Matrix cachedInput;

public:
    explicit Activation(ActivationType type, int features = -1);

    Matrix forward(const Matrix& input) override;
    Matrix backward(const Matrix& gradOutput, double learningRate) override;
    int inputSize() const override;
    int outputSize() const override;
};
