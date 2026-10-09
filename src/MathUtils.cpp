#include "MathUtils.h"
#include <stdexcept>
std::vector<double> vectorAdd(
    const std::vector<double>& a,
    const std::vector<double>& b
)
{
    if (a.size() != b.size())
    {
        throw std::invalid_argument(
            "Les vecteurs doivent avoir la meme taille."
        );
    }
    std::vector<double> result(a.size());

    for (size_t i = 0; i < a.size(); i++)
    {
        result[i] = a[i] + b[i];
    }

    return result;
}
std::vector<double> vectorSubtract(
    const std::vector<double>& a,
    const std::vector<double>& b
)
{
    if (a.size() != b.size())
    {
        throw std::invalid_argument(
            "Les vecteurs doivent avoir la meme taille."
        );
    }
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); i++)
    {
        result[i] = a[i] - b[i];
    }

    return result;
}
std::vector<double> scalarMultiply(
    const std::vector<double>& vector,
    double scalar
)
{
    std::vector<double> result(vector.size());
    for (size_t i = 0; i < vector.size(); i++)
    {
        result[i] = vector[i] * scalar;
    }

    return result;
}
double dotProduct(
    const std::vector<double>& a,
    const std::vector<double>& b
)
{
    if (a.size() != b.size())
    {
        throw std::invalid_argument(
            "Les vecteurs doivent avoir la meme taille."
        );
    }
    double result = 0.0;
    for (size_t i = 0; i < a.size(); i++)
    {
        result += a[i] * b[i];
    }
    return result;
}