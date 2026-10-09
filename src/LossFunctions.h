#ifndef LOSS_FUNCTIONS_H
#define LOSS_FUNCTIONS_H

#include <vector>

double meanSquaredError(
    const std::vector<double>& predictions,
    const std::vector<double>& targets
);

std::vector<double> meanSquaredErrorDerivative(
    const std::vector<double>& predictions,
    const std::vector<double>& targets
);

#endif