#include "iterator.hpp"

template <typename type>
bool Iterator<type>::is_valid() const
{
	// Проверяется, актуален ли указатель.
	return !data.expired();
}

template <typename type>
bool Iterator<type>::is_end() const
{
	return index == size;
}

template <typename type>
Iterator<type>::operator bool() const
{
	// Проверяется, актуален ли указатель.
	return data.expired();
}

template <typename type>
void Iterator<type>::_check_valid() const
{
	if (!is_valid())
		// Висящий указатель. указатель пустой.
		throw(error_memory(
			"Обращение к nullptr", __FILE__, __LINE__, __func__));
}

template <typename type>
void Iterator<type>::_check_index(std::string str, size_t index)
{
	if (!is_valid())
		throw(error_index(str, __FILE__, __LINE__, __func__, index));
}

template <typename type>
type &Iterator<type>::operator*()
{
	_check_valid();
	_check_index("Выход итератора за границы. (operator*)", index);

	// Создает новый shared_ptr, который разделяет владение управляемым объектом.
	std::shared_ptr<type[]> data_ptr = data.lock();
	return data_ptr[index];
}

template <typename type>
const type &Iterator<type>::operator*() const
{
	_check_valid();
	_check_index("Выход итератора за границы. (const operator*)", index);

	// lock() - Создает новый shared_ptr, который разделяет владение управляемым объектом.
	std::shared_ptr<type[]> data_ptr = data.lock();
	return data_ptr[index];
}

template <typename type>
type *Iterator<type>::operator->()
{
	_check_valid();
	_check_index("Выход итератора за границы. (operator->)", index);
	// lock() - Создает новый shared_ptr, на основе weak_ptr.
	std::shared_ptr<type[]> data_ptr = data.lock();
	// get() - Возвращает сохраненный указатель.
	return data[index].get();
}

template <typename type>
const type *Iterator<type>::operator->() const
{
	_check_valid();
	_check_index("Выход итератора за границы. (const operator->)", index);
	std::shared_ptr<type[]> data_ptr = data.lock();
	return data[index].get();
}

template <typename type>
type &Iterator<type>::value()
{
	return operator*();
}

template <typename type>
const type &Iterator<type>::value() const
{
	return operator*();
}

template <typename type>
bool Iterator<type>::operator!=(Iterator const &it) const
{
	return index != it.index;
}

template <typename type>
bool Iterator<type>::operator==(Iterator const &it) const
{
	return index == it.index;
}

template <typename type>
Iterator<type> &Iterator<type>::operator=(Iterator const &it)
{
	data = it.data;
	index = it.index;
	size = it.size;
	return *this;
}

template <typename type>
Iterator<type> &Iterator<type>::operator++()
{
	if (index < size)
		index++;
	return *this;
}

template <typename type>
Iterator<type> &Iterator<type>::next()
{
	return operator++();
}

template <typename type>
Iterator<type> Iterator<type>::operator++(int)
{
	Iterator<type> it(*this);
	++(*this);
	return it;
}
