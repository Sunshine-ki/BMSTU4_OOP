#ifndef __ERRORS_HPP__

#define __ERRORS_HPP__

#include <exception>
#include <string.h>

#include "colors.hpp"

// Записать в лог файл.
// В сообщение нужно:
// Время.
// Место (где?).
// Сама ошибка.
// И возможно данные, которые привели к этой ошибке. (Если они есть).
class base_exception : public std::exception
{
public:
	base_exception(std::string msg, std::string file_name,
				   int line, std::string name,
				   std::string title = "Ошибка!\n")
	{
		error_msg = RED + title + msg + YELLOW;
		error_msg += "\n\nВ файле: " + file_name;
		error_msg += "\nИмя: " + name;
		error_msg += "\nНа строке: " + std::to_string(line);
		error_msg += "\nВремя последнего обновления (Компиляции): ";
		error_msg += __TIME__;
		error_msg += "\nВремя возникновения ошибки: ";
		error_msg += ctime(&t_time);
		error_msg += WHITE;
	}
	// virtual std::string what() override { return this->error_msg + WHITE; } -> Будет ошибка. ok.
	// virtual std::string what() { return this->error_msg + WHITE; }
	virtual const char *what() const noexcept override
	{
		return error_msg.c_str();
	};

protected:
	time_t t_time = time(NULL);
	std::string error_msg;
};

class error_index : public base_exception
{
public:
	error_index(
		std::string msg, std::string file_name,
		int line, std::string name, int ind,
		std::string title = "Ошибка индексации:\n")
		: base_exception(msg, file_name, line, name, title), index(ind) { error_msg += "\nИндекс: " + std::to_string(index) + WHITE; }

private:
	int index;
};

class error_memory : public base_exception
{
public:
	error_memory(
		std::string msg, std::string file_name,
		int line, std::string name,
		std::string title = "Ошибка работы с памятью:\n")
		: base_exception(msg, file_name, line, name, title) {}
};

class error_empty : public base_exception
{
public:
	error_empty(
		std::string msg, std::string file_name,
		int line, std::string name,
		std::string title = "Ошибка при попытке использования пустого вектора!:\n")
		: base_exception(msg, file_name, line, name, title) {}
};

class error_size : public base_exception
{
public:
	error_size(
		std::string msg, std::string file_name,
		int line, std::string name, size_t count,
		std::string title = "Ошибка, связанная с размером вектора!:\n")
		: base_exception(msg, file_name, line, name, title), size(count) { error_msg += "\nРазмер: " + std::to_string(size) + WHITE; }

private:
	int size;
};

class error_pointer : public base_exception
{
public:
	error_pointer(
		std::string msg, std::string file_name,
		int line, std::string name,
		std::string title = "Ошибка, связанная с указателем!:\n")
		: base_exception(msg, file_name, line, name, title) {}
};

class error_division_by_zero : public base_exception
{
public:
	error_division_by_zero(
		std::string msg, std::string file_name,
		int line, std::string name,
		std::string title = "Ошибка при делении на ноль!\n")
		: base_exception(msg, file_name, line, name, title) {}
};

#endif