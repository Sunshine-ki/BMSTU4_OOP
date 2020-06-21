#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>
#include <algorithm>

#include "constants.h"

template <typename T>
using vector = std::vector<T>;


enum class ControllerState
{
    FREE,
    BUSY
};

class Controller : public QObject
{
    Q_OBJECT

public slots:
    void onFloor(short floor);
    void passedFloor(short floor);

public:
    explicit Controller(QObject *parent = nullptr);
    void setTarget(short floor);

signals:
    void setDestination(short floor);

private:
    // очередность, в которой нажимались кнопки (классическая очередь)
    vector<short> _queue;
    // текущий этаж
    short _curFloor;
    // текущая цель
    short _curTarget;
    // элемент [elem - 1] вектора true, если этаж elem надо посетить
    vector<bool> _floors;
    ControllerState _state;
    Direction _direction;

    void _correctQueue();
    short _getClosestTarget();
    short _getUpwards();
    short _getDownwards();
};

#endif // CONTROLLER_H
