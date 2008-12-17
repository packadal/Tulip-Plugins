/****************************************************************************
** Meta object code from reading C++ file 'QProperty.h'
**
** Created: Wed Dec 17 16:33:44 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QProperty.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QProperty.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QProperty[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      24,   19,   11,   10, 0x0a,
      67,   56,   51,   10, 0x0a,
     102,   10,   11,   10, 0x0a,
     130,   10,   11,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QProperty[] = {
    "QProperty\0\0QString\0node\0"
    "getNodeStringValue(QNode*)\0bool\0"
    "node,value\0setNodeStringValue(QNode*,QString)\0"
    "getNodeDefaultStringValue()\0"
    "getEdgeDefaultStringValue()\0"
};

const QMetaObject QProperty::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QProperty,
      qt_meta_data_QProperty, 0 }
};

const QMetaObject *QProperty::metaObject() const
{
    return &staticMetaObject;
}

void *QProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QProperty))
	return static_cast<void*>(const_cast< QProperty*>(this));
    return QObject::qt_metacast(_clname);
}

int QProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = getNodeStringValue((*reinterpret_cast< QNode*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { bool _r = setNodeStringValue((*reinterpret_cast< QNode*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { QString _r = getNodeDefaultStringValue();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = getEdgeDefaultStringValue();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
