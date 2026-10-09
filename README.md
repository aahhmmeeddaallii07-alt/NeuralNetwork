# Neural Network from Scratch in C++ #

A neural network implemented from scratch in C++ without using machine learning frameworks.

# Overview #

This project implements the fundamental components of a neural network from the ground up.

The goal is to understand how neural networks work internally, including forward propagation, backpropagation, gradient descent, training, evaluation and model persistence.

## Features ##

- Vector operations
- Matrix operations
- Activation functions
  - Sigmoid
  - ReLU
  - Tanh
- Neuron implementation
- Layer implementation
- Multi-layer neural network
- Forward propagation
- Backpropagation
- Gradient descent
- Mean Squared Error
- Dataset management
- Train/Test split
- CSV dataset loading
- Synthetic dataset generation
- Model evaluation
  - Accuracy
  - Precision
  - Recall
  - F1-score
  - Confusion Matrix
- Model saving and loading
- Command Line Interface

## Project Architecture ##

```text
NeuralNetwork/
├── src/
│   ├── ActivationFunctions.cpp
│   ├── ActivationFunctions.h
│   ├── CLI.cpp
│   ├── CLI.h
│   ├── CSVLoader.cpp
│   ├── CSVLoader.h
│   ├── Dataset.cpp
│   ├── Dataset.h
│   ├── DatasetGenerator.cpp
│   ├── DatasetGenerator.h
│   ├── Layer.cpp
│   ├── Layer.h
│   ├── LossFunctions.cpp
│   ├── LossFunctions.h
│   ├── Matrix.cpp
│   ├── Matrix.h
│   ├── Metrics.cpp
│   ├── Metrics.h
│   ├── ModelSerializer.cpp
│   ├── ModelSerializer.h
│   ├── NeuralNetwork.cpp
│   ├── NeuralNetwork.h
│   ├── Neuron.cpp
│   ├── Neuron.h
│   ├── Trainer.cpp
│   └── Trainer.h
│
├── data/
├── models/
├── tests/
├── README.md
└── NeuralNetwork.exe

## Build with CMake

Requirements:
- CMake
- A C++17-compatible compiler
- MinGW Makefiles when using MinGW on Windows

Configure the project from the repository root:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
```

Build:

```powershell
cmake --build build
```

## Run the application ##

Display available commands:

```powershell
.\build\NeuralNetwork.exe
```

Train the model:

```powershell
.\build\NeuralNetwork.exe train
```

Predict a sample:

```powershell
.\build\NeuralNetwork.exe predict 0.3 0.7
```

Evaluate the model:

```powershell
.\build\NeuralNetwork.exe metrics
```

## Run automated tests ##

```powershell
ctest --test-dir build --output-on-failure
```

The test suite covers loss functions, neuron calculations, and activation functions.