// Пример 7. Одиночка(Singleton).
#include <iostream>
#include <memory>

using namespace std;

class Product
{
public:
	static shared_ptr<Product> instance()
	{
		static shared_ptr<Product> myInstance(new Product());

		return myInstance;
	}
	~Product() { cout << "Destructor;" << endl; }

	void f() { cout << "Method f;" << endl; }

	Product(const Product &) = delete;
	Product &operator=(const Product &) = delete;

private:
	Product() { cout << "Default constructor;" << endl; }
};

int main()
{
	shared_ptr<Product> ptr(Product::instance());

	shared_ptr<Product> ptr1(Product::instance());

	printf("%d\n", ptr1 == ptr);

	ptr->f();
}
