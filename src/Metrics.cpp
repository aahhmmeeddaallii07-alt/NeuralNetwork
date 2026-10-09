#include "Metrics.h"

#include <vector>

double Metrics::accuracy(
    NeuralNetwork& network,
    const Dataset& dataset
)
{
    const auto& inputs =
        dataset.getInputs();

    const auto& targets =
        dataset.getTargets();

    int correct = 0;

    for (size_t i = 0; i < dataset.size(); i++)
    {
        std::vector<double> prediction =
            network.forward(inputs[i]);

        int predictedClass =
            prediction[0] >= 0.5 ? 1 : 0;

        int actualClass =
            targets[i][0] >= 0.5 ? 1 : 0;

        if (predictedClass == actualClass)
        {
            correct++;
        }
    }

    return static_cast<double>(correct)
        / dataset.size();
}

void Metrics::confusionMatrix(
    NeuralNetwork& network,
    const Dataset& dataset,
    int& trueNegative,
    int& falsePositive,
    int& falseNegative,
    int& truePositive
)
{
    trueNegative = 0;
    falsePositive = 0;
    falseNegative = 0;
    truePositive = 0;

    const auto& inputs =
        dataset.getInputs();

    const auto& targets =
        dataset.getTargets();

    for (size_t i = 0; i < dataset.size(); i++)
    {
        std::vector<double> prediction =
            network.forward(inputs[i]);

        int predictedClass =
            prediction[0] >= 0.5 ? 1 : 0;

        int actualClass =
            targets[i][0] >= 0.5 ? 1 : 0;

        if (actualClass == 0 && predictedClass == 0)
        {
            trueNegative++;
        }
        else if (actualClass == 0 && predictedClass == 1)
        {
            falsePositive++;
        }
        else if (actualClass == 1 && predictedClass == 0)
        {
            falseNegative++;
        }
        else
        {
            truePositive++;
        }
    }
}

double Metrics::precision(
    int truePositive,
    int falsePositive
)
{
    if (truePositive + falsePositive == 0)
    {
        return 0.0;
    }

    return static_cast<double>(truePositive)
        / (truePositive + falsePositive);
}

double Metrics::recall(
    int truePositive,
    int falseNegative
)
{
    if (truePositive + falseNegative == 0)
    {
        return 0.0;
    }

    return static_cast<double>(truePositive)
        / (truePositive + falseNegative);
}

double Metrics::f1Score(
    double precision,
    double recall
)
{
    if (precision + recall == 0.0)
    {
        return 0.0;
    }

    return 2.0 *
        (precision * recall) /
        (precision + recall);
}