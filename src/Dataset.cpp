#include "Dataset.h"

#include <stdexcept>

void Dataset::addSample(
    const std::vector<double>& input,
    const std::vector<double>& target
)
{
    if (input.empty())
    {
        throw std::invalid_argument(
            "L'input ne doit pas etre vide."
        );
    }

    if (target.empty())
    {
        throw std::invalid_argument(
            "La target ne doit pas etre vide."
        );
    }

    inputs.push_back(input);
    targets.push_back(target);
}

const std::vector<std::vector<double>>&
Dataset::getInputs() const
{
    return inputs;
}

const std::vector<std::vector<double>>&
Dataset::getTargets() const
{
    return targets;
}

size_t Dataset::size() const
{
    return inputs.size();
}
void Dataset::split(
    double trainRatio,
    Dataset& trainDataset,
    Dataset& testDataset
) const
{
    if (trainRatio <= 0.0 || trainRatio >= 1.0)
    {
        throw std::invalid_argument(
            "Le train ratio doit etre entre 0 et 1."
        );
    }

    size_t trainSize =
        static_cast<size_t>(
            size() * trainRatio
        );

    for (size_t i = 0; i < size(); i++)
    {
        if (i < trainSize)
        {
            trainDataset.addSample(
                inputs[i],
                targets[i]
            );
        }
        else
        {
            testDataset.addSample(
                inputs[i],
                targets[i]
            );
        }
    }
}