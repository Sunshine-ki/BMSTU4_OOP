#include "const_iterator.hpp"

template <typename type>
bool ConstIterator<type>::is_valid() const
{
	// Проверяется, актуален ли указатель.
	return !data.expired();
}

template <typename type>
bool ConstIterator<type>::is_end() const
{
	return index == size;
}

template <typename type>
ConstIterator<type>::operator bool() const
{
	// Проверяется, актуален ли указатель.
	return data.expired();
}

template <typename type>
void ConstIterator<type>::_check_valid() const
{
	if (!is_valid())
		throw(error_memory(
			"Обращение к nullptr", __FILE__, __LINE__, __func__));
}

template <typename type>
void ConstIterator<type>::_check_index(const std::string str, const size_t index) const
{
	if (!is_valid())
		throw(error_index(str, __FILE__, __LINE__, __func__, index));
}

template <typename type>
const type &ConstIterator<type>::operator*() const
{
	_check_valid();
	_check_index("Выход итератора за границы. (const operator*)", index);
	// lock() - Создает новый shared_ptr, который разделяет владение управляемым объектом.
	std::shared_ptr<type[]> data_ptr = data.lock();
	return data_ptr[index];
}

template <typename type>
const type *ConstIterator<type>::operator->() const
{
	_check_valid();
	_check_index("Выход итератора за границы. (const operator->)", index);
	std::shared_ptr<type[]> data_ptr = data.lock();
	return data[index].get();
}

template <typename type>
const type &ConstIterator<type>::value() const
{
	return operator*();
}

template <typename type>
bool ConstIterator<type>::operator!=(ConstIterator const &it) const
{
	return index != it.index;
}

template <typename type>
bool ConstIterator<type>::operator==(ConstIterator const &it) const
{
	return index == it.index;
}

template <typename type>
const ConstIterator<type> &ConstIterator<type>::operator++() const
{
	if (index < size)
		index++;
	return *this;
}

template <typename type>
ConstIterator<type> &ConstIterator<type>::next() const
{
	return operator++();
}

template <typename type>
ConstIterator<type> ConstIterator<type>::operator++(int) const
{
	ConstIterator<type> it(*this);
	++(*this);
	return it;
}
