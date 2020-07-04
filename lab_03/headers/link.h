#pragma once

#include <iostream>

class Link
{
private:
	size_t _l1, _l2;

public:
	Link() = default;
	Link(size_t l1, size_t l2): _l1(l1), _l2(l2) {};
	
	void set(size_t, size_t);

	size_t getFirst() {return _l1;};
	size_t getLast() {return _l2;};
};