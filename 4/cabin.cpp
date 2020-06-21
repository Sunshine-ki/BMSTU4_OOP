#include "cabin.h"

#include <QDebug>
#include <QString>

// connect(чей сигнал, какой сигнал, кто принимает, во что принимает)


Cabin::Cabin(QObject *parent) : QObject(parent),
      _state(CabinState::STAND), _direction(Direction::STAND),
      _floor(Constants::START_FLOOR),
      _destination(Constants::NO_DESTINATION_FLOOR)
{
    // Соединяем сигнал Stop() со слотом CabinStopped() - метод, чтобы остановиться.
    QObject::connect(this, SIGNAL(Stop()), this, SLOT(CabinStopped()));
    // Начинаем открывать двери, когда кабина остановилась.
    QObject::connect(this, SIGNAL(Stopped(short)), &_doors, SLOT(start_open()));

    _moveTimer.setSingleShot(true); // Таймер работает один раз и все, а не, например, каждые 2 секунды
    _moveTimer.setInterval(static_cast<size_t>(Times::FLOOR_MOVE)); // Устанавливаем время таймера

    // Как только истекает _moveTimer, проходит время, которые мы двигались до следующего этажа
    // и вызывается функция-слот move, которая прибавит этаж, проверит, доехали мы или нет, и будет
    // дальше принимать решение (вызвать ли сигнал остановки или снова запустить таймер движения)
    QObject::connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(CabinMoving()));
    // Как только двери посылают сигнал closed, можно начинать движение (функция-слот move)
    QObject::connect(&_doors, SIGNAL(closed()), this, SLOT(CabinMoving()));
}


void Cabin::CabinMoving() {

    // Если кабина двигалась
    if (_state == CabinState::MOVING) {
        // обновляем этаж
        _floor += static_cast<short>(_direction);
        // Если не достигнут этаж-цель
        if (_floor != _destination) {
            // Сгенерировать сигнал "проезжаем этаж"
            emit FloorPassing(_floor);
            // запускаем таймер таймер движения до след этажа
            _moveTimer.start();
        }
        else // генерим stop, если этаж достигнут
            emit Stop();
    }

    else if (_state == CabinState::ACTIVE) {
        _state = CabinState::MOVING;
        if (_floor == _destination)
            emit Stop();
        else { // если нужно двигаться (то есть если мы не стоим на этаже-цели
            // опреляем направление движения
            _direction = _destination > _floor ? Direction::UP : Direction::DOWN;
            // устанавливаем таймер движения до следующего этажа
            _moveTimer.start();
        }
    }
}


// Слот, который обрабатывает сигнал кабины stop
void Cabin::CabinStopped() {
    if (_state == CabinState::MOVING) {
        _state = CabinState::STAND;
        _direction = Direction::STAND;

        qDebug("Elevator stands on the floor %d", _floor);
        emit Stopped(_floor);
    }
}


// Слот, который принимает новый этаж-цель
void Cabin::SetDestination(short floor) {
    if (_state == CabinState::STAND)
        _state = CabinState::ACTIVE;

    _destination = floor;
    _direction = _destination > _floor ? Direction::UP : Direction::DOWN;

    _doors.getReadyToMove();
}
