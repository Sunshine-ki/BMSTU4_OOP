#ifndef CABIN_H
#define CABIN_H

#include <QObject>

#include "controller.h"
#include "constants.h"
#include "doors.h"

class Cabin : public QObject
{
    // Макрос для работы со слотами и сигналами.
    Q_OBJECT

    enum class state
    {
        STAND,
        GET,
        MOVING
    };

public:
    explicit Cabin(QObject *parent = nullptr);

public slots:
    void cabin_take_target(short);
    void cabin_move();
    void cabin_stand();

signals:
    void stop(); // Останавливает кабину.
    void open_door();
    void floor_passing(short);

private:
    Doors _doors;

    state _state;
    direction _direction;

    short _current_floor;
    short _need_floor;

    // Время движения.
    QTimer _move_time;

private:
    void _settings_time();
    void _settings_connect();
};

#endif // CABIN_H
