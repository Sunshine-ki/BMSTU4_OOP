#pragma once

#include <iostream>
#include <memory>

#include "base_vector.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"
#include "errors.hpp"

// Параметры шаблона используем как типы.
// Шаблонный класс.
template <typename type>
class Vector : public base_vector
{
public:
	friend Iterator<type>;
	friend ConstIterator<type>;

	// explicit - запрещаем неявный вызов конструктора. ok.
	explicit Vector(size_t count = 0);
	Vector(size_t count, const type &filler);

	Vector(size_t count, type *vector);
	Vector(std::initializer_list<type> list);
	explicit Vector(const Vector &vector); // Копирование.
	Vector(Vector &&vector) noexcept;	   // Перенос.

	~Vector() = default;

	Vector<type> &operator=(const Vector &vector);
	Vector<type> &operator=(Vector &&vector);
	Vector<type> &operator=(std::initializer_list<type> list);

	// Избыточный интерфейс. ok.
	// noexcept -> без исключений.
	Vector<type> operator+(const Vector &vector) const;
	Vector<type> &operator+=(const Vector &vector);
	Vector<type> operator+(const type &element) const noexcept;
	Vector<type> &operator+=(const type &element) noexcept;
	Vector<type> add_vector(const Vector &vector) const;
	Vector<type> add_element(const type &element) const noexcept;

	Vector<type> operator-(const Vector &vector) const;
	Vector<type> &operator-=(const Vector &vector);
	Vector<type> operator-(const type &element) const noexcept;
	Vector<type> &operator-=(const type &element) noexcept;
	Vector<type> sub_vector(const Vector &vector) const;
	Vector<type> sub_element(const type &element) const noexcept;

	// Побитовое и & -> поэлементное умножение. ok.
	Vector<type> operator&(const Vector &vector) const;
	Vector<type> &operator&=(const Vector &vector);
	//  operator* -> Векторное умножение. ok.
	Vector<type> operator*(const Vector &vector) const; // Векторное произведение. ok.
	Vector<type> &operator*=(const Vector &vector);
	Vector<type> operator*(const type &element) const noexcept;
	Vector<type> &operator*=(const type &element) noexcept;
	Vector<type> mul_vector(const Vector &vector) const;
	Vector<type> mul_element(const type &element) const noexcept;

	Vector<type> operator/(const Vector &vector) const;
	Vector<type> &operator/=(const Vector &vector);
	Vector<type> operator/(const type &element) const;
	Vector<type> &operator/=(const type &element);
	Vector<type> div_vector(const Vector &vector) const;
	Vector<type> div_element(const type &element) const;

	// Разбить так всё. (Операторы сначала, потом методы). ok.
	bool operator==(const Vector &vector) noexcept;
	bool operator!=(const Vector &vector) noexcept;
	bool is_equal(const Vector &vector) noexcept;
	bool not_equal(const Vector &vector) noexcept;

	Vector<type> operator-() const noexcept;
	Vector<type> negative() const noexcept;

	// Математические методы.
	bool unit_vector() const noexcept;			  // Вектор явл единичным или нет? ok.
	double length() const noexcept;				  // Длина вектора. ok.
	type dot_product(const Vector &vector) const; // Скалярное произведение. ok.
	double angle(Vector &vector) const;			  // Определить угол между векторами. ok.
	bool is_orthogonality(Vector &vector) const;  // Вид ортогональность ok.
	bool is_collinearity(Vector &vector) const;	  // Коллинеарность. ok.
	Vector<type> get_single_vector() const;		  // Нормирование. ok.

	// Тут группировать получше. ok.
	type &operator[](int index);
	const type &operator[](int index) const;
	type &operator()(int index);
	const type &operator()(int index) const;
	type &at(int index);
	const type &at(int index) const;
	type &get_elem(int index);
	void set_elem(int index, const type &element);

	// Чтобы смогли сделать цикл по коллекции.
	// сbegin() сend() Добавить. ok.
	Iterator<type> begin();
	Iterator<type> end();
	ConstIterator<type> begin() const;
	ConstIterator<type> end() const;
	ConstIterator<type> cbegin() const;
	ConstIterator<type> cend() const;

protected:
	std::shared_ptr<type[]> data;

private:
	void _check_size(size_t count) const;
	void _check_index(int index, int limit) const;
	std::shared_ptr<type[]> allocate_memory(size_t count);
};

#include "../implementation/vector_constructors.hpp"
#include "../implementation/vector_operators.hpp"
#include "../implementation/vector_operator_methods.hpp"
#include "../implementation/vector_methods.hpp"
#include "../implementation/vector_math.hpp"