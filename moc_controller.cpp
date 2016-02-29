/****************************************************************************
** Meta object code from reading C++ file 'controller.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_controller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,
      37,   32,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     101,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     145,   11,   11,   11, 0x08,
     157,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     180,   11,   11,   11, 0x08,
     191,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     215,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     236,   11,   11,   11, 0x08,
     252,   11,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_controller[] = {
    "controller\0\0res\0result(QString)\0expr\0"
    "change_text(QString)\0add_comma()\0"
    "add_zero()\0add_one()\0add_two()\0"
    "add_three()\0add_four()\0add_five()\0"
    "add_six()\0add_seven()\0add_eight()\0"
    "add_nine()\0add_plus()\0add_minus()\0"
    "add_times()\0add_divide()\0equal()\0"
    "add_bracket_l()\0add_bracket_r()\0"
    "add_square()\0"
};

void controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        controller *_t = static_cast<controller *>(_o);
        switch (_id) {
        case 0: _t->result((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->change_text((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->add_comma(); break;
        case 3: _t->add_zero(); break;
        case 4: _t->add_one(); break;
        case 5: _t->add_two(); break;
        case 6: _t->add_three(); break;
        case 7: _t->add_four(); break;
        case 8: _t->add_five(); break;
        case 9: _t->add_six(); break;
        case 10: _t->add_seven(); break;
        case 11: _t->add_eight(); break;
        case 12: _t->add_nine(); break;
        case 13: _t->add_plus(); break;
        case 14: _t->add_minus(); break;
        case 15: _t->add_times(); break;
        case 16: _t->add_divide(); break;
        case 17: _t->equal(); break;
        case 18: _t->add_bracket_l(); break;
        case 19: _t->add_bracket_r(); break;
        case 20: _t->add_square(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData controller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_controller,
      qt_meta_data_controller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_controller))
        return static_cast<void*>(const_cast< controller*>(this));
    return QObject::qt_metacast(_clname);
}

int controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void controller::result(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controller::change_text(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
