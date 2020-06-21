#ifndef CONSTANTS_H
#define CONSTANTS_H


#define TIME_MOVE_DOORS 500
#define TIME_WAITING_DOORS 2000
#define TIME_MOVE_CABIN 1500

#define START_FLOOR 1
#define NO_DESTINATION -1
#define FLOORS_AMOUNT 9 // Кол-во этажей.

enum direction
{
    UP = 1,
    STAND = 0,
    DOWN = -1
};

#endif // CONSTANTS_H
