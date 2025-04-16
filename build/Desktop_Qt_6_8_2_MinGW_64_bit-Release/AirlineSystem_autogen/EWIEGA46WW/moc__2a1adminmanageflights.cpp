/****************************************************************************
** Meta object code from reading C++ file '_2a1adminmanageflights.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../_2a1adminmanageflights.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file '_2a1adminmanageflights.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
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
struct qt_meta_tag_ZN18adminManageFlightsE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN18adminManageFlightsE = QtMocHelpers::stringData(
    "adminManageFlights",
    "on_nextAddFlightBtn_clicked",
    "",
    "on_finishFlightBtn_clicked",
    "on_assignPilotBtn_clicked",
    "QTableWidget*",
    "pilotsTable",
    "attendantsTable",
    "resetForm",
    "on_searchOnFlightToUpdate_clicked",
    "on_updateFlightBtn_clicked",
    "on_searchOnFlightToUpdateCrew_clicked",
    "on_updateAssignedCrewBtn_clicked",
    "on_updateCrewBtn_clicked",
    "on_searchOnFlightToRemove_clicked",
    "on_removeFlightBtn_clicked",
    "viewFlightsIsPressed"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN18adminManageFlightsE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    2,   88,    2, 0x08,    3 /* Private */,
       8,    0,   93,    2, 0x08,    6 /* Private */,
       9,    0,   94,    2, 0x08,    7 /* Private */,
      10,    0,   95,    2, 0x08,    8 /* Private */,
      11,    0,   96,    2, 0x08,    9 /* Private */,
      12,    0,   97,    2, 0x08,   10 /* Private */,
      13,    0,   98,    2, 0x08,   11 /* Private */,
      14,    0,   99,    2, 0x08,   12 /* Private */,
      15,    0,  100,    2, 0x08,   13 /* Private */,
      16,    0,  101,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject adminManageFlights::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ZN18adminManageFlightsE.offsetsAndSizes,
    qt_meta_data_ZN18adminManageFlightsE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN18adminManageFlightsE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<adminManageFlights, std::true_type>,
        // method 'on_nextAddFlightBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_finishFlightBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_assignPilotBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidget *, std::false_type>,
        // method 'resetForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchOnFlightToUpdate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateFlightBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchOnFlightToUpdateCrew_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateAssignedCrewBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateCrewBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchOnFlightToRemove_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_removeFlightBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'viewFlightsIsPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void adminManageFlights::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<adminManageFlights *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_nextAddFlightBtn_clicked(); break;
        case 1: _t->on_finishFlightBtn_clicked(); break;
        case 2: _t->on_assignPilotBtn_clicked((*reinterpret_cast< std::add_pointer_t<QTableWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTableWidget*>>(_a[2]))); break;
        case 3: _t->resetForm(); break;
        case 4: _t->on_searchOnFlightToUpdate_clicked(); break;
        case 5: _t->on_updateFlightBtn_clicked(); break;
        case 6: _t->on_searchOnFlightToUpdateCrew_clicked(); break;
        case 7: _t->on_updateAssignedCrewBtn_clicked(); break;
        case 8: _t->on_updateCrewBtn_clicked(); break;
        case 9: _t->on_searchOnFlightToRemove_clicked(); break;
        case 10: _t->on_removeFlightBtn_clicked(); break;
        case 11: _t->viewFlightsIsPressed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *adminManageFlights::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminManageFlights::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN18adminManageFlightsE.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int adminManageFlights::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
