// Пример 24. Посредник (Mediator).
# include <iostream>
# include <memory>
# include <list>
# include <vector>

using namespace std;

class Message {};         // Request

class Mediator;

class Colleague
{
private:
	weak_ptr<Mediator> mediator;

public:
	virtual ~Colleague() = default;

	// Установка медиатора. 
	void setMediator(shared_ptr<Mediator> mdr) { mediator = mdr; }

	// Послать сообщение.
	virtual bool send(shared_ptr<Message> msg);
	// Принять.
	virtual void receive(shared_ptr<Message> msg) = 0;
};

// Левый посылаеат - принимает правый (и наоборот).
// Обмениваются сообщениями через посредника.
class ColleagueLeft : public Colleague
{
public:
	virtual void receive(shared_ptr<Message> msg) override { cout << "Right - > Left;" << endl; }
};

class ColleagueRight : public Colleague
{
public:
	virtual void receive(shared_ptr<Message> msg) override { cout << "Left - > Right;" << endl; }
};

class Mediator
{
protected:
	list<shared_ptr<Colleague>> colleagues;

public:
	virtual ~Mediator() = default;

	// Кому передается и сообщение.
	virtual bool send(const Colleague* coleague, shared_ptr<Message> msg) = 0;

	// Добавить те объекты, которы будут взаимодействовать.
	static bool add(shared_ptr<Mediator> mediator, shared_ptr<Colleague> colleague, ...);
};

class ConMediator : public Mediator
{
public:
	// Только посылает.
	virtual bool send(const Colleague* coleague, shared_ptr<Message> msg) override;
};

#pragma region Methods Colleague
bool Colleague::send(shared_ptr<Message> msg)
{
	shared_ptr<Mediator> mdr = mediator.lock();

	// Если есть медиатор, то посылаем сообщение.
	return mdr ? mdr->send(this, msg) : false;
}

#pragma endregion

#pragma region Methods Mediator
bool Mediator::add(shared_ptr<Mediator> mediator, shared_ptr<Colleague> colleague, ...)
{
	if (!mediator || !colleague) return false;
	
	for (shared_ptr<Colleague>* ptr = &colleague; *ptr; ++ptr)
	{
		mediator->colleagues.push_back(*ptr);
		(*ptr)->setMediator(mediator);
	}

	return true;
}

bool ConMediator::send(const Colleague* colleague, shared_ptr<Message> msg)
{
	bool flag = false;
	// Просматриваем все объекты, которые имеют указатель медиатор.
	for (auto& elem : colleagues)
	{
		// Если это левый объект, а элемент правый, тогда передаем этому объекту сообщение.
		if (dynamic_cast<const ColleagueLeft*>(colleague) && dynamic_cast<ColleagueRight*>(elem.get()))
		{
			elem->receive(msg);
			flag = true;
		}
		else if (dynamic_cast<const ColleagueRight*>(colleague) && dynamic_cast<ColleagueLeft*>(elem.get()))
		{
			elem->receive(msg);
			flag = true;
		}
	}

	return flag;
}

#pragma endregion

int main()
{
	shared_ptr<Mediator> mediator(new ConMediator());

	// shared_ptr<Colleague> col1(new ColleagueLeft());
	// shared_ptr<Colleague> col2(new ColleagueRight());
	// shared_ptr<Colleague> col3(new ColleagueLeft());
	// shared_ptr<Colleague> col4(new ColleagueLeft());

	// Mediator::add(mediator, col1, col2, col3, col4, shared_ptr<Colleague>());

	// shared_ptr<Message> msg(new Message());

	// col1->send(msg);
	// col2->send(msg);
}
