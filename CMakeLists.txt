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

enable_testing()

add_executable(
    test_loss
    tests/test_loss.cpp
    src/LossFunctions.cpp
)

add_test(
    NAME LossFunctionsTest
    COMMAND test_loss
)

add_executable(
    test_neuron
    tests/test_neuron.cpp
    src/Neuron.cpp
)

add_test(
    NAME NeuronTest
    COMMAND test_neuron
)

add_executable(
    test_activation
    tests/test_activation.cpp
    src/ActivationFunctions.cpp
)

add_test(
    NAME ActivationFunctionsTest
    COMMAND test_activation
)