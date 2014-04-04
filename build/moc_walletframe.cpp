/****************************************************************************
** Meta object code from reading C++ file 'walletframe.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/walletframe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'walletframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WalletFrame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   31,   31,   31, 0x0a,
      32,   31,   31,   31, 0x0a,
      50,   31,   31,   31, 0x0a,
      72,   31,   31,   31, 0x0a,
      95,  122,   31,   31, 0x0a,
     127,   31,   31,   31, 0x2a,
     147,  122,   31,   31, 0x0a,
     175,   31,   31,   31, 0x2a,
     196,  122,   31,   31, 0x0a,
     226,   31,   31,   31, 0x2a,
     249,  269,   31,   31, 0x0a,
     276,   31,   31,   31, 0x0a,
     291,   31,   31,   31, 0x0a,
     310,   31,   31,   31, 0x0a,
     325,   31,   31,   31, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WalletFrame[] = {
    "WalletFrame\0gotoOverviewPage()\0\0"
    "gotoHistoryPage()\0gotoAddressBookPage()\0"
    "gotoReceiveCoinsPage()\0"
    "gotoSendCoinsPage(QString)\0addr\0"
    "gotoSendCoinsPage()\0gotoSignMessageTab(QString)\0"
    "gotoSignMessageTab()\0gotoVerifyMessageTab(QString)\0"
    "gotoVerifyMessageTab()\0encryptWallet(bool)\0"
    "status\0backupWallet()\0changePassphrase()\0"
    "unlockWallet()\0setEncryptionStatus()\0"
};

void WalletFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WalletFrame *_t = static_cast<WalletFrame *>(_o);
        switch (_id) {
        case 0: _t->gotoOverviewPage(); break;
        case 1: _t->gotoHistoryPage(); break;
        case 2: _t->gotoAddressBookPage(); break;
        case 3: _t->gotoReceiveCoinsPage(); break;
        case 4: _t->gotoSendCoinsPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->gotoSendCoinsPage(); break;
        case 6: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->gotoSignMessageTab(); break;
        case 8: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->gotoVerifyMessageTab(); break;
        case 10: _t->encryptWallet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->backupWallet(); break;
        case 12: _t->changePassphrase(); break;
        case 13: _t->unlockWallet(); break;
        case 14: _t->setEncryptionStatus(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WalletFrame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WalletFrame::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_WalletFrame,
      qt_meta_data_WalletFrame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WalletFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WalletFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WalletFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WalletFrame))
        return static_cast<void*>(const_cast< WalletFrame*>(this));
    return QFrame::qt_metacast(_clname);
}

int WalletFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
