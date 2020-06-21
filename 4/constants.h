#ifndef CONSTANTS_H
#define CONSTANTS_H


enum Times {
    FLOOR_MOVE = 2500,
    DOORS_MOVE = 1500,
    DOORS_WAIT = 4000,
};

enum Constants {
    FLOORS_AMOUNT = 9,
    START_FLOOR = 1,
    NO_DESTINATION_FLOOR = -1,
};

enum Direction
{
    UP = 1,
    STAND = 0,
    DOWN = -1
};

#endif // CONSTANTS_H
