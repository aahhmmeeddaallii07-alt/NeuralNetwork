cmake_minimum_required(VERSION 3.10)

project(NeuralNetwork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    NeuralNetwork

    src/main.cpp
    src/CLI.cpp
    src/NeuralNetwork.cpp
    src/Layer.cpp
    src/Neuron.cpp
    src/ActivationFunctions.cpp
    src/LossFunctions.cpp
    src/Trainer.cpp
    src/Dataset.cpp
    src/DatasetGenerator.cpp
    src/Metrics.cpp
    src/ModelSerializer.cpp
    src/CSVLoader.cpp
    src/Matrix.cpp
)