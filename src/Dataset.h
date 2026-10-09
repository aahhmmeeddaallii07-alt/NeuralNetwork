#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <cstddef>

class Dataset
{
private:
    std::vector<std::vector<double>> inputs;
    std::vector<std::vector<double>> targets;

public:
    void addSample(
        const std::vector<double>& input,
        const std::vector<double>& target
    );

    const std::vector<std::vector<double>>& getInputs() const;

    const std::vector<std::vector<double>>& getTargets() const;

    size_t size() const;

    void split(
        double trainRatio,
        Dataset& trainDataset,
        Dataset& testDataset
    ) const;
};

#endif