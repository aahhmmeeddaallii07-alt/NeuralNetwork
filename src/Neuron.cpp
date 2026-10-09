#include "Neuron.h"

#include <random>
#include <stdexcept>

Neuron::Neuron(int inputSize)
{
    if (inputSize <= 0)
    {
        throw std::invalid_argument(
            "Le nombre d'inputs doit etre positif."
        );
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);

    weights.resize(inputSize);

    for (double& weight : weights)
    {
        weight = distribution(generator);
    }

    bias = distribution(generator);

    lastZ = 0.0;
    lastOutput = 0.0;
}

void Neuron::setWeight(int index, double value)
{
    if (index < 0 || index >= static_cast<int>(weights.size()))
    {
        throw std::out_of_range(
            "Indice du poids invalide."
        );
    }

    weights[index] = value;
}

void Neuron::setBias(double value)
{
    bias = value;
}

double Neuron::getWeight(int index) const
{
    if (index < 0 || index >= static_cast<int>(weights.size()))
    {
        throw std::out_of_range(
            "Indice du poids invalide."
        );
    }

    return weights[index];
}

double Neuron::getBias() const
{
    return bias;
}
const std::vector<double>& Neuron::getWeights() const
{
    return weights;
}

double Neuron::forward(
    const std::vector<double>& inputs
)
{
    if (inputs.size() != weights.size())
    {
        throw std::invalid_argument(
            "Le nombre d'inputs doit correspondre au nombre de poids."
        );
    }

    lastInputs = inputs;

    lastZ = bias;

    for (size_t i = 0; i < inputs.size(); i++)
    {
        lastZ += inputs[i] * weights[i];
    }

    lastOutput = lastZ;

    return lastOutput;
}

double Neuron::forward(
    const std::vector<double>& inputs,
    double (*activation)(double)
)
{
    double z = forward(inputs);

    lastOutput = activation(z);

    return lastOutput;
}

double Neuron::getLastZ() const
{
    return lastZ;
}

double Neuron::getLastOutput() const
{
    return lastOutput;
}
std::vector<double> Neuron::backward(
    double outputGradient,
    double (*activationDerivative)(double),
    double learningRate
)
{
    double delta =
        outputGradient *
        activationDerivative(lastZ);

    std::vector<double> inputGradients(
        weights.size()
    );

    for (size_t i = 0; i < weights.size(); i++)
    {
        inputGradients[i] =
            delta * weights[i];
    }

    for (size_t i = 0; i < weights.size(); i++)
    {
        double weightGradient =
            delta * lastInputs[i];

        weights[i] -=
            learningRate * weightGradient;
    }

    bias -= learningRate * delta;

    return inputGradients;
}
