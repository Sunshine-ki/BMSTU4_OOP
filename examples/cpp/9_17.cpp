// Пример 17. Стратегия (Strategy).
# include <iostream>
# include <memory>
# include <vector>

using namespace std;

class Strategy
{
public:
	virtual ~Strategy() = 0;

	virtual void algorithm() = 0;
};

Strategy::~Strategy() = default;

class ConStrategy1 : public Strategy
{
public:
	virtual void algorithm() override { cout << "Algorithm 1;" << endl; }
};

class ConStrategy2 : public Strategy
{
public:
	virtual void algorithm() override { cout << "Algorithm 2;" << endl; }
};

class Context
{
public:

	void algorithmStrategy(shared_ptr<Strategy> strategy) { strategy->algorithm(); }
};

int main()
{
	Context obj;

	obj.algorithmStrategy(shared_ptr<Strategy>(new ConStrategy1()));

	obj.algorithmStrategy(shared_ptr<Strategy>(new ConStrategy2()));	
}