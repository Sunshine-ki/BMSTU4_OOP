// Пример 25. Подписчик-издатель (Publish-Subscribe).
# include <iostream>
# include <memory>
# include <vector>

using namespace std;

// Подписчик.
class Subscriber;

using Reseiver = Subscriber;

// Издатель.
class Publisher
{
private:
	using Action = void(Reseiver::*)();
	using Pair = pair<shared_ptr<Reseiver>, Action>;

	// Вектор пар (указатель на подписчика, 
	// и какой метод этого подписчика вызываем)
	vector<Pair> callback;

public:
	// метод подписаться.
	void subscribe(shared_ptr<Reseiver> r, Action a);

	// Метод оповещает подписчиков, о том, что он вызван.
	void run();
};

class Subscriber
{
public:
	virtual ~Subscriber() = default;

	virtual void method() = 0;
};

class ConSubscriber : public Subscriber
{
public:
	virtual void method() override { cout << "method;" << endl; }
};

class ConSubscriber2 : public Subscriber
{
public:
	virtual void method() override { cout << "method 2;" << endl; }
};

#pragma region Methods Publisher
void Publisher::subscribe(shared_ptr<Reseiver> r, Action a)
{
	// Создается пара.
	Pair pr(r, a);
	// Добавляется в вектор.
	callback.push_back(pr);
}

void Publisher::run()
{
	// Вызываем методы.
	cout << "Run:" << endl;
	for (auto elem : callback)
		((*elem.first).*(elem.second))();
}

#pragma endregion

int main()
{
	shared_ptr<Subscriber> subscriber2(new ConSubscriber2());

	shared_ptr<Subscriber> subscriber(new ConSubscriber());
	shared_ptr<Publisher> publisher(new Publisher());
	

	// Подписывается подписчик.
	publisher->subscribe(subscriber, &Subscriber::method);
	publisher->subscribe(subscriber2, &Subscriber::method);

	publisher->run();
}