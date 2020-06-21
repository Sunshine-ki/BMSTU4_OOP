#include "cabin.h"

#include <QDebug>
#include <QString>

//    Механизм сигналов и слотов является расширением языка программирования С++,
//    который используется для установления связи между объектами. Если происходит какое-либо
//    определённое событие, то при этом может генерироваться сигнал. Данный сигнал попадает в связанный
//    с ним слот. В свою очередь, слот — это обычный метод в C++, который присоединяется к сигналу;
//    он вызывается тогда, когда генерируется связанный с ним сигнал.

void Cabin::_settings_connect()
{
    QObject::connect(this, SIGNAL(stop()), this, SLOT(cabin_stand()));
    QObject::connect(this, SIGNAL(open_door()), &_doors, SLOT(start_opening()));

    QObject::connect(&_move_time, SIGNAL(timeout()), this, SLOT(cabin_move()));
    QObject::connect(&_doors, SIGNAL(closed()), this, SLOT(cabin_move()));
}


void Cabin::_settings_time()
{
    _move_time.setSingleShot(true);
    // Устанавливаем время таймера
    _move_time.setInterval(TIME_MOVE_CABIN);
}

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _current_floor = START_FLOOR;
    _need_floor = NO_DESTINATION;
    _direction = direction::STAND;
    _state = state::STAND;

    _settings_time();
    _settings_connect();
}

// Слот, который принимает новый этаж-цель
void Cabin::cabin_take_target(short floor)
{
    if (_state == state::STAND)
    {
        _state = state::GET;
        _need_floor = floor;
        _direction = _need_floor > _current_floor ? direction::UP : direction::DOWN;
        _doors.check_closed();
    }
}

void Cabin::cabin_move()
{
    if (_state == state::GET)
    {   
        _state = state::MOVING;
        if (_current_floor == _need_floor)
            emit stop();
        else
            _move_time.start(); // устанавливаем таймер движения до следующего этажа
    }
    else if (_state == state::MOVING)
    {
        _current_floor += _direction;
        if (_current_floor != _need_floor)
        {
            // Сгенерировать сигнал "проезжаем этаж"
            emit floor_passing(_current_floor);
            // запускаем таймер таймер движения до следующего этажа.
            _move_time.start();
        }
        else
            emit stop();

    }
}

// Слот, который обрабатывает сигнал кабины stop
void Cabin::cabin_stand()
{
    if (_state == state::MOVING)
    {
        qDebug() << "Лифт остановился на этаже: " << _current_floor;
        _state = state::STAND;
        _direction = direction::STAND;
        // Передаем управления дверям.
        emit open_door();
    }
}




