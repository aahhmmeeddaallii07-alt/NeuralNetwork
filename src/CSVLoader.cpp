#include "CSVLoader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

Dataset CSVLoader::load(
    const std::string& filename,
    int inputSize,
    int targetSize
)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Impossible d'ouvrir le fichier CSV."
        );
    }

    Dataset dataset;
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::stringstream stream(line);
        std::string value;

        std::vector<double> input;
        std::vector<double> target;

        for (int i = 0; i < inputSize; i++)
        {
            if (!std::getline(stream, value, ','))
            {
                throw std::runtime_error(
                    "Nombre de colonnes invalide."
                );
            }

            input.push_back(
                std::stod(value)
            );
        }

        for (int i = 0; i < targetSize; i++)
        {
            if (!std::getline(stream, value, ','))
            {
                throw std::runtime_error(
                    "Nombre de colonnes invalide."
                );
            }

            target.push_back(
                std::stod(value)
            );
        }

        dataset.addSample(
            input,
            target
        );
    }

    file.close();

    return dataset;
}