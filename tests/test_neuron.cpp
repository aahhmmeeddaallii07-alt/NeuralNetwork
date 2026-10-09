
#include <iostream>
#include <vector>
#include <cmath>

#include "../src/Neuron.h"

int main()
{
    Neuron neuron(2);

    neuron.setWeight(0, 2.0);
    neuron.setWeight(1, 3.0);
    neuron.setBias(1.0);

    std::vector<double> inputs = {4.0, 5.0};

    double output = neuron.forward(inputs);

    double expected = 24.0;

    if (std::abs(output - expected) < 0.000001)
    {
        std::cout << "Neuron test: PASS" << std::endl;
        return 0;
    }

    std::cout << "Neuron test: FAIL" << std::endl;
    return 1;
}