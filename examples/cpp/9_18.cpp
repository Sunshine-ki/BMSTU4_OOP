// Пример 18. Стратегия (Strategy). “Статический полиморфизм”.
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

template <typename CStrategy>
class Context
{
private:
	unique_ptr<CStrategy> strategy;

public:
	Context() : strategy(new CStrategy()) {}

	void algorithmStrategy() { strategy->algorithm(); }
};

int main()
{
	Context<ConStrategy2> obj;

	obj.algorithmStrategy();
}