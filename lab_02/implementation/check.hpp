#pragma once

template <typename type>
void check_ptr(type *ptr)
{
	if (!ptr)
		throw(error_pointer(
			"Обращение к nullptr!",
			__FILE__, __LINE__, __func__));
}

template <typename type>
void Vector<type>::_check_size(size_t count) const
{
	if (size != count)
		throw(error_size(
			"Некорректный размер!",
			__FILE__, __LINE__, __func__, count));
}

template <typename type>
void Vector<type>::_check_index(int index, int limit) const
{
	if ((index > 0 && index >= limit) || (index < 0 && -1 * index > limit))
		throw(error_index(
			"Индекс выходит за пределы!",
			__FILE__, __LINE__, __func__, index));
}