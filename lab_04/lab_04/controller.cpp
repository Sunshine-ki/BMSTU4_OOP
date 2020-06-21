#include "controller.h"

#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{
    _state = ControllerState::FREE;
}

void Controller::_add_floor(const short floor)
{
    for (size_t i = 0; i < _queue.size(); i++)
        // Если уже имеется данный этаж в очереди, то не добавляем его.
        if (_queue[i] == floor)
            return;
    _queue.push_back(floor);
}


// Поступило нажатие кнопки, обрабатываем его, добавляя в очередь.
void Controller::set_target(short floor)
{
    _add_floor(floor);

    if (_state == ControllerState::BUSY)
        return;

    _state = ControllerState::BUSY;
    emit set_destination(floor);
}


// Слот, который вызывается, когда кабина остановилась на некотором этаже
// если очередь != пусто, то этот слот также генерирует сигнал о новой цели
// для кабины (связываем в лифте).
void Controller::stop_cabin()
{
    _queue.erase(_queue.begin());

    if (!_queue.size())
    {
        _state = ControllerState::FREE;
        return;
    }

    emit set_destination(_queue[0]);
}

// Слот, принимающий сигналы от кабины о том, что она проехала этаж.
void Controller::passedFloor(short floor)
{
    qDebug() << "Проезжаем этаж: " << floor;
}


