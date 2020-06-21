#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "constants.h"

class Doors : public QObject
{
    // Макрос для работы со слотами и сигналами.
    Q_OBJECT

    enum class State
    {
        CLOSED,
        OPENING,
        OPENED,
        CLOSING,
    };

public:
    explicit Doors(QObject *parent = nullptr);
    void check_closed(); // Проверка на закрытие, можем ли двигаться?

public slots:
    void start_opening();  // начало открытия.
    void stop_opening(); // конец открытия, перевод в "открыты".
    void start_closing(); // начало закрытия.
    void stop_closing();// конец закрытия, перевод в "закрыты".

signals:
    void closed(); // Сигнал кабине о закрытых дверях.
    void start_opening_time();
    void opened(); // Ожидаем с открытыми дверями.
    void stop_closing_time();

private:
    State _state;
    // Таймер "сколько времени открываются" двери.
    QTimer _opening_time;
    // Таймер "сколько времени стоят открытыми" двери.
    QTimer _open_door_time;
    // Таймер "сколько времени закрываются" двери.
    QTimer _closing_time;

private:
    // Настройки для связи сигналов и слотов.
    void _settings_connect();
    void _settings_time();
};

#endif // DOOR_H
