#include <iostream>
#include <memory>
#include <iterator>
#include <initializer_list>

using namespace std;

template <typename Type>
class Iterator;

class BaseArray
{
public:
	BaseArray(size_t sz = 0) { count = shared_ptr<size_t>(new size_t(sz)); }
	virtual ~BaseArray() = default;

	size_t size() { return bool(count) ? *count : 0; }
	operator bool() { return size(); }

protected:
	shared_ptr<size_t> count;
};

template <typename Type>
class Array final : public BaseArray
{
public:
	Array(initializer_list<Type> lt);
	virtual ~Array() {}

	Iterator<Type> begin() const { return Iterator<Type>(arr, count); }
	Iterator<Type> end() const { return Iterator<Type>(arr, count, *count); }

private:
	shared_ptr<Type[]> arr{nullptr};
};

template <typename Type>
class Iterator : public std::iterator<std::input_iterator_tag, Type>
{
	friend class Array<Type>;

private:
	Iterator(const shared_ptr<Type[]> &a, const shared_ptr<size_t> &c, size_t ind = 0) : arr(a), count(c), index(ind) {}

public:
	Iterator(const Iterator &it) = default;

	bool operator!=(Iterator const &other) const;
	bool operator==(Iterator const &other) const;

	Type &operator*();
	const Type &operator*() const;
	Type *operator->();
	const Type *operator->() const;
	Iterator<Type> &operator++();
	Iterator<Type> operator++(int);

private:
	weak_ptr<Type[]> arr;
	weak_ptr<size_t> count;
	size_t index = 0;
};

#pragma region Method Array

template <typename Type>
Array<Type>::Array(initializer_list<Type> lt)
{
	if (!(*count = lt.size()))
		return;

	arr = shared_ptr<Type[]>(new Type[*count]);

	size_t i = 0;
	for (Type elem : lt)
		arr[i++] = elem;
}

#pragma endregion

#pragma region Methods Iterator

template <typename Type>
bool Iterator<Type>::operator!=(Iterator const &other) const
{
	return index != other.index;
}

template <typename Type>
Type &Iterator<Type>::operator*()
{
	shared_ptr<Type[]> a(arr);

	return a[index];
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator++()
{
	shared_ptr<size_t> n(count);
	if (index < *n)
		index++;

	return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
	Iterator<Type> it(*this);

	++(*this);

	return it;
}

#pragma endregion

template <typename Type>
ostream &operator<<(ostream &os, const Array<Type> &arr)
{
	for (auto elem : arr)
		cout << elem << " ";

	return os;
}

int main()
{
	Array<int> arr{1, 2, 3, 4, 5};

	cout << " Array: " << arr << endl;
}