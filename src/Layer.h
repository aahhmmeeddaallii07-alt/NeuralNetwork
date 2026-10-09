#ifndef LAYER_H
#define LAYER_H

#include <vector>

#include "Neuron.h"

class Layer
{
private:
    std::vector<Neuron> neurons;

    double (*activation)(double);
    double (*activationDerivative)(double);

public:
    Layer(
        int inputSize,
        int neuronCount,
        double (*activation)(double),
        double (*activationDerivative)(double)
    );

    void setWeight(
        int neuronIndex,
        int weightIndex,
        double value
    );

    void setBias(
        int neuronIndex,
        double value
    );

    std::vector<double> forward(
        const std::vector<double>& inputs
    );

    std::vector<double> backward(
        const std::vector<double>& outputGradients,
        double learningRate
    );

    int getNeuronCount() const;
    std::vector<Neuron>& getNeurons();
    const std::vector<Neuron>& getNeurons() const;
};

#endif