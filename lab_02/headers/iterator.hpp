#pragma once

#include <iostream>
#include <memory>

#include "errors.hpp"

template <typename type>
class Vector;

// Итератор следует наследовать от класса std::iterator.
// Сам по себе этот класс не реализует никаких методов, но объявляет
// необходимые типы, которые используются в стандартных алгоритмах.
template <typename type>
class Iterator : public std::iterator<std::forward_iterator_tag, type>
{
public:
	Iterator(const Vector<type> &vector, const size_t ind = 0) : data(vector.data),
																 index(ind),
																 size(vector.size) {}

	bool operator!=(Iterator const &it) const;
	bool operator==(Iterator const &it) const;
	Iterator<type> &operator=(const Iterator<type> &it);

	type &operator*();
	const type &operator*() const;
	type &value();
	const type &value() const;
	type *operator->();
	const type *operator->() const;
	// Чтобы могли рассматривать объекты, как bool значение if (obj) {...}
	operator bool() const;

	bool is_valid() const;
	bool is_end() const;

	Iterator<type> &operator++();
	Iterator<type> &next();
	Iterator<type> operator++(int);

private:
	std::weak_ptr<type[]> data;
	size_t index = 0;
	size_t size = 0;

	void _check_valid() const;
	void _check_index(std::string str, size_t index);
};

#include "../implementation/iterator_implementation.hpp"