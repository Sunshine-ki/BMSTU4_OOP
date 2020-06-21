#include "math.h"

#include "vector.hpp"

template <typename type>
double Vector<type>::length() const noexcept
{
	double len = 0;
	for (size_t i = 0; i < size; i++)
		len += data[i] * data[i];
	return sqrt(len);
}

template <typename type>
bool Vector<type>::unit_vector() const noexcept
{
	if (length() - 1 < 1e-3)
		return true;
	return false;
}

template <typename type>
type Vector<type>::dot_product(const Vector &vector) const
{
	_check_size(vector.size);

	type result = 0;
	for (size_t i = 0; i < size; i++)
		result += data[i] * vector[i];
	return result;
}

template <typename type>
double Vector<type>::angle(Vector &vector) const
{
	return acos(dot_product(vector) / length() / vector.length()) * 180 / M_PI;
}

template <typename type>
bool Vector<type>::is_orthogonality(Vector &vector) const
{

	return !dot_product(vector);
}

template <typename type>
bool Vector<type>::is_collinearity(Vector &vector) const
{
	if (angle(vector) < 1e-3)
		return true;
	return false;
}

// Для того, чтобы нормировать вектор нам 
// необходимо найти его модуль,
// И каждую координату разделить на него.
template <typename type>
Vector<type> Vector<type>::get_single_vector() const
{
	Vector<type> temp(*this);
	return temp / length();
}

// // Векторное произведение.
// template <typename type>
// Vector<type> Vector<type>::cross_product(Vector &vector)
// {
// 	if (size != 3)
// 		return Vector<type>();

//     type x = data[1] * vector[2] - data[2] * vector[1];
//     type y = data[2] * vector[0] - data[0] * vector[2];
//     type z = data[0] * vector[1] - data[1] * vector[0];

// 	Vector<type> new_vector = {x, y, z};

// 	return new_vector;
// }