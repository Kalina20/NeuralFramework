#include "Activation.h"

#include <cmath>

Activation::Activation(ActivationType type, int features) : type(type), features(features), cachedInput(1, 1) {
}

Matrix Activation::forward(const Matrix& input) {
    cachedInput = input;
    Matrix output(input.getRows(), input.getCols());

    for (int i = 0; i < input.getRows(); ++i) {
        for (int j = 0; j < input.getCols(); ++j) {
            const double x = input(i, j);
            if (type == ActivationType::ReLU) {
                output(i, j) = x > 0.0 ? x : 0.0;
            } else {
                output(i, j) = 1.0 / (1.0 + std::exp(-x));
            }
        }
    }

    return output;
}

Matrix Activation::backward(const Matrix& gradOutput, double learningRate) {
    (void)learningRate;

    Matrix gradInput(gradOutput.getRows(), gradOutput.getCols());
    for (int i = 0; i < gradOutput.getRows(); ++i) {
        for (int j = 0; j < gradOutput.getCols(); ++j) {
            const double x = cachedInput(i, j);
            double derivative = 0.0;

            if (type == ActivationType::ReLU) {
                derivative = x > 0.0 ? 1.0 : 0.0;
            } else {
                const double s = 1.0 / (1.0 + std::exp(-x));
                derivative = s * (1.0 - s);
            }

            gradInput(i, j) = gradOutput(i, j) * derivative;
        }
    }

    return gradInput;
}

int Activation::inputSize() const {
    return features;
}

int Activation::outputSize() const {
    return features;
}
