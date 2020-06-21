// Пример 2. Фабричный метод(Factory Method).Без повторного создания.
#include <iostream>
#include <memory>

using namespace std;

class Product;

class Creator
{
public:
	shared_ptr<Product> getProduct();

protected:
	virtual shared_ptr<Product> createProduct() = 0;

private:
	shared_ptr<Product> product;
};

template <typename Tprod>
class ConCreator : public Creator
{
protected:
	virtual shared_ptr<Product> createProduct() override
	{
		return shared_ptr<Product>(new Tprod());
	}
};

#pragma region Method Creator
shared_ptr<Product> Creator::getProduct()
{
	if (!product)
	{
		product = createProduct();
	}

	return product;
}

#pragma endregion

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

#pragma endregion

int main()
{
	shared_ptr<Creator> cr(new ConCreator<ConProd1>());
	shared_ptr<Product> ptr1 = cr->getProduct();
	shared_ptr<Product> ptr2 = cr->getProduct();

	cout << ptr1.use_count() << endl;
	ptr1->run();
}