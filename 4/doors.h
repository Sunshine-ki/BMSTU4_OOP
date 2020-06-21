#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "constants.h"
#include "state.h"

class Doors : public QObject
{
    Q_OBJECT

public:
    Doors();
    void getReadyToMove();

public slots:
    void start_open(); // начало открытия (start opening)
    void start_close(); // начало закрытия (start closing)

signals:
    void closed();
    void opened();

private slots:
    void _open(); // конец открытия, перевод в "открыты"
    void _close(); // конец закрытия, перевод в "закрыты"

private:
    DoorsState _state;
    // Таймер "сколько времени открываются"
    QTimer _openTimer;
    // Таймер "сколько времени закрываются"
    QTimer _closeTimer;
    // Таймер "сколько времени стоят открытыми"
    QTimer _openedTimer;
private:
    void _time_setting();
    void _settings_connect();
};

#endif
