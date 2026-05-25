# NeuralFramework (C++)

A minimal neural-network framework written in pure C++ (no third-party ML libraries).

## Features
- Build dense (fully connected) models
- Train with backpropagation
- Predict and evaluate using MSE

## Build with CMake
```bash
cmake -S NeuralFramework -B build
cmake --build build --config Release
```

## Run example
The example in `NeuralFramework/main.cpp` trains a small XOR model.
