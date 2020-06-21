#include "doors.h"
#include "qdebug.h"

/*
QTimer timer;
timer.setInterval(integer); // Утановить время в миллисекундах.
timer.start(); // запуск таймера
когда время таймера истекает, он генерит сигнал timeout(), который можно перехватить, например:
QObject::connect(&timer, SIGNAL(timeout()), cat, SLOT(eat()));
*/

Doors::Doors()
{
    _state = DoorsState::CLOSED;
    _time_setting();
    _settings_connect();
}

void Doors::start_open()
{
    if (_state == DoorsState::CLOSED) {
        _state = DoorsState::OPENING;
        qDebug() << "Двери открываются";
        _openTimer.start();
    }
}


void Doors::_open()
{
    if (_state == DoorsState::OPENING) {
        _state = DoorsState::OPENED;
        qDebug() << "Двери открыты";
        // Генерируем сигнал для таймера, чтобы он
        // Начал отсчитывать время до закрытия дверей.
        emit opened();
    }
}

void Doors::getReadyToMove()
{
    if (_state == DoorsState::CLOSED)
        emit closed();
}


void Doors::start_close()
{
    if (_state == DoorsState::OPENED) {
        _state = DoorsState::CLOSING;
        qDebug("Doors are closing");
        _closeTimer.start();
    }
}

void Doors::_close()
{
    if (_state == DoorsState::CLOSING) {
        _state = DoorsState::CLOSED;
        qDebug("Doors are closed");
        emit closed(); // Это передается кабине (внешнему миру то есть)
    }
}

void Doors::_time_setting()
{
    // Утановить вызов сигнала единыжды (короткий - один раз).
//    _openTimer.setSingleShot(true);
//    _closeTimer.setSingleShot(true);
//    _openedTimer.setSingleShot(true);

    _openTimer.setInterval(Times::DOORS_MOVE);
    _closeTimer.setInterval(Times::DOORS_MOVE);
    _openedTimer.setInterval(Times::DOORS_WAIT);
}

void Doors::_settings_connect()
{
    // Если истекает таймер "открытия" вызвать слот, который переведет в состояние "открыты"
    // и запустит таймер "сколько времени стоят открытые"
    QObject::connect(&_openTimer, SIGNAL(timeout()), this, SLOT(_open()));
    // при получении сигнала "открыты" начинаем отсчет таймера "сколько времени стоят откырытыми"
    QObject::connect(this, SIGNAL(opened()), &_openedTimer, SLOT(start()));
    // при истечении таймера "сколько времени стоят открытыми" запускаем слот "закрыть",
    // который запустит таймер "закрытия"
    QObject::connect(&_openedTimer, SIGNAL(timeout()), this, SLOT(start_close()));
    // при истечении таймера "закрытия" вызывается слот, который переводит в состояние "закрыты"
    QObject::connect(&_closeTimer, SIGNAL(timeout()), this, SLOT(_close()));
}

