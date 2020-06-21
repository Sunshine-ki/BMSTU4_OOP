#pragma once

#include <iostream>
#include <memory>

#include "errors.hpp"

template <typename type>
class Vector;

template <typename type>
class ConstIterator : public std::iterator<std::forward_iterator_tag, type>
{
public:
	ConstIterator(const Vector<type> &vector, const size_t ind = 0) : data(vector.data),
																	  index(ind),
																	  size(vector.size) {}

	bool operator!=(ConstIterator const &it) const;
	bool operator==(ConstIterator const &it) const;

	const type &operator*() const;
	const type &value() const;

	bool is_valid() const;
	bool is_end() const;
	// Чтобы могли рассматривать объекты, как bool значение if (obj) {...}
	operator bool() const;

	const type *operator->() const;

	const ConstIterator<type> &operator++() const;
	ConstIterator<type> &next() const;
	ConstIterator<type> operator++(int) const; // Постфиксная.

private:
	std::weak_ptr<type[]> data;
	// Чтобы могли ее менять.
	mutable size_t index = 0;
	size_t size = 0;

	void _check_valid() const;
	void _check_index(const std::string str, const size_t index) const;
};

#include "../implementation/const_iterator_implementation.hpp"