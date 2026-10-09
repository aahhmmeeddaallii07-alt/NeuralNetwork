#include "ModelSerializer.h"

#include <fstream>
#include <stdexcept>

void ModelSerializer::save(
    const NeuralNetwork& network,
    const std::string& filename
)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Impossible de creer le fichier du modele."
        );
    }

    const auto& layers =
        network.getLayers();

    file << layers.size() << std::endl;

    for (const Layer& layer : layers)
    {
        const auto& neurons =
            layer.getNeurons();

        file << neurons.size() << std::endl;

        for (const Neuron& neuron : neurons)
        {
            const auto& weights =
                neuron.getWeights();

            file << weights.size();

            for (double weight : weights)
            {
                file << " " << weight;
            }

            file << std::endl;

            file << neuron.getBias()
                 << std::endl;
        }
    }

    file.close();
}
void ModelSerializer::load(
    NeuralNetwork& network,
    const std::string& filename
)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Impossible d'ouvrir le fichier du modele."
        );
    }

    int layerCount;

    file >> layerCount;

    for (int i = 0; i < layerCount; i++)
    {
        int neuronCount;

        file >> neuronCount;

        for (int j = 0; j < neuronCount; j++)
        {
            int weightCount;

            file >> weightCount;

            for (int k = 0; k < weightCount; k++)
            {
                double weight;

                file >> weight;

                network.getLayers()[i]
                    .getNeurons()[j]
                    .setWeight(k, weight);
            }

            double bias;

            file >> bias;

            network.getLayers()[i]
                .getNeurons()[j]
                .setBias(bias);
        }
    }

    file.close();
}