#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
std::vector<double> vectorAdd(
    const std::vector<double>& a,
    const std::vector<double>& b
);
std::vector<double> vectorSubtract(
    const std::vector<double>& a,
    const std::vector<double>& b
);
std::vector<double> scalarMultiply(
    const std::vector<double>& vector,
    double scalar
);
double dotProduct(
    const std::vector<double>& a,
    const std::vector<double>& b
);

#endif