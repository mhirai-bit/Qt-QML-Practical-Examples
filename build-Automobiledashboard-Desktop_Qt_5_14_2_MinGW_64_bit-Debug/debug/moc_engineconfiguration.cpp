/****************************************************************************
** Meta object code from reading C++ file 'engineconfiguration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Automobiledashboard/engineconfiguration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engineconfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EngineConfiguration_t {
    QByteArrayData data[29];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EngineConfiguration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EngineConfiguration_t qt_meta_stringdata_EngineConfiguration = {
    {
QT_MOC_LITERAL(0, 0, 19), // "EngineConfiguration"
QT_MOC_LITERAL(1, 20, 16), // "engineRPMChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "speedChanged"
QT_MOC_LITERAL(4, 51, 19), // "maxEngineRPMChanged"
QT_MOC_LITERAL(5, 71, 14), // "curGearChanged"
QT_MOC_LITERAL(6, 86, 16), // "fuelLevelChanged"
QT_MOC_LITERAL(7, 103, 17), // "engineTempChanged"
QT_MOC_LITERAL(8, 121, 14), // "eventGenerated"
QT_MOC_LITERAL(9, 136, 5), // "event"
QT_MOC_LITERAL(10, 142, 18), // "distanceStrChanged"
QT_MOC_LITERAL(11, 161, 14), // "calculateSpeed"
QT_MOC_LITERAL(12, 176, 17), // "calculateDistance"
QT_MOC_LITERAL(13, 194, 13), // "generateEvent"
QT_MOC_LITERAL(14, 208, 10), // "accelerate"
QT_MOC_LITERAL(15, 219, 3), // "acc"
QT_MOC_LITERAL(16, 223, 10), // "applyBrake"
QT_MOC_LITERAL(17, 234, 6), // "brakes"
QT_MOC_LITERAL(18, 241, 16), // "updateEngineProp"
QT_MOC_LITERAL(19, 258, 5), // "param"
QT_MOC_LITERAL(20, 264, 5), // "value"
QT_MOC_LITERAL(21, 270, 12), // "maxEngineRPM"
QT_MOC_LITERAL(22, 283, 17), // "getEngineProperty"
QT_MOC_LITERAL(23, 301, 9), // "engineRPM"
QT_MOC_LITERAL(24, 311, 5), // "speed"
QT_MOC_LITERAL(25, 317, 7), // "curGear"
QT_MOC_LITERAL(26, 325, 9), // "fuelLevel"
QT_MOC_LITERAL(27, 335, 10), // "engineTemp"
QT_MOC_LITERAL(28, 346, 11) // "distanceStr"

    },
    "EngineConfiguration\0engineRPMChanged\0"
    "\0speedChanged\0maxEngineRPMChanged\0"
    "curGearChanged\0fuelLevelChanged\0"
    "engineTempChanged\0eventGenerated\0event\0"
    "distanceStrChanged\0calculateSpeed\0"
    "calculateDistance\0generateEvent\0"
    "accelerate\0acc\0applyBrake\0brakes\0"
    "updateEngineProp\0param\0value\0maxEngineRPM\0"
    "getEngineProperty\0engineRPM\0speed\0"
    "curGear\0fuelLevel\0engineTemp\0distanceStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EngineConfiguration[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       7,  122, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,
       7,    0,   99,    2, 0x06 /* Public */,
       8,    1,  100,    2, 0x06 /* Public */,
      10,    0,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  104,    2, 0x0a /* Public */,
      12,    0,  105,    2, 0x0a /* Public */,
      13,    0,  106,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      14,    1,  107,    2, 0x02 /* Public */,
      16,    1,  110,    2, 0x02 /* Public */,
      18,    2,  113,    2, 0x02 /* Public */,
      21,    0,  118,    2, 0x02 /* Public */,
      22,    1,  119,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,   19,   20,
    QMetaType::Double,
    QMetaType::Double, QMetaType::QString,   19,

 // properties: name, type, flags
      23, QMetaType::Int, 0x00495003,
      24, QMetaType::Int, 0x00495103,
      21, QMetaType::Double, 0x00495003,
      25, QMetaType::Int, 0x00495003,
      26, QMetaType::Int, 0x00495003,
      27, QMetaType::Int, 0x00495003,
      28, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       7,

       0        // eod
};

void EngineConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EngineConfiguration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->engineRPMChanged(); break;
        case 1: _t->speedChanged(); break;
        case 2: _t->maxEngineRPMChanged(); break;
        case 3: _t->curGearChanged(); break;
        case 4: _t->fuelLevelChanged(); break;
        case 5: _t->engineTempChanged(); break;
        case 6: _t->eventGenerated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->distanceStrChanged(); break;
        case 8: _t->calculateSpeed(); break;
        case 9: _t->calculateDistance(); break;
        case 10: _t->generateEvent(); break;
        case 11: _t->accelerate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->applyBrake((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->updateEngineProp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 14: { double _r = _t->maxEngineRPM();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 15: { double _r = _t->getEngineProperty((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EngineConfiguration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::engineRPMChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EngineConfiguration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::speedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EngineConfiguration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::maxEngineRPMChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EngineConfiguration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::curGearChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EngineConfiguration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::fuelLevelChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EngineConfiguration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::engineTempChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (EngineConfiguration::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::eventGenerated)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (EngineConfiguration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineConfiguration::distanceStrChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<EngineConfiguration *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->engineRPM(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->speed(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->maxEngineRPM(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->curGear(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->fuelLevel(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->engineTemp(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->distanceStr(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<EngineConfiguration *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_engineRPM(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setSpeed(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setmaxEngineRPM(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setcurGear(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setfuelLevel(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setengineTemp(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setdistanceStr(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject EngineConfiguration::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EngineConfiguration.data,
    qt_meta_data_EngineConfiguration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EngineConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EngineConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EngineConfiguration.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EngineConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void EngineConfiguration::engineRPMChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EngineConfiguration::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EngineConfiguration::maxEngineRPMChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EngineConfiguration::curGearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void EngineConfiguration::fuelLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EngineConfiguration::engineTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void EngineConfiguration::eventGenerated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void EngineConfiguration::distanceStrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
