#include <iostream>
#include <memory>

#include "vector.hpp"


template <typename type>
Vector<type> Vector<type>::operator+(const Vector &vector) const
{
	_check_size(vector.size);

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i] + vector[i];

	return temp;
}

template <typename type>
Vector<type> Vector<type>::operator-(const Vector &vector) const
{
	_check_size(vector.size);

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i] - vector[i];

	return temp;
}

template <typename type>
Vector<type> Vector<type>::operator&(const Vector &vector) const
{
	_check_size(vector.size);

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i] * vector[i];

	return temp;
}

template <typename type>
Vector<type> &Vector<type>::operator&=(const Vector &vector)
{
	_check_size(vector.size);

	for (size_t i = 0; i < size; i++)
		data[i] *= vector[i];

	return *this;
}

template <typename type>
Vector<type> Vector<type>::operator*(const Vector &vector) const
{
	_check_size(vector.size);

	if (size != 3)
		return Vector<type>();

    type x = data[1] * vector[2] - data[2] * vector[1];
    type y = data[2] * vector[0] - data[0] * vector[2];
    type z = data[0] * vector[1] - data[1] * vector[0];

	Vector<type> new_vector = {x, y, z};

	return new_vector;
}

template <typename type>
Vector<type> &Vector<type>::operator*=(const Vector &vector)
{
	_check_size(vector.size);

	if (size != 3 or vector.get_size() != 3)
		return *this;
	
    double x = data[1] * vector[2] - data[2] * vector[1];
    double y = data[2] * vector[0] - data[0] * vector[2];
    double z = data[0] * vector[1] - data[1] * vector[0];

	data[0] = x;
	data[1] = y;
	data[2] = z;

	return *this;
}


template <typename type>
Vector<type> Vector<type>::operator/(const Vector &vector) const
{
	_check_size(vector.size);

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
	{
		if (vector[i] == 0)
			throw(error_division_by_zero(
				"При попытке поделить векторы!",
				__FILE__, __LINE__, __func__));
		temp[i] = data[i] / vector[i];
	}

	return temp;
}

template <typename type>
Vector<type> Vector<type>::operator+(const type &element) const noexcept
{
	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i] + element;

	return temp;
}

template <typename type>
Vector<type> Vector<type>::operator-(const type &element) const noexcept
{
	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i] - element;

	return temp;
}

template <typename type>
Vector<type> Vector<type>::operator*(const type &element) const noexcept
{
	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i] * element;

	return temp;
}

template <typename type>
Vector<type> Vector<type>::operator/(const type &element) const
{
	if (element == 0)
		throw(error_division_by_zero(
			"При попытке поделить вектор на ноль!",
			__FILE__, __LINE__, __func__));

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i] / element;

	return temp;
}

// Vector<type> operator-()
template <typename type>
Vector<type> Vector<type>::operator-() const noexcept
{
	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		temp[i] = -data[i];

	return temp;
}

template <typename type>
Vector<type> &Vector<type>::operator+=(const Vector &vector)
{
	_check_size(vector.size);

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		data[i] += vector[i];

	return *this;
}

template <typename type>
Vector<type> &Vector<type>::operator-=(const Vector &vector)
{
	_check_size(vector.size);

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		data[i] -= vector[i];

	return *this;
}


template <typename type>
Vector<type> &Vector<type>::operator/=(const Vector &vector)
{
	_check_size(vector.size);

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
	{
		if (vector[i] == 0)
			throw(error_division_by_zero(
				"При попытке поделить векторы!",
				__FILE__, __LINE__, __func__));
		data[i] /= vector[i];
	}

	return *this;
}

template <typename type>
Vector<type> &Vector<type>::operator+=(const type &element) noexcept
{

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		data[i] += element;

	return *this;
}

template <typename type>
Vector<type> &Vector<type>::operator-=(const type &element) noexcept
{

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		data[i] -= element;

	return *this;
}

template <typename type>
Vector<type> &Vector<type>::operator*=(const type &element) noexcept
{

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		data[i] *= element;

	return *this;
}

template <typename type>
Vector<type> &Vector<type>::operator/=(const type &element)
{
	if (element == 0)
		throw(error_division_by_zero(
			"При попытке поделить вектор на ноль!",
			__FILE__, __LINE__, __func__));

	Vector<type> temp(size);
	for (size_t i = 0; i < size; i++)
		data[i] /= element;

	return *this;
}

template <typename type>
bool Vector<type>::operator==(const Vector &vector) noexcept
{
	if (size != vector.size)
		return false;

	for (size_t i = 0; i < size; i++)
		if (data[i] != vector[i])
			return false;

	return true;
}

template <typename type>
bool Vector<type>::operator!=(const Vector &vector) noexcept
{
	return !operator==(vector);
}
template <typename type>
type &Vector<type>::operator[](int index)
{
	_check_index(index, size);
	if (index < 0)
		index += size;
	return data[index];
}

template <typename type>
const type &Vector<type>::operator[](int index) const
{
	_check_index(index, size);
	if (index < 0)
		index += size;
	return data[index];
}

template <typename type>
type &Vector<type>::operator()(int index)
{
	return operator[](index);
}

template <typename type>
const type &Vector<type>::operator()(int index) const
{
	return operator[](index);
}