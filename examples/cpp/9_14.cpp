// Мост
# include <iostream>
# include <memory>

using namespace std;

class Implementor
{
public:
	virtual ~Implementor() = 0;

	virtual void operationImp() = 0;
};

Implementor::~Implementor() = default;

class Abstraction
{
protected:
	shared_ptr<Implementor> implementor;

public:
	Abstraction(shared_ptr<Implementor> imp) : implementor(imp) {}
	virtual ~Abstraction() = 0;

	virtual void operation() = 0;
};

Abstraction::~Abstraction() = default;

class ConImplementor : public Implementor
{
public:
	virtual void operationImp() override { cout << "Implementor;" << endl; }
};

class Entity : public Abstraction
{
public:
	using Abstraction::Abstraction;

	virtual void operation() override { cout << "Entity: "; implementor->operationImp(); }
};

int main()
{
	shared_ptr<Implementor> implementor(new ConImplementor());
	shared_ptr<Abstraction> abstraction(new Entity(implementor));

	abstraction->operation();
}
