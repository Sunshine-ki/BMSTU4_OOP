// Пример 1. Фабричный метод(Factory Method).Новый объект.
#include <iostream>
#include <memory>

using namespace std;

class Product;

class Creator
{
public:
	virtual unique_ptr<Product> createProduct() = 0;
};

template <typename Tprod>
class ConCreator : public Creator
{
public:
	virtual unique_ptr<Product> createProduct() override
	{
		return unique_ptr<Product>(new Tprod());
	}
};

#pragma region Product
class Product
{
public:
	virtual ~Product() = 0;
	virtual void run() = 0;
};

Product::~Product() {}

class ConProd1 : public Product
{
public:
	virtual ~ConProd1() override { cout << "Destructor;" << endl; }
	virtual void run() override { cout << "Method run;" << endl; }
};

class ConProd2 : public Product
{
public:
	virtual ~ConProd2() override { cout << "Destructor;" << endl; }
	virtual void run() override { cout << "Method 2 run;" << endl; }
};

#pragma endregion

int main()
{
	shared_ptr<Creator> cr(new ConCreator<ConProd1>());
	shared_ptr<Product> ptr = cr->createProduct();

	ptr->run();
}
