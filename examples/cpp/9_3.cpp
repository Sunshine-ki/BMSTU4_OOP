// Пример 3. Фабричный метод(Factory Method).Разделение обязанностей.
#include <iostream>
#include <memory>
#include <map>

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

#pragma endregion

unique_ptr<Creator> createConCreator()
{
	return unique_ptr<Creator>(new ConCreator<ConProd1>());
}


// +base
class Solution
{
public:
	typedef unique_ptr<Creator> (*CreateCreator)();

	bool registration(size_t id, CreateCreator createfun)
	{
		return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
	}
	bool check(size_t id) { return callbacks.erase(id) == 1; }

	unique_ptr<Creator> create(size_t id)
	{
		CallBackMap::const_iterator it = callbacks.find(id);

		if (it == callbacks.end())
		{
			//			throw IdError();
		}

		return unique_ptr<Creator>((it->second)());
	}

private:
	using CallBackMap = map<size_t, CreateCreator>;

	CallBackMap callbacks;
};

int main()
{
	Solution solution;

	solution.registration(1, createConCreator);

	shared_ptr<Creator> cr(solution.create(1));
	shared_ptr<Product> ptr = cr->createProduct();

	ptr->run();
}
