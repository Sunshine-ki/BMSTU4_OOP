// Пример 26. Опекун (Memento).
# include <iostream>
# include <memory>
# include <list>

using namespace std;

class Memento;

// Опекун.
class Caretaker
{
public:
	// Вернуть
	unique_ptr<Memento> getMemento();
	// Добавть снимок.
	void setMemento(unique_ptr<Memento> memento);

private:
	// Список снимков.
	list<unique_ptr<Memento>> mementos;
};

class Originator
{
public:
	Originator(int s) : state(s) {}

	const int getState() const { return state; }
	void setState(int s) { state = s; }

	// Сделать снимок.
	std::unique_ptr<Memento> createMemento() { return make_unique<Memento>(*this); }
	// Восстановить  состояние
	void restoreMemento(std::unique_ptr<Memento> memento);

private:
	// Тот снимок, который пришел последний - уходит первым. (идея стека)
	int state; // Состояние
};

class Memento
{
	friend class Originator;

public:
	Memento(Originator o) : originator(o) {}

private:
	void setOriginator(Originator o) { originator = o; }
	Originator getOriginator() { return originator; }

private:
	// Хранит мгновенный снимок этого объекта.
	Originator originator;
};

#pragma region Methods Caretaker
void Caretaker::setMemento(unique_ptr<Memento> memento)
{
	mementos.push_back(move(memento));
}

unique_ptr<Memento> Caretaker::getMemento() {

	unique_ptr<Memento> last = move(mementos.back());

	mementos.pop_back();

	// Возвращаем снимок.
	return last;
}

#pragma endregion

#pragma region Method Originator
// ЗАменят на тот объект, который мы взяли у опекуна.
void Originator::restoreMemento(std::unique_ptr<Memento> memento)
{
	*this = memento->getOriginator();
}

#pragma endregion

int main()
{
	auto originator = make_unique<Originator>(1);
	auto caretaker = make_unique<Caretaker>();

	cout << "State = " << originator->getState() << endl;
	caretaker->setMemento(originator->createMemento());

	originator->setState(2);
	cout << "State = " << originator->getState() << endl;
	caretaker->setMemento(originator->createMemento());
	originator->setState(3);
	cout << "State = " << originator->getState() << endl;
	caretaker->setMemento(originator->createMemento());

	originator->restoreMemento(caretaker->getMemento());
	cout << "State = " << originator->getState() << endl;
	originator->restoreMemento(caretaker->getMemento());
	cout << "State = " << originator->getState() << std::endl;
	originator->restoreMemento(caretaker->getMemento());
	cout << "State = " << originator->getState() << std::endl;
}
