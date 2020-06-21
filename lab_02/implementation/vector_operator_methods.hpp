#include <iostream>

#include "vector.hpp"

template <typename type>
Vector<type> Vector<type>::add_vector(const Vector &vector) const
{
	return operator+(vector);
}

template <typename type>
Vector<type> Vector<type>::sub_vector(const Vector &vector) const
{
	return operator-(vector);
}

template <typename type>
Vector<type> Vector<type>::mul_vector(const Vector &vector) const
{
	return operator*(vector);
}

template <typename type>
Vector<type> Vector<type>::div_vector(const Vector &vector) const
{
	return operator-(vector);
}

template <typename type>
Vector<type> Vector<type>::add_element(const type &element) const noexcept
{
	return operator+(element);
}

template <typename type>
Vector<type> Vector<type>::sub_element(const type &element) const noexcept
{
	return operator-(element);
}

template <typename type>
Vector<type> Vector<type>::mul_element(const type &element) const noexcept
{
	return operator*(element);
}

template <typename type>
Vector<type> Vector<type>::div_element(const type &element) const
{
	return operator/(element);
}

template <typename type>
Vector<type> Vector<type>::negative() const noexcept
{
	return operator-();
}

template <typename type>
bool Vector<type>::is_equal(const Vector &vector) noexcept
{
	return operator==(vector);
}

template <typename type>
bool Vector<type>::not_equal(const Vector &vector) noexcept
{
	return operator!=(vector);
}

template <typename type>
type &Vector<type>::at(int index)
{
	return operator[](index);
}

template <typename type>
const type &Vector<type>::at(int index) const
{
	return operator[](index);
}