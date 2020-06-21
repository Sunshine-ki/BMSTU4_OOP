#include "doors.h"
#include "qdebug.h"

/*
QTimer timer;
timer.setInterval(integer); // установить время в миллисекундах
timer.start(); // запуск таймера
когда время таймера истекает, он генерит сигнал timeout(), который можно перехватить, например:
QObject::connect(&timer, SIGNAL(timeout()), cat, SLOT(eat()));
*/



void Doors::_settings_connect()
{
    QObject::connect(this, SIGNAL(start_opening_time()), &_opening_time, SLOT(start()));
    QObject::connect(this, SIGNAL(opened()), &_open_door_time, SLOT(start()));
    QObject::connect(this, SIGNAL(stop_closing_time()), &_closing_time, SLOT(start()));

    QObject::connect(&_opening_time, SIGNAL(timeout()), this, SLOT(stop_opening()));
    QObject::connect(&_open_door_time, SIGNAL(timeout()), this, SLOT(start_closing()));
    QObject::connect(&_closing_time, SIGNAL(timeout()), this, SLOT(stop_closing()));
}

void Doors::_settings_time()
{
    // Короткий сигнал - один раз.
    _opening_time.setSingleShot(true);
    _closing_time.setSingleShot(true);
    _open_door_time.setSingleShot(true);

    // Устанавливаем интервалы, чтобы в дальнейшем просто вызывать start().
    _opening_time.setInterval(TIME_MOVE_DOORS);
    _open_door_time.setInterval(TIME_WAITING_DOORS);
    _closing_time.setInterval(TIME_MOVE_DOORS);
}

Doors::Doors(QObject *parent) : QObject(parent)
{
    _state = State::CLOSED;

    _settings_connect();
    _settings_time();
}

void Doors::start_opening()
{
    if (_state == State::CLOSED)
    {
        qDebug() <<"Двери открываются!";
        _state = State::OPENING;
        emit start_opening_time();
//        _opening_time.start();
    }
}

void Doors::stop_opening()
{
    if (_state == State::OPENING)
    {
        qDebug() << "Двери открыты! Входите!";
        _state = State::OPENED;
        emit opened();
    }
}

void Doors::start_closing()
{
    if (_state == State::OPENED)
    {
        qDebug() << "Осторожно, двери закрываеются!";
        _state = State::CLOSING;
        emit stop_closing_time();
//        _closing_time.start();
    }
}

void Doors::stop_closing()
{
    if (_state == State::CLOSING)
    {
        _state = State::CLOSED;
        qDebug() << "Двери закрыты!";
        emit closed(); // Это передается кабине (то есть внешнему миру)
    }
}

void Doors::check_closed()
{
    if (_state == State::CLOSED)
        emit closed();
}
