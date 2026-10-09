#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>

#include "Layer.h"

class NeuralNetwork
{
private:
    std::vector<Layer> layers;

public:
    NeuralNetwork();

    void addLayer(
        int inputSize,
        int neuronCount,
        double (*activation)(double),
        double (*activationDerivative)(double)
    );

    std::vector<double> forward(
        const std::vector<double>& inputs
    );

    std::vector<double> backward(
        const std::vector<double>& outputGradients,
        double learningRate
    );

    int getLayerCount() const;
    std::vector<Layer>& getLayers();
    const std::vector<Layer>& getLayers() const;
};

#endif