#pragma once

#include <memory>
#include <iostream>

template <typename type, size_t N>
class Matrix
{
private:
	type _data[N][N];
public:
	Matrix();
	Matrix(const std::initializer_list<type> &init_list);

	Matrix(const Matrix &) = delete;
    Matrix &operator=(const Matrix &) = delete;

	type &at(size_t row, size_t column);
};

template <typename type, size_t N>
class MathVector
{
private:
	type _data[N];
public:
    MathVector();
    MathVector(const std::initializer_list<type> &init_list);

    MathVector(const MathVector &) = delete;
    MathVector &operator=(const MathVector &) = delete;

	void multiplication(Matrix<type, N> &matrix);

	type &at(size_t index);

	void print();
};

#include "matrix.hpp"