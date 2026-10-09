#include "ActivationFunctions.h"
#include <cmath>

double sigmoid(double x)
{
    return 1.0 / (1.0 + std::exp(-x));
}

double sigmoidDerivative(double x)
{
    double s = sigmoid(x);

    return s * (1.0 - s);
}

double relu(double x)
{
    if (x > 0.0)
    {
        return x;
    }

    return 0.0;
}

double reluDerivative(double x)
{
    if (x > 0.0)
    {
        return 1.0;
    }

    return 0.0;
}

double tanhActivation(double x)
{
    return std::tanh(x);
}

double tanhDerivative(double x)
{
    double t = std::tanh(x);

    return 1.0 - t * t;
}