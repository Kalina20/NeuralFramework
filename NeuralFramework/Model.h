#pragma once

#include <memory>
#include <vector>

#include "Layer.h"
#include "Loss.h"

class Model {
private:
    std::vector<std::unique_ptr<Layer>> layers;
    MSELoss loss;

public:
    void add(std::unique_ptr<Layer> layer);
    void fit(const Matrix& x, const Matrix& y, int epochs, double learningRate, bool verbose = true);
    Matrix predict(const Matrix& x) const;
    double evaluate(const Matrix& x, const Matrix& y) const;
};
