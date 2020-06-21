#ifndef STATE_H
#define STATE_H

enum class CabinState
{
    MOVING,
    ACTIVE,
    STAND
};

enum DoorsState
{
    OPENED,
    OPENING,
    CLOSING,
    CLOSED,
};

#endif // STATE_H
