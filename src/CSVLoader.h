#ifndef CSV_LOADER_H
#define CSV_LOADER_H

#include <string>

#include "Dataset.h"

class CSVLoader
{
public:
    static Dataset load(
        const std::string& filename,
        int inputSize,
        int targetSize
    );
};

#endif