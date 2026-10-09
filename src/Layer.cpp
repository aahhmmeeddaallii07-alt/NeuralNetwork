#include "Layer.h"

#include <stdexcept>

Layer::Layer(
    int inputSize,
    int neuronCount,
    double (*activation)(double),
    double (*activationDerivative)(double)
)
{
    if (inputSize <= 0 || neuronCount <= 0)
    {
        throw std::invalid_argument(
            "Les dimensions doivent etre positives."
        );
    }

    if (activation == nullptr ||
        activationDerivative == nullptr)
    {
        throw std::invalid_argument(
            "Les fonctions d'activation sont obligatoires."
        );
    }

    this->activation = activation;
    this->activationDerivative = activationDerivative;

    for (int i = 0; i < neuronCount; i++)
    {
        neurons.emplace_back(inputSize);
    }
}

void Layer::setWeight(
    int neuronIndex,
    int weightIndex,
    double value
)
{
    if (
        neuronIndex < 0 ||
        neuronIndex >= static_cast<int>(neurons.size())
    )
    {
        throw std::out_of_range(
            "Indice du neurone invalide."
        );
    }

    neurons[neuronIndex].setWeight(
        weightIndex,
        value
    );
}

void Layer::setBias(
    int neuronIndex,
    double value
)
{
    if (
        neuronIndex < 0 ||
        neuronIndex >= static_cast<int>(neurons.size())
    )
    {
        throw std::out_of_range(
            "Indice du neurone invalide."
        );
    }

    neurons[neuronIndex].setBias(value);
}

std::vector<double> Layer::forward(
    const std::vector<double>& inputs
)
{
    std::vector<double> outputs;

    for (Neuron& neuron : neurons)
    {
        outputs.push_back(
            neuron.forward(
                inputs,
                activation
            )
        );
    }

    return outputs;
}

std::vector<double> Layer::backward(
    const std::vector<double>& outputGradients,
    double learningRate
)
{
    if (
        outputGradients.size() != neurons.size()
    )
    {
        throw std::invalid_argument(
            "Le nombre de gradients doit correspondre au nombre de neurones."
        );
    }

    std::vector<double> inputGradients;

    for (size_t i = 0; i < neurons.size(); i++)
    {
        std::vector<double> gradients =
            neurons[i].backward(
                outputGradients[i],
                activationDerivative,
                learningRate
            );

        if (inputGradients.empty())
        {
            inputGradients =
                std::vector<double>(
                    gradients.size(),
                    0.0
                );
        }

        for (size_t j = 0; j < gradients.size(); j++)
        {
            inputGradients[j] += gradients[j];
        }
    }

    return inputGradients;
}

int Layer::getNeuronCount() const
{
    return static_cast<int>(neurons.size());
}
std::vector<Neuron>& Layer::getNeurons()
{
    return neurons;
}
const std::vector<Neuron>& Layer::getNeurons() const
{
    return neurons;
}