// Пример 20. Цепочка обязанностей (Chain of Responsibility).
# include <iostream>
# include <memory>

using namespace std;

// На основе него формируем список.
class AbstractHandler
{
protected:
	shared_ptr<AbstractHandler> next;

	virtual bool run() = 0;

public:
	using Default = shared_ptr<AbstractHandler>;

	virtual ~AbstractHandler() = default;

	virtual bool handle() = 0;

	// Добавляет в список обработчики.
	void add(shared_ptr<AbstractHandler> node);
	void add(shared_ptr<AbstractHandler> node1, shared_ptr<AbstractHandler> node2, ...);
};


class ConHandler : public AbstractHandler
{
private:
	bool condition{ false }; // Состояние.

protected:
	// Содержит метод обработки.
	virtual bool run() override { cout << "Method run;" << endl; return true; }

public:
	ConHandler() = default;
	ConHandler(bool c) : condition(c) { cout << "Constructor;" << endl; }
	virtual ~ConHandler() override { cout << "Destructor;" << endl; }

	virtual bool handle() override
	{
		// Проход по цепочке, пока не найдется обработчик с состоянием true (Дальше не пойдет по цепочке).
		if (!condition) return next ? next->handle() : false;

		return run();
	}

};

#pragma region Methods
void AbstractHandler::add(shared_ptr<AbstractHandler> node)
{
	if (next)
		next->add(node);
	else
		next = node;
}

void AbstractHandler::add(shared_ptr<AbstractHandler> node1, shared_ptr<AbstractHandler> node2, ...)
{
	add(node1);
	for (Default* ptr = &node2; *ptr; ++ptr)
		add(*ptr);
}

#pragma endregion

int main()
{
	shared_ptr<AbstractHandler> chain(new ConHandler());

	chain->add(
		shared_ptr<AbstractHandler>(new ConHandler(false)),
		shared_ptr<AbstractHandler>(new ConHandler(true)),
		shared_ptr<AbstractHandler>(new ConHandler(true)),
		AbstractHandler::Default()
	);

	cout << "Result = " << chain->handle() << ";" << endl;;
}
