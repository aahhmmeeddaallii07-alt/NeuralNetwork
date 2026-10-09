
#include <iostream>
#include <cmath>

#include "../src/ActivationFunctions.h"

int main()
{
    bool sigmoidPassed =
        std::abs(sigmoid(0.0) - 0.5) < 0.000001;

    bool reluPassed =
        std::abs(relu(-2.0)) < 0.000001 &&
        std::abs(relu(3.0) - 3.0) < 0.000001;

    bool tanhPassed =
        std::abs(tanhActivation(0.0)) < 0.000001;

    if (sigmoidPassed && reluPassed && tanhPassed)
    {
        std::cout << "Activation tests: PASS" << std::endl;
        return 0;
    }

    std::cout << "Activation tests: FAIL" << std::endl;
    return 1;
}