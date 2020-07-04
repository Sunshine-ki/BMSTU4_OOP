#include "matrix.h"

template <typename type, size_t N>
type &Matrix<type, N>::at(size_t row, size_t column)
{
    if (row >= N || column >= N)
        printf("Error size");
    // throw
    return _data[row][column];
}

template <typename type, size_t N>
Matrix<type, N>::Matrix(const std::initializer_list<type> &init_list)
{
    if (init_list.size() != N * N)
        printf("Error init_list");
    // throw
    auto it = init_list.begin();

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            _data[i][j] = *it++;
}

template <typename type, size_t N>
Matrix<type, N>::Matrix()
{
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            _data[i][j] = (i == j);
}

template <typename type, size_t N>
void MathVector<type, N>::multiplication(Matrix<type, N> &matrix)
{
    type result[N] = {0};
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            result[i] += matrix.at(j, i) * _data[j];

    for (size_t i = 0; i < N; i++)
        _data[i] = result[i];
}

template <typename type, size_t N>
type &MathVector<type, N>::at(size_t index)
{
    if (index >= N)
        std::cout << "Error at MathVec";
    // throw
    return _data[index];
}

template <typename type, size_t N>
MathVector<type, N>::MathVector(const std::initializer_list<type> &init_list)
{
    if (init_list.size() != N)
        std::cout << "Error MathVec initializer_list";
    // throw

    auto it = init_list.begin();
    for (size_t i = 0; i < N; i++)
        _data[i] = *it++;
}

template <typename type, size_t N>
MathVector<type, N>::MathVector()
{
    for (size_t i = 0; i < N; i++)
        _data[i] = 0;
}

template <typename type, size_t N>
void MathVector<type, N>::print()
{
    std::cout << "Vector:\n";
    for (size_t i = 0; i < N; i++)
        std::cout << _data[i] << " ";
}