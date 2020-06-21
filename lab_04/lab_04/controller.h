#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>
#include <algorithm>

#include "constants.h"

class Controller : public QObject
{
    Q_OBJECT

    enum class ControllerState
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QObject *parent = nullptr);
    void set_target(short floor);

public slots:
    void stop_cabin();
    void passedFloor(short floor);

signals:
    void set_destination(short floor);

private:
    // очередность, в которой нажимались кнопки (классическая очередь)
    std::vector<short> _queue;
    ControllerState _state;

private:
    void _add_floor(const short);
};

#endif // CONTROLLER_H
