/****************************************************************************
** Meta object code from reading C++ file 'multiwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "multiwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Multiwin_t {
    QByteArrayData data[8];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Multiwin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Multiwin_t qt_meta_stringdata_Multiwin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Multiwin"
QT_MOC_LITERAL(1, 9, 24), // "outputFeedsButtonClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "setCurrentUser"
QT_MOC_LITERAL(4, 50, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 67, 8), // "newTweet"
QT_MOC_LITERAL(6, 76, 12), // "addFollowing"
QT_MOC_LITERAL(7, 89, 9) // "searchTag"

    },
    "Multiwin\0outputFeedsButtonClicked\0\0"
    "setCurrentUser\0QListWidgetItem*\0"
    "newTweet\0addFollowing\0searchTag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Multiwin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Multiwin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Multiwin *_t = static_cast<Multiwin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->outputFeedsButtonClicked(); break;
        case 1: _t->setCurrentUser((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->newTweet(); break;
        case 3: _t->addFollowing(); break;
        case 4: _t->searchTag(); break;
        default: ;
        }
    }
}

const QMetaObject Multiwin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Multiwin.data,
      qt_meta_data_Multiwin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Multiwin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Multiwin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Multiwin.stringdata0))
        return static_cast<void*>(const_cast< Multiwin*>(this));
    return QWidget::qt_metacast(_clname);
}

int Multiwin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
