#ifndef MODEL_SERIALIZER_H
#define MODEL_SERIALIZER_H

#include <string>

#include "NeuralNetwork.h"

class ModelSerializer
{
public:
    static void save(
        const NeuralNetwork& network,
        const std::string& filename
    );
    static void load(
    NeuralNetwork& network,
    const std::string& filename
);
};

#endif