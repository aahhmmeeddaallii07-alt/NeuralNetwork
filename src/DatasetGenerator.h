#ifndef DATASET_GENERATOR_H
#define DATASET_GENERATOR_H

#include "Dataset.h"

class DatasetGenerator
{
public:
    static Dataset generateClassificationDataset(
        int sampleCount
    );
};

#endif