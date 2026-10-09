#ifndef TRAINER_H
#define TRAINER_H

#include "NeuralNetwork.h"
#include "Dataset.h"

class Trainer
{
public:
    static void train(
        NeuralNetwork& network,
        const Dataset& dataset,
        int epochs,
        double learningRate
    );
};

#endif