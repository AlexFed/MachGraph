/****************************************************************************
** Meta object code from reading C++ file 'imageeditor.h'
**
** Created: Sun Sep 18 03:55:27 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ImageEditor/imageeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      20,   12,   12,   12, 0x08,
      28,   12,   12,   12, 0x08,
      35,   12,   12,   12, 0x08,
      44,   12,   12,   12, 0x08,
      54,   12,   12,   12, 0x08,
      67,   12,   12,   12, 0x08,
      81,   12,   12,   12, 0x08,
      89,   12,   12,   12, 0x08,
      99,   12,   12,   12, 0x08,
     112,   12,   12,   12, 0x08,
     120,   12,   12,   12, 0x08,
     133,   12,   12,   12, 0x08,
     145,   12,   12,   12, 0x08,
     154,   12,   12,   12, 0x08,
     165,   12,   12,   12, 0x08,
     173,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImageEditor[] = {
    "ImageEditor\0\0open()\0print()\0test()\0"
    "zoomIn()\0zoomOut()\0normalSize()\0"
    "fitToWindow()\0about()\0lineExt()\0"
    "channelExt()\0gauss()\0sharpening()\0"
    "grayWorld()\0median()\0sepGauss()\0waves()\0"
    "glass()\0"
};

const QMetaObject ImageEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImageEditor,
      qt_meta_data_ImageEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageEditor))
        return static_cast<void*>(const_cast< ImageEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImageEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open(); break;
        case 1: print(); break;
        case 2: test(); break;
        case 3: zoomIn(); break;
        case 4: zoomOut(); break;
        case 5: normalSize(); break;
        case 6: fitToWindow(); break;
        case 7: about(); break;
        case 8: lineExt(); break;
        case 9: channelExt(); break;
        case 10: gauss(); break;
        case 11: sharpening(); break;
        case 12: grayWorld(); break;
        case 13: median(); break;
        case 14: sepGauss(); break;
        case 15: waves(); break;
        case 16: glass(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
