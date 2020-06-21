#include <iostream>
#include <memory>

#include "vector.hpp"

template <typename type>
type &Vector<type>::get_elem(int index)
{
	return operator[](index);
}

template <typename type>
void Vector<type>::set_elem(int index, const type &element)
{
	operator[](index) = element;
}

template <typename type>
Iterator<type> Vector<type>::begin()
{
	return Iterator<type>(*this, 0);
}

template <typename type>
Iterator<type> Vector<type>::end()
{
	return Iterator<type>(*this, size);
}

template <typename type>
ConstIterator<type> Vector<type>::begin() const
{
	return ConstIterator<type>(*this, 0);
}

template <typename type>
ConstIterator<type> Vector<type>::end() const
{
	return ConstIterator<type>(*this, size);
}

template <typename type>
ConstIterator<type> Vector<type>::cbegin() const
{
	return ConstIterator<type>(*this, 0);
}

template <typename type>
ConstIterator<type> Vector<type>::cend() const
{
	return ConstIterator<type>(*this, size);
}

template <typename type>
std::ostream &operator<<(std::ostream &stream, Vector<type> &vector)
{
	if (vector.is_empty())
		throw(error_empty(
			"При попытке считывания из вектора!",
			__FILE__, __LINE__, __func__));

	for (size_t i = 0; i < vector.get_size(); i++)
		stream << vector[i] << " ";
	stream << std::endl;

	return stream;
}

template <typename type>
std::istream &operator>>(std::istream &stream, Vector<type> &vector)
{
	if (vector.is_empty())
		throw(error_empty(
			"При попытке записи в вектор",
			__FILE__, __LINE__, __func__));

	for (size_t i = 0; i < vector.get_size(); i++)
		stream >> vector[i];

	return stream;
}