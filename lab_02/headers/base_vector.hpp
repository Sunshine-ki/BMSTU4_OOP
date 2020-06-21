#pragma once

class base_vector
{
public:
	// Конструктор.
	base_vector(size_t count = 0) : size(count) {}

	virtual size_t get_size() const noexcept { return size; };
	virtual bool is_empty() const noexcept { return !size; } // True == empty.

	// Деструктор.
	// Реализацию написать ~base_vector() здесь, но потом вынести. ok.
	virtual ~base_vector() = 0;

protected:
	size_t size = 0;
};

#include "../implementation/base.hpp"