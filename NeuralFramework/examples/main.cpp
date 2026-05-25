#include <iostream>
#include <memory>

#include "Activation.h"
#include "Dense.h"
#include "Model.h"

int main() {
    Matrix x(4, 2);
    x(0, 0) = 0.0; x(0, 1) = 0.0;
    x(1, 0) = 0.0; x(1, 1) = 1.0;
    x(2, 0) = 1.0; x(2, 1) = 0.0;
    x(3, 0) = 1.0; x(3, 1) = 1.0;

    Matrix y(4, 1);
    y(0, 0) = 0.0;
    y(1, 0) = 1.0;
    y(2, 0) = 1.0;
    y(3, 0) = 0.0;

    Model model;
    model.add(std::make_unique<Dense>(2, 4));
    model.add(std::make_unique<Activation>(ActivationType::ReLU, 4));
    model.add(std::make_unique<Dense>(4, 1));
    model.add(std::make_unique<Activation>(ActivationType::Sigmoid, 1));

    model.fit(x, y, 5000, 0.1, true);

    Matrix pred = model.predict(x);
    std::cout << "\nPredictions:\n";
    for (int i = 0; i < pred.getRows(); ++i) {
        std::cout << x(i, 0) << " XOR " << x(i, 1) << " -> " << pred(i, 0) << '\n';
    }

    std::cout << "\nFinal MSE: " << model.evaluate(x, y) << '\n';
    return 0;
}
