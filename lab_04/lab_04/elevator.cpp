#include "elevator.h"

Elevator::Elevator()
{
    QObject::connect(&_controller, SIGNAL(set_destination(short)), &_cabin, SLOT(cabin_take_target(short)));
    QObject::connect(&_cabin, SIGNAL(floor_passing(short)), &_controller, SLOT(passedFloor(short)));
    QObject::connect(&_cabin, SIGNAL(open_door()), &_controller, SLOT(stop_cabin()));
}

void Elevator::call(short floor)
{
    _controller.set_target(floor);
}
