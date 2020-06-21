#ifndef CABIN_H
#define CABIN_H

#include <QObject>

#include "controller.h"
#include "constants.h"
#include "doors.h"
#include "state.h"

class Cabin : public QObject
{
    // Этот макрос нужен, чтобы мы могли работать
    // С сигналами и слотами.
    Q_OBJECT

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void FloorPassing(short floor);
    void Stop();
    void Stopped(short floor);

public slots:
    void CabinMoving();
    void CabinStopped();
    void SetDestination(short floor);

private:
    Doors _doors;
    CabinState _state;
    Direction _direction;

    short _floor;
    short _destination;

    QTimer _moveTimer;
};

#endif // CABIN_H
