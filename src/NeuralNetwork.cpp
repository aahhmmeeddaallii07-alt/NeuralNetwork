#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{
}

void NeuralNetwork::addLayer(
    int inputSize,
    int neuronCount,
    double (*activation)(double),
    double (*activationDerivative)(double)
)
{
    layers.emplace_back(
        inputSize,
        neuronCount,
        activation,
        activationDerivative
    );
}

std::vector<double> NeuralNetwork::forward(
    const std::vector<double>& inputs
)
{
    std::vector<double> current = inputs;

    for (Layer& layer : layers)
    {
        current = layer.forward(current);
    }

    return current;
}

std::vector<double> NeuralNetwork::backward(
    const std::vector<double>& outputGradients,
    double learningRate
)
{
    std::vector<double> currentGradients =
        outputGradients;

    for (
        int i = static_cast<int>(layers.size()) - 1;
        i >= 0;
        i--
    )
    {
        currentGradients =
            layers[i].backward(
                currentGradients,
                learningRate
            );
    }

    return currentGradients;
}

int NeuralNetwork::getLayerCount() const
{
    return static_cast<int>(layers.size());
}
std::vector<Layer>& NeuralNetwork::getLayers()
{
    return layers;
}
const std::vector<Layer>& NeuralNetwork::getLayers() const
{
    return layers;
}