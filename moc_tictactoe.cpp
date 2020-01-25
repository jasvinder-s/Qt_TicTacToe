/****************************************************************************
** Meta object code from reading C++ file 'tictactoe.h'
**
** Created: Tue 11. May 21:26:10 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tictactoe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tictactoe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TicTacToe[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   11,   10,   10, 0x0a,
      57,   11,   10,   10, 0x0a,
      74,   10,   10,   10, 0x0a,
      89,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TicTacToe[] = {
    "TicTacToe\0\0playerWhoWin\0gameWon(int)\0"
    "showWinMessage(int)\0updateScore(int)\0"
    "clearSymbols()\0startNewGame()\0"
};

const QMetaObject TicTacToe::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TicTacToe,
      qt_meta_data_TicTacToe, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TicTacToe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TicTacToe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TicTacToe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TicTacToe))
        return static_cast<void*>(const_cast< TicTacToe*>(this));
    return QWidget::qt_metacast(_clname);
}

int TicTacToe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gameWon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: showWinMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: updateScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: clearSymbols(); break;
        case 4: startNewGame(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TicTacToe::gameWon(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
