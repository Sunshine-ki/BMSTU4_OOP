#include <iostream>
#include <memory>

#include "vector.hpp"
#include "check.hpp"

#include "allocate_memory.hpp"

template <typename type>
Vector<type>::Vector(size_t count) : base_vector(count)
{
	data = allocate_memory(count);
}

template <typename type>
Vector<type>::Vector(size_t count, const type &filler) : base_vector(count)
{
	data = allocate_memory(count);

	for (size_t i = 0; i < size; i++)
		data[i] = filler;
}

template <typename type>
Vector<type>::Vector(std::initializer_list<type> list)
{
	size = list.size();
	data = allocate_memory(size);

	size_t i = 0;
	for (const auto &elem : list)
	{
		data[i] = elem;
		i++;
	}
}

template <typename type>
Vector<type>::Vector(const Vector &vector) : base_vector(vector.size)
{
	data = allocate_memory(size);
	for (size_t i = 0; i < size; i++)
		data[i] = vector.data[i];
}

template <typename type>
Vector<type>::Vector(Vector &&vector)  noexcept : base_vector(vector.size) 
{
	data = vector.data;
}

template <typename type>
Vector<type>::Vector(size_t count, type *vector) : base_vector(count)
{
	check_ptr(vector);
	data = allocate_memory(count);
	for (size_t i = 0; i < size; i++)
		data[i] = vector[i];
}

template <typename type>
Vector<type> &Vector<type>::operator=(const Vector &vector)
{
	size = vector.size;
	data = allocate_memory(size);
	for (size_t i = 0; i < size; i++)
		data[i] = vector.data[i];
	return *this;
}

template <typename type>
Vector<type> &Vector<type>::operator=(Vector &&vector)
{
	size = vector.size;
	data = vector.data;
	return *this;
}

template <typename type>
Vector<type> &Vector<type>::operator=(std::initializer_list<type> list)
{
	size = list.size();
	data = allocate_memory(size);

	size_t i = 0;
	for (const auto &elem : list)
	{
		data[i] = elem;
		i++;
	}

	// Возвращаем *this, чтобы
	// Могли делать так:
	// obj2 = (obj = {1, 2, 999});
	return *this;
}
