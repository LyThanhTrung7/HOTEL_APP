/****************************************************************************
** Meta object code from reading C++ file 'menu1.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../menu1.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmenu1ENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSmenu1ENDCLASS = QtMocHelpers::stringData(
    "menu1",
    "currentTimeChanged",
    "",
    "setCurrentTime",
    "newCurrentTime",
    "current_timer_timeout",
    "currentTime"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmenu1ENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[6];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[15];
    char stringdata5[22];
    char stringdata6[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmenu1ENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmenu1ENDCLASS_t qt_meta_stringdata_CLASSmenu1ENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "menu1"
        QT_MOC_LITERAL(6, 18),  // "currentTimeChanged"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 14),  // "setCurrentTime"
        QT_MOC_LITERAL(41, 14),  // "newCurrentTime"
        QT_MOC_LITERAL(56, 21),  // "current_timer_timeout"
        QT_MOC_LITERAL(78, 11)   // "currentTime"
    },
    "menu1",
    "currentTimeChanged",
    "",
    "setCurrentTime",
    "newCurrentTime",
    "current_timer_timeout",
    "currentTime"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmenu1ENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   37, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   33,    2, 0x0a,    3 /* Public */,
       5,    0,   36,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00015903, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject menu1::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSmenu1ENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmenu1ENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmenu1ENDCLASS_t,
        // property 'currentTime'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<menu1, std::true_type>,
        // method 'currentTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCurrentTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'current_timer_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void menu1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<menu1 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentTimeChanged(); break;
        case 1: _t->setCurrentTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->current_timer_timeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (menu1::*)();
            if (_t _q_method = &menu1::currentTimeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<menu1 *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->currentTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<menu1 *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentTime(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *menu1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmenu1ENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int menu1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void menu1::currentTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
