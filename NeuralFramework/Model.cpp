#include "Model.h"

#include <iostream>
#include <stdexcept>

void Model::add(std::unique_ptr<Layer> layer) {
    if (!layers.empty()) {
        const int prevOut = layers.back()->outputSize();
        const int curIn = layer->inputSize();
        if (prevOut > 0 && curIn > 0 && prevOut != curIn) {
            throw std::runtime_error("Layer size mismatch in architecture");
        }
    }
    layers.push_back(std::move(layer));
}

void Model::fit(const Matrix& x, const Matrix& y, int epochs, double learningRate, bool verbose) {
    if (layers.empty()) {
        throw std::runtime_error("Model has no layers");
    }

    for (int epoch = 1; epoch <= epochs; ++epoch) {
        Matrix current = x;
        for (const auto& layer : layers) {
            current = layer->forward(current);
        }

        const double currentLoss = loss.value(y, current);
        Matrix grad = loss.gradient(y, current);

        for (auto it = layers.rbegin(); it != layers.rend(); ++it) {
            grad = (*it)->backward(grad, learningRate);
        }

        if (verbose && (epoch == 1 || epoch % 500 == 0 || epoch == epochs)) {
            std::cout << "Epoch " << epoch << "/" << epochs << ", loss=" << currentLoss << '\n';
        }
    }
}

Matrix Model::predict(const Matrix& x) const {
    if (layers.empty()) {
        throw std::runtime_error("Model has no layers");
    }

    Matrix current = x;
    for (const auto& layer : layers) {
        current = layer->forward(current);
    }
    return current;
}

double Model::evaluate(const Matrix& x, const Matrix& y) const {
    Matrix yPred = predict(x);
    return loss.value(y, yPred);
}
