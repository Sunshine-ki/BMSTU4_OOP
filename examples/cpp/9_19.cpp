// Пример 19. Команда (Command).
# include <iostream>
# include <memory>

using namespace std;

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};

template <typename Reseiver>
class SimpleCommand : public Command
{
private:
	// Получаем указатель на объект и на метод.
	typedef void(Reseiver::*Action)();

	shared_ptr<Reseiver> reseiver;
	Action action;

public:
	SimpleCommand(shared_ptr<Reseiver> r, Action a) : reseiver(r), action(a) {}

	virtual void execute() override { ((*reseiver).*action)(); }
};

class Object
{
public:
	void run() { cout << "Run method;" << endl; }
};

int main()
{
	shared_ptr<Object> obj(new Object());
	shared_ptr<Command> command(new SimpleCommand<Object>(obj, &Object::run));

	command->execute();
}