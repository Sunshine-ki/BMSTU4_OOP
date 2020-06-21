// Пример 8. Шаблон одиночка(Singleton).
#include <iostream>
#include <memory>

using namespace std;

template <typename Type>
class Singleton
{
public:
	static Type &instance()
	{
		static unique_ptr<Type> myInstance(new Type());

		return *myInstance;
	}

	Singleton() = delete;
	Singleton(const Singleton<Type> &) = delete;
	Singleton<Type> &operator=(const Singleton<Type> &) = delete;
};

class Product
{
public:
	Product() { cout << "Default constructor;" << endl; }
	~Product() { cout << "Destructor;" << endl; }

	void f() { cout << "Method f;" << endl; }
};

int main()
{
	Product &d = Singleton<Product>::instance();

	d.f();
}