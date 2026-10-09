#include "Matrix.h"
#include <stdexcept>
#include <iostream>

Matrix::Matrix(int rows, int cols)
{
   
    if (rows <= 0 || cols <= 0)
    {
        throw std::invalid_argument(
            "Le nombre de lignes et de colonnes doit etre positif."
        );
    }

    
    this->rows = rows;
    this->cols = cols;

    
    data = std::vector<std::vector<double>>(
        rows,
        std::vector<double>(cols, 0.0)
    );
}



void Matrix::set(int row, int col, double value)
{
    
    if (row < 0 || row >= rows)
    {
        throw std::out_of_range("Indice de ligne invalide.");
    }

    
    if (col < 0 || col >= cols)
    {
        throw std::out_of_range("Indice de colonne invalide.");
    }

   
    data[row][col] = value;
}



double Matrix::get(int row, int col) const
{
    if (row < 0 || row >= rows)
    {
        throw std::out_of_range("Indice de ligne invalide.");
    }

    if (col < 0 || col >= cols)
    {
        throw std::out_of_range("Indice de colonne invalide.");
    }

    return data[row][col];
}



int Matrix::getRows() const
{
    return rows;
}



int Matrix::getCols() const
{
    return cols;
}



void Matrix::print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << data[i][j];

            if (j < cols - 1)
            {
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }
}



Matrix Matrix::add(const Matrix& other) const
{

    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument(
            "Les matrices doivent avoir les memes dimensions."
        );
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] =
                data[i][j] + other.data[i][j];
        }
    }

    return result;
}



Matrix Matrix::subtract(const Matrix& other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument(
            "Les matrices doivent avoir les memes dimensions."
        );
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] =
                data[i][j] - other.data[i][j];
        }
    }

    return result;
}



Matrix Matrix::multiply(double scalar) const
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] =
                data[i][j] * scalar;
        }
    }

    return result;
}



Matrix Matrix::multiply(const Matrix& other) const
{

    if (cols != other.rows)
    {
        throw std::invalid_argument(
            "Dimensions incompatibles pour la multiplication."
        );
    }


    Matrix result(rows, other.cols);


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {

            double sum = 0.0;

  
            for (int k = 0; k < cols; k++)
            {
                sum += data[i][k] * other.data[k][j];
            }

    
            result.data[i][j] = sum;
        }
    }

    return result;
}