#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron
{
private:
    std::vector<double> weights;
    double bias;

    std::vector<double> lastInputs;
    double lastZ;
    double lastOutput;

public:
    Neuron(int inputSize);

    void setWeight(int index, double value);
    void setBias(double value);

    double getWeight(int index) const;
    double getBias() const;
    const std::vector<double>& getWeights() const;

    double forward(
        const std::vector<double>& inputs
    );

    double forward(
        const std::vector<double>& inputs,
        double (*activation)(double)
    );

    std::vector<double> backward(
        double outputGradient,
        double (*activationDerivative)(double),
        double learningRate
    );

    double getLastZ() const;
    double getLastOutput() const;
};

#endif