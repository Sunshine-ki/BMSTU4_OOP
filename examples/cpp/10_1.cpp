// Пример 1. Использование паттерна “Подписчик-издатель” (Qt). 
# include <iostream>
# include <string>
# include <QObject>

using namespace std;

class Employer : public QObject // Publisher
{
    Q_OBJECT

private:
    const int day_salary = 15;
    const int day_advance = 25;

public:
    Employer() = default;
    void notifyEmployeis(int day);

signals:
    void salaryPayment();
    void taskIssuance();
};

# pragma region Method Publisher
void Employer::notifyEmployeis(int day)
{
    if (day == day_salary || day == day_advance)
    {
        emit salaryPayment();
    }
    else
    {
        emit taskIssuance();
    }
}

# pragma endregion

enum class Mood
{
    happy,
    sad
};

class Employee : public QObject // Subscribe
{
    Q_OBJECT

private:
    string name;
    Mood mood;

public:
    Employee(string name) : name(name), mood(Mood::sad) {}

    string getName() { return name; }
	Mood getMood() { return mood; }

    void subscribeOnEmployer(const Employer* ptrEmployer);
    void unsubscribeFromEmployer(const Employer* ptrEmployer);

public slots:
    void onSalaryPayment() { mood = Mood::happy; }
    void onTaskIssuance() { mood = Mood::sad; }
};

# pragma region Methods Subscribe
void Employee::subscribeOnEmployer(const Employer* ptrEmployer)
{
    QObject::connect(ptrEmployer, SIGNAL(salaryPayment()), this, SLOT(onSalaryPayment()));
    QObject::connect(ptrEmployer, SIGNAL(taskIssuance()), this, SLOT(onTaskIssuance()));
}

void Employee::unsubscribeFromEmployer(const Employer* ptrEmployer)
{
    QObject::disconnect(ptrEmployer, SIGNAL(salaryPayment()), this, SLOT(onSalaryPayment()));
    QObject::disconnect(ptrEmployer, SIGNAL(taskIssuance()), this, SLOT(onTaskIssuance()));
}

# pragma endregion

ostream& operator<< (ostream &out, const Employee &employee)
{
    string mood = employee.getMood() == Mood::happy ?
                "Happy with a lot of money!!!!))))" :
                "Sad with a lot of work....((((";
    
    return out << "Name: " << employee.getName() << ", Mood: " << mood << endl;
}

int main()
{
    //Создадим работодателя, который выступает в роли объекта publisher
    Employer google;

    //Создадим несколько работников, которые выступают в роли объекта subscriber
    Employee vanya("Vanya");
    Employee artem("Artem");
    Employee maxim("Maxim");
    Employee dmitrii("Dmitrii");

    //Проверим текущее состояние работников
    cout << "Employees states after creation:" << endl;
    cout << vanya;
    cout << artem;
    cout << maxim;
    cout << dmitrii << endl;

    //Подпишем нескольких работников на объект работодателя
    vanya.subscribeOnEmployer(&google);
    artem.subscribeOnEmployer(&google);
    dmitrii.subscribeOnEmployer(&google);

    //Проверим состояние после подписки на объект работодателя
    cout << "Employees states after publishing:" << endl;
    cout << vanya;
    cout << artem;
    cout << maxim;
    cout << dmitrii << endl;

    //Вызовем метод получения оповещения для всех подписчиков, в котором вызовется сигнал salaryPayment
    int day_salary = 25;
    google.notifyEmployeis(day_salary);

    //Проверим состояние работников, после получения зарплаты
    cout << "Employees states after salary event:" << endl;
    cout << vanya;
    cout << artem;
    cout << maxim;
    cout << dmitrii << endl;

    //Вызовем метод получения оповещения для всех подписчиков, в котором вызовется сигнал taskIssuance
    int someDay = 10;
    google.notifyEmployeis(someDay);

    //Проверим состояние работников, после получения задания
    cout << "Employees states after task event:" << endl;
    cout << vanya;
    cout << artem;
    cout << maxim;
    cout << dmitrii << endl;

    return 0;
}