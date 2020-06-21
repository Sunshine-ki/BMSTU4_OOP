/****************************************************************************
** Meta object code from reading C++ file 'cabin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "cabin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cabin_t {
    QByteArrayData data[10];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cabin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cabin_t qt_meta_stringdata_Cabin = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Cabin"
QT_MOC_LITERAL(1, 6, 8), // "getReady"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 12), // "passingFloor"
QT_MOC_LITERAL(4, 29, 5), // "floor"
QT_MOC_LITERAL(5, 35, 4), // "stop"
QT_MOC_LITERAL(6, 40, 7), // "stopped"
QT_MOC_LITERAL(7, 48, 4), // "move"
QT_MOC_LITERAL(8, 53, 5), // "stand"
QT_MOC_LITERAL(9, 59, 14) // "setDestination"

    },
    "Cabin\0getReady\0\0passingFloor\0floor\0"
    "stop\0stopped\0move\0stand\0setDestination"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cabin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    4,

       0        // eod
};

void Cabin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cabin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getReady(); break;
        case 1: _t->passingFloor((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 2: _t->stop(); break;
        case 3: _t->stopped((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 4: _t->move(); break;
        case 5: _t->stand(); break;
        case 6: _t->setDestination((*reinterpret_cast< short(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cabin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabin::getReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cabin::*)(short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabin::passingFloor)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cabin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabin::stop)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Cabin::*)(short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabin::stopped)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cabin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Cabin.data,
    qt_meta_data_Cabin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cabin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cabin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cabin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cabin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Cabin::getReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cabin::passingFloor(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Cabin::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Cabin::stopped(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
