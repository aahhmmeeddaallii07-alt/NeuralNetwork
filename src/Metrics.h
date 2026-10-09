#ifndef METRICS_H
#define METRICS_H

#include "Dataset.h"
#include "NeuralNetwork.h"

class Metrics
{
public:
    static double accuracy(
        NeuralNetwork& network,
        const Dataset& dataset
    );

    static void confusionMatrix(
        NeuralNetwork& network,
        const Dataset& dataset,
        int& trueNegative,
        int& falsePositive,
        int& falseNegative,
        int& truePositive
    );

    static double precision(
        int truePositive,
        int falsePositive
    );

    static double recall(
        int truePositive,
        int falseNegative
    );

    static double f1Score(
        double precision,
        double recall
    );
};

#endif