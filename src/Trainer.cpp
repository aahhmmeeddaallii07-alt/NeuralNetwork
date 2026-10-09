#include "Trainer.h"

#include <iostream>

#include "LossFunctions.h"

void Trainer::train(
    NeuralNetwork& network,
    const Dataset& dataset,
    int epochs,
    double learningRate
)
{
    const auto& inputs =
        dataset.getInputs();

    const auto& targets =
        dataset.getTargets();

    for (int epoch = 1; epoch <= epochs; epoch++)
    {
        double totalLoss = 0.0;

        for (size_t i = 0; i < dataset.size(); i++)
        {
            std::vector<double> predictions =
                network.forward(inputs[i]);

            double loss =
                meanSquaredError(
                    predictions,
                    targets[i]
                );

            totalLoss += loss;

            std::vector<double> gradients =
                meanSquaredErrorDerivative(
                    predictions,
                    targets[i]
                );

            network.backward(
                gradients,
                learningRate
            );
        }

        double averageLoss =
            totalLoss / dataset.size();

        if (
            epoch == 1 ||
            epoch % 1000 == 0 ||
            epoch == epochs
        )
        {
            std::cout
                << "Epoch "
                << epoch
                << " - Loss : "
                << averageLoss
                << std::endl;
        }
    }
}