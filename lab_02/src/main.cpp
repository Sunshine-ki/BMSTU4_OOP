#include <iostream>

#include <fstream>

#include "vector.hpp"

using namespace std;

#define OK 0;
#define dednl "\n\n" // double endl;

// Закрыть все файлы -> корректно завершить программу.
int main(void)
{
	setbuf(stdout, NULL);

	// TESTS
	size_t size = 6;

	cout << "\nИнициализация вектора.";
	Vector<int> obj_1(size);
	Vector<int> obj_2(size, 8);
	Vector<int> obj_3(obj_2);

	int *v = new int[size];
	Vector<int> obj_4(size, v);
	delete[] v;

	Vector<int> obj_5 = {1, 2, 3, 99};
	Vector<int> obj_5_1;
	obj_5_1 = {3, 1, 4, 11};

	Vector<int> obj_6(size, 0);

	cout << "Вывод разными способами:\n\n";

	for (const auto &element : obj_5_1)
		cout << element << " ";

	cout << dednl;

	Vector<int> obj_begin = {123, 2, 3, 99};

	for (auto it = obj_begin.begin(); it != obj_begin.end(); it++)
		cout << *it << " ";

	cout << dednl;

	const Vector<int> obj_cbegin = {123, 2, 3, 99};

	for (auto it = obj_cbegin.cbegin(); it != obj_cbegin.cend(); it++)
		cout << *it << " ";

	cout << dednl;

	for (auto it = obj_cbegin.begin(); it != obj_cbegin.end(); it++)
		cout << *it << " ";

	cout << dednl;

	const Vector<int> obj_const = {1, 2, 3, 9};
	for (const auto &element : obj_const)
		cout << element << " ";

	cout << dednl;
	cout << endl;
	cout << obj_2;
	cout << endl;
	cout << obj_5;
	cout << endl;

	Vector<int> obj_u = {987, 654, 321};
	for (const auto &element : obj_u)
		cout << element << " ";
	for (auto &element : obj_u)
		element = 0;
	cout << dednl;
	for (const auto &element : obj_u)
		cout << element << " ";
	cout << endl;

	cout << "\nИнициализация вектора (float)\n";
	Vector<float> obj_f(size, 5.5);
	cout << endl
		 << obj_f << endl;

	cout << "\nИнициализация вектора (double)\n";
	Vector<double> obj_d(size, 105.501);
	cout << endl
		 << obj_d << endl;

	cout << "\nИнициализация вектора (char)\n";
	Vector<char> obj_c(size, 't');
	cout << endl
		 << obj_c << endl;

	cout << "\nИнициализация вектора (char*)\n";
	char name[6] = "Alice";
	Vector<char *> obj_s(size, name);
	cout << endl
		 << obj_s << endl;

	cout << "____________Операторы с двумя векторами:____________\n\n";

	cout << "operator+:\n";
	obj_2 = obj_5 + obj_5_1;
	cout << obj_2;
	cout << endl;

	cout << "operator-:\n";
	obj_2 = obj_5 - obj_5_1;
	cout << obj_2;
	cout << endl;

	cout << "operator*:\n";
	Vector<double> obj_mult_1 = {-1, 2, -3};
	Vector<double> obj_mult_2 = {0, -4, 1};
	Vector<double> obj_mult_res = obj_mult_1.mul_vector(obj_mult_2);
	cout << obj_mult_res;
	cout << endl;

	cout << "operator&:\n";
	obj_2 = obj_5 & obj_5_1;
	cout << obj_2;
	cout << endl;

	cout << "operator/:\n";
	obj_2 = obj_5 / obj_5_1;
	cout << obj_2;
	cout << endl;

	cout << "operator=:\n";
	obj_2 = obj_5;
	cout << obj_2;
	obj_2 = (obj_5 = {31, 9, 3, 21});
	cout << obj_2;
	cout << endl;

	cout << "operator+=:\n";
	obj_2 += obj_5;
	cout << obj_2;
	cout << endl;

	cout << "operator-=:\n";
	obj_2 -= obj_5;
	cout << obj_2;
	cout << endl;

	cout << "operator&=:\n";
	obj_2 &= obj_5;
	cout << obj_2;
	cout << endl;

	cout << "operator*=:\n";
	Vector<double> obj_mult1 = {-1, 2, -3};
	Vector<double> obj_mult2 = {0, -4, 1};
	obj_mult1 *= obj_mult2;
	cout << obj_mult2;
	cout << endl;

	cout << "operator/=:\n";
	obj_2 /= obj_5;
	cout << obj_2;
	cout << endl;

	cout << "Проверка методов избыточного интерфейса:\n\n";

	cout << "add_vector:\n";
	obj_2 = obj_5.add_vector(obj_5_1);
	cout << obj_2;
	cout << endl;

	cout << "sub_vector:\n";
	obj_2 = obj_5.sub_vector(obj_5_1);
	cout << obj_2;
	cout << endl;

	cout << "mul_vector:\n";
	obj_mult_res = obj_mult_1.mul_vector(obj_mult_2);
	cout << obj_mult_res;
	cout << endl;

	cout << "div_vector:\n";
	obj_2 = obj_5.div_vector(obj_5_1);
	cout << obj_2;
	cout << endl;

	cout << "Исключение при делении векторов, разного размера:\n\n";
	try
	{
		obj_2 /= obj_1;
		cout << obj_2;
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}

	Vector<int> obj_7(size, 8);
	Vector<int> obj_8(size, 0);
	cout << "Исключение при делении на ноль (operator/=):\n\n";
	try
	{
		obj_7 /= obj_8;
		cout << obj_7;
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "____________Операторы с вектором и числом:____________\n\n";
	Vector<int> obj_9(size, 8);
	int elem = 7;

	cout << "operator+=:\n";
	obj_9 += elem;
	cout << obj_9;
	cout << endl;

	cout << "operator-=:\n";
	obj_9 -= elem;
	cout << obj_9;
	cout << endl;

	cout << "operator*=:\n";
	obj_9 *= elem;
	cout << obj_9;
	cout << endl;

	cout << "operator/=:\n";
	obj_9 /= elem;
	cout << obj_9;
	cout << endl;

	cout << "Проверка методов избыточного интерфейса:\n\n";

	cout << "add_element:\n";
	obj_9 = obj_9.add_element(elem);
	cout << obj_9;
	cout << endl;

	cout << "sub_element:\n";
	obj_9 = obj_9.sub_element(elem);
	cout << obj_9;
	cout << endl;

	cout << "mul_element:\n";
	obj_9 = obj_9.mul_element(elem);
	cout << obj_9;
	cout << endl;

	cout << "div_element:\n";
	obj_9 = obj_9.div_element(elem);
	cout << obj_9;
	cout << endl;

	Vector<int> obj_10(size, 8);
	cout << "Исключение при делении на ноль (operator/=):\n\n";
	try
	{
		obj_10 /= 0;
		cout << obj_10;
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}

	Vector<int> obj_11(size, 8);
	cout << "Исключение при делении на ноль (div_element):\n\n";
	try
	{
		obj_11 = obj_11.div_element(0);
		cout << obj_11;
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "Проверка операторов сравнения:\n\n";

	Vector<int> obj_12 = {1, 2, 3};
	Vector<int> obj_13 = {1, 2, 3};
	Vector<int> obj_14 = {1, 2, 3, 4};
	Vector<int> obj_15 = {1, 2, 4};

	cout << "obj_12: " << obj_12 << endl;
	cout << "obj_13: " << obj_13 << endl;
	cout << "obj_14: " << obj_14 << endl;
	cout << "obj_15: " << obj_15 << endl;

	cout << "(obj_12 == obj_12) = " << (obj_12 == obj_12) << endl;
	cout << "(obj_12 == obj_13) = " << (obj_12 == obj_12) << endl;
	cout << "(obj_12 == obj_14) = " << (obj_12 == obj_14) << endl;
	cout << "(obj_12 == obj_15) = " << (obj_12 == obj_15) << endl;
	cout << endl;
	cout << "(obj_12 != obj_12) = " << (obj_12 != obj_12) << endl;
	cout << "(obj_12 != obj_13) = " << (obj_12 != obj_12) << endl;
	cout << "(obj_12 != obj_14) = " << (obj_12 != obj_14) << endl;
	cout << "(obj_12 != obj_15) = " << (obj_12 != obj_15) << endl;
	cout << endl;

	cout << "Проверка операторов сравнения при помощи избыточного интерфейса:\n\n";

	cout << "(obj_12 is_equal obj_12) = " << (obj_12.is_equal(obj_12)) << endl;
	cout << "(obj_12 is_equal obj_13) = " << (obj_12.is_equal(obj_12)) << endl;
	cout << "(obj_12 is_equal obj_14) = " << (obj_12.is_equal(obj_14)) << endl;
	cout << "(obj_12 is_equal obj_15) = " << (obj_12.is_equal(obj_15)) << endl;
	cout << endl;
	cout << "(obj_12 not_equal obj_12) = " << (obj_12.not_equal(obj_12)) << endl;
	cout << "(obj_12 not_equal obj_13) = " << (obj_12.not_equal(obj_12)) << endl;
	cout << "(obj_12 not_equal obj_14) = " << (obj_12.not_equal(obj_14)) << endl;
	cout << "(obj_12 not_equal obj_15) = " << (obj_12.not_equal(obj_15)) << endl;
	cout << endl;

	cout << "Проверка оператора operator-:\n\n";
	Vector<int> obj_16 = {321, -123};

	cout << "obj_16: " << obj_16 << endl;
	obj_16 = -obj_16;
	cout << "-obj_16: " << obj_16 << endl;

	cout << "Проверка метода negative:\n\n";
	cout << "obj_16: " << obj_16 << endl;
	obj_16 = obj_16.negative();
	cout << "obj_16.negative(): " << obj_16 << endl;

	cout << "Проверка метода get_elem с параметром:\n\n";
	cout << "obj_16.get_elem(1): " << obj_16.get_elem(1) << endl;
	cout << endl;

	cout << "Проверка метода get_elem с отрицательным параметром:\n\n";
	cout << "obj_16.get_elem(-1): " << obj_16.get_elem(-1) << endl;
	cout << endl;

	cout << "Исключение при попытке взять индекс, выходящий за пределы (Положительный индекс):\n\n";
	try
	{
		cout << "obj_16.get_elem(2):\n\n"
			 << obj_16.get_elem(2) << endl;
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "Исключение при попытке взять индекс, выходящий за пределы (Отрицательный индекс):\n\n";
	try
	{
		cout << "obj_16.get_elem(-3):\n\n"
			 << obj_16.get_elem(-3) << endl;
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}

	Vector<int> obj_17 = {321, -123};

	cout << "Проверка метода set_elem:\n\n";
	elem = 111;
	obj_17.set_elem(1, elem);
	cout << "obj_17.set_elem(1, 111): " << obj_17 << endl;
	cout << endl;

	cout << "Проверка метода set_elem с отрицательным параметром:\n\n";
	elem = 222;
	obj_17.set_elem(-1, elem);
	cout << "obj_16.set_elem(-1, 222): " << obj_16 << endl;
	cout << endl;

	cout << "Исключение при индексе, выходящим за пределы (Положительный индекс):\n\n";
	try
	{
		cout << "obj_16.set_elem(2, 444):\n\n";
		obj_16.set_elem(2, 444);
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}
	cout << endl;

	cout << "Исключение при индексе, выходящим за пределы (Отрицательный индекс):\n\n";
	try
	{
		cout << "obj_16.set_elem(-3, 444):\n\n";
		obj_16.set_elem(-3, 555);
	}
	catch (base_exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "Проверка оператора operator[] (Положительный индекс):\n";
	Vector<int> obj_18 = {321, -123, 8, 1, 2, 3};
	cout << "obj_18: " << obj_18 << endl;
	cout << "obj_18[1] = " << obj_18[1] << endl;
	cout << endl;

	cout << "Проверка метода at() (Положительный индекс):\n";
	cout << "obj_18.at(1) = " << obj_18.at(1) << endl;
	cout << endl;

	cout << "Проверка оператора operator() (Положительный индекс):\n";
	cout << "obj_18(3) = " << obj_18(3) << endl;
	cout << endl;

	cout << "Проверка оператора operator[] (Отрицательный индекс):\n";
	cout << "obj_18[-3] = " << obj_18[-3] << endl;
	cout << endl;

	cout << "Проверка метода at() (Отрицательный индекс):\n";
	cout << "obj_18.at(-3) = " << obj_18.at(-3) << endl;
	cout << endl;

	cout << "Проверка оператора operator() (Отрицательный индекс):\n";
	cout << "obj_18(-3) = " << obj_18(-3) << endl;
	cout << endl;

	cout << "Проверка математических методов:\n\n";

	Vector<int> obj_19 = {-1, 2, 3};
	cout << "Вектор: " << obj_19;
	cout << "length() = " << obj_19.length() << "\n";
	cout << "unit_vector() = " << obj_19.unit_vector() << "\n";
	cout << dednl;
	Vector<int> obj_20 = {-1};
	cout << "Вектор: " << obj_20;
	cout << "length() = " << obj_20.length() << "\n";
	cout << "unit_vector() = " << obj_20.unit_vector() << "\n";
	cout << dednl;

	// Скалярное произведение векторов.
	Vector<int> obj_21 = {1, 2, 3};
	Vector<int> obj_22 = {4, 5, 6};
	cout << "Вектор_1: " << obj_21;
	cout << "Вектор_2: " << obj_22;
	cout << "dot_product Вектор_1 на Вектор_2: " << obj_21.dot_product(obj_22);
	cout << dednl;

	// Угол между векторами.
	Vector<int> obj_23 = {1, 1, 0};
	Vector<int> obj_24 = {1, 0, 1};
	cout << "Вектор_1: " << obj_23;
	cout << "Вектор_2: " << obj_24;
	cout << "angle Вектор_1 и Вектор_2: " << obj_23.angle(obj_24);
	cout << dednl;

	// Ортогональность векторов.
	Vector<int> obj_25 = {1, 2};
	Vector<int> obj_26 = {2, -1};
	cout << "Вектор_1: " << obj_25;
	cout << "Вектор_2: " << obj_26;
	cout << "is_orthogonality Вектор_1 и Вектор_2: " << obj_25.is_orthogonality(obj_26);
	cout << dednl;
	obj_25 = {3, -1};
	obj_26 = {7, 5};
	cout << "Вектор_1: " << obj_25;
	cout << "Вектор_2: " << obj_26;
	cout << "is_orthogonality Вектор_1 и Вектор_2: " << obj_25.is_orthogonality(obj_26);
	cout << dednl;

	// Коллинеарность векторов.
	obj_25 = {1, 2};
	obj_26 = {4, 8};
	cout << "Вектор_1: " << obj_25;
	cout << "Вектор_2: " << obj_26;
	cout << "is_collinearity Вектор_1 и Вектор_2: " << obj_25.is_collinearity(obj_26);
	cout << dednl;
	obj_26 = {5, 9};
	cout << "Вектор_1: " << obj_25;
	cout << "Вектор_2: " << obj_26;
	cout << "is_collinearity Вектор_1 и Вектор_2: " << obj_25.is_collinearity(obj_26);
	cout << dednl;

	// Нормирование вектора.
	Vector<double> obj_27 = {1, 3, 0, -2};
	cout << "Вектор: " << obj_27;
	Vector<double> obj_28 = obj_27.get_single_vector();
	cout << "get_single_vector : " << obj_28;
	cout << dednl;

	return OK;
}