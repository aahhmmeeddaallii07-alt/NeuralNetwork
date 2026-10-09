#include "LossFunctions.h"

#include <stdexcept>

double meanSquaredError(
    const std::vector<double>& predictions,
    const std::vector<double>& targets
)
{
    if (predictions.size() != targets.size())
    {
        throw std::invalid_argument(
            "Les predictions et les targets doivent avoir la meme taille."
        );
    }

    if (predictions.empty())
    {
        throw std::invalid_argument(
            "Les vecteurs ne doivent pas etre vides."
        );
    }

    double sum = 0.0;

    for (size_t i = 0; i < predictions.size(); i++)
    {
        double error = predictions[i] - targets[i];

        sum += error * error;
    }

    return sum / predictions.size();
}
std::vector<double> meanSquaredErrorDerivative(
    const std::vector<double>& predictions,
    const std::vector<double>& targets
)
{
    if (predictions.size() != targets.size())
    {
        throw std::invalid_argument(
            "Les predictions et les targets doivent avoir la meme taille."
        );
    }

    if (predictions.empty())
    {
        throw std::invalid_argument(
            "Les vecteurs ne doivent pas etre vides."
        );
    }

    std::vector<double> gradients;

    for (size_t i = 0; i < predictions.size(); i++)
    {
        double gradient =
            2.0 * (predictions[i] - targets[i]);

        gradients.push_back(gradient);
    }

    return gradients;
}