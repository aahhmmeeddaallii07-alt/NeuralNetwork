#include "DatasetGenerator.h"

#include <random>

Dataset DatasetGenerator::generateClassificationDataset(
    int sampleCount
)
{
    Dataset dataset;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < sampleCount; i++)
    {
        double x1 = distribution(generator);
        double x2 = distribution(generator);

        double target;

        if (x1 + x2 < 1.0)
        {
            target = 0.0;
        }
        else
        {
            target = 1.0;
        }

        dataset.addSample(
            {x1, x2},
            {target}
        );
    }

    return dataset;
}