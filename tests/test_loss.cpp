
#include <iostream>
#include <vector>
#include <cmath>

#include "../src/LossFunctions.h"

int main()
{
    std::vector<double> predictions = {7.0};
    std::vector<double> targets = {10.0};

    double loss =
        meanSquaredError(predictions, targets);

    std::vector<double> gradients =
        meanSquaredErrorDerivative(predictions, targets);

    bool lossPassed =
        std::abs(loss - 9.0) < 0.000001;

    bool gradientPassed =
        std::abs(gradients[0] - (-6.0)) < 0.000001;

    if (lossPassed && gradientPassed)
    {
        std::cout << "Loss tests: PASS" << std::endl;
        return 0;
    }

    std::cout << "Loss tests: FAIL" << std::endl;
    return 1;
}