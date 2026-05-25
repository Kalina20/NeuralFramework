#include "Dense.h"

#include <stdexcept>

Dense::Dense(int inputSize, int outputSize)
    : inSize(inputSize),
      outSize(outputSize),
      weights(inputSize, outputSize),
      bias(1, outputSize),
      cachedInput(1, inputSize) {
    weights.randomize();
    bias.fill(0.0);
}

int Dense::inputSize() const {
    return inSize;
}

int Dense::outputSize() const {
    return outSize;
}

Matrix Dense::forward(const Matrix& input) {
    if (input.getCols() != weights.getRows()) {
        throw std::runtime_error("Dense forward size mismatch");
    }

    cachedInput = input;
    Matrix z = Matrix::multiply(input, weights);

    for (int i = 0; i < z.getRows(); ++i) {
        for (int j = 0; j < z.getCols(); ++j) {
            z(i, j) += bias(0, j);
        }
    }

    return z;
}

Matrix Dense::backward(const Matrix& gradOutput, double learningRate) {
    Matrix dW = Matrix::multiply(Matrix::transpose(cachedInput), gradOutput);
    Matrix db = Matrix::sumRows(gradOutput);
    Matrix gradInput = Matrix::multiply(gradOutput, Matrix::transpose(weights));

    Matrix scaledDW = Matrix::scalarMultiply(dW, learningRate);
    Matrix scaledDb = Matrix::scalarMultiply(db, learningRate);

    weights = Matrix::subtract(weights, scaledDW);
    bias = Matrix::subtract(bias, scaledDb);

    return gradInput;
}
