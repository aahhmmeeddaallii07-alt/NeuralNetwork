#include "CLI.h"

#include <iostream>
#include <string>
#include <vector>

#include "ActivationFunctions.h"
#include "DatasetGenerator.h"
#include "Metrics.h"
#include "ModelSerializer.h"
#include "NeuralNetwork.h"
#include "Trainer.h"

int CLI::run(
    int argc,
    char* argv[]
)
{
    if (argc < 2)
    {
        std::cout
            << "Commandes disponibles :"
            << std::endl;

        std::cout
            << "  train"
            << std::endl;

        std::cout
            << "  predict <x1> <x2>"
            << std::endl;

        std::cout
            << "  metrics"
            << std::endl;

        return 0;
    }

    std::string command = argv[1];

    if (command == "train")
    {
        NeuralNetwork network;

        network.addLayer(
            2,
            8,
            relu,
            reluDerivative
        );

        network.addLayer(
            8,
            1,
            sigmoid,
            sigmoidDerivative
        );

        Dataset dataset =
            DatasetGenerator::generateClassificationDataset(
                1000
            );

        Dataset trainDataset;
        Dataset testDataset;

        dataset.split(
            0.75,
            trainDataset,
            testDataset
        );

        std::cout
            << "Entrainement..."
            << std::endl;

        Trainer::train(
            network,
            trainDataset,
            5000,
            0.1
        );

        ModelSerializer::save(
            network,
            "model.txt"
        );

        std::cout
            << "Modele sauvegarde."
            << std::endl;
    }
    else if (command == "predict")
    {
        if (argc != 4)
        {
            std::cout
                << "Usage : predict <x1> <x2>"
                << std::endl;

            return 1;
        }

        double x1 = std::stod(argv[2]);
        double x2 = std::stod(argv[3]);

        NeuralNetwork network;

        network.addLayer(
            2,
            8,
            relu,
            reluDerivative
        );

        network.addLayer(
            8,
            1,
            sigmoid,
            sigmoidDerivative
        );

        ModelSerializer::load(
            network,
            "model.txt"
        );

        std::vector<double> prediction =
            network.forward({x1, x2});

        std::cout
            << "Prediction : "
            << prediction[0]
            << std::endl;

        int predictedClass =
            prediction[0] >= 0.5 ? 1 : 0;

        std::cout
            << "Classe : "
            << predictedClass
            << std::endl;
    }
    else if (command == "metrics")
    {
        NeuralNetwork network;

        network.addLayer(
            2,
            8,
            relu,
            reluDerivative
        );

        network.addLayer(
            8,
            1,
            sigmoid,
            sigmoidDerivative
        );

        ModelSerializer::load(
            network,
            "model.txt"
        );

        Dataset dataset =
            DatasetGenerator::generateClassificationDataset(
                1000
            );

        int trueNegative;
        int falsePositive;
        int falseNegative;
        int truePositive;

        Metrics::confusionMatrix(
            network,
            dataset,
            trueNegative,
            falsePositive,
            falseNegative,
            truePositive
        );

        double accuracy =
            Metrics::accuracy(
                network,
                dataset
            );

        double precision =
            Metrics::precision(
                truePositive,
                falsePositive
            );

        double recall =
            Metrics::recall(
                truePositive,
                falseNegative
            );

        double f1 =
            Metrics::f1Score(
                precision,
                recall
            );

        std::cout
            << "Accuracy : "
            << accuracy * 100.0
            << "%"
            << std::endl;

        std::cout
            << "Precision : "
            << precision
            << std::endl;

        std::cout
            << "Recall : "
            << recall
            << std::endl;

        std::cout
            << "F1-score : "
            << f1
            << std::endl;

        std::cout
            << std::endl
            << "Confusion Matrix :"
            << std::endl;

        std::cout
            << "TN : "
            << trueNegative
            << std::endl;

        std::cout
            << "FP : "
            << falsePositive
            << std::endl;

        std::cout
            << "FN : "
            << falseNegative
            << std::endl;

        std::cout
            << "TP : "
            << truePositive
            << std::endl;
    }
    else
    {
        std::cout
            << "Commande inconnue."
            << std::endl;

        return 1;
    }

    return 0;
}