/****************************************************************************
** Meta object code from reading C++ file 'Uiscene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Script/Uiscene.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Uiscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
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
struct qt_meta_stringdata_CLASSuisceneENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSuisceneENDCLASS = QtMocHelpers::stringData(
    "uiscene",
    "drawCardSignal",
    "",
    "handleCardClick",
    "swappingturns",
    "NpcCardHandler",
    "DisplayThechoices",
    "ChangingDeckValue",
    "NpcChoosingSuit",
    "ChangingFieldSuitValue",
    "CurrentRoundEnded",
    "StartnewGame",
    "GameEnded",
    "ChangeSettings",
    "QuitGame",
    "createNewScene",
    "eventFilter",
    "obj",
    "QEvent*",
    "event",
    "drawCardOnClick",
    "DeleteUsedCard",
    "DeleteNPCUsedCard",
    "CardDrawnPlayer",
    "CardDrawnNpc",
    "CardDrawnField",
    "ShowingButtons",
    "HiddingButtons",
    "setskip",
    "getskip",
    "SwitchingtoLastScene",
    "CallingtheNpcChange",
    "CarddropSound",
    "CarddrawSound",
    "ShowHelp"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSuisceneENDCLASS_t {
    uint offsetsAndSizes[70];
    char stringdata0[8];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[14];
    char stringdata5[15];
    char stringdata6[18];
    char stringdata7[18];
    char stringdata8[16];
    char stringdata9[23];
    char stringdata10[18];
    char stringdata11[13];
    char stringdata12[10];
    char stringdata13[15];
    char stringdata14[9];
    char stringdata15[15];
    char stringdata16[12];
    char stringdata17[4];
    char stringdata18[8];
    char stringdata19[6];
    char stringdata20[16];
    char stringdata21[15];
    char stringdata22[18];
    char stringdata23[16];
    char stringdata24[13];
    char stringdata25[15];
    char stringdata26[15];
    char stringdata27[15];
    char stringdata28[8];
    char stringdata29[8];
    char stringdata30[21];
    char stringdata31[20];
    char stringdata32[14];
    char stringdata33[14];
    char stringdata34[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSuisceneENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSuisceneENDCLASS_t qt_meta_stringdata_CLASSuisceneENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "uiscene"
        QT_MOC_LITERAL(8, 14),  // "drawCardSignal"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 15),  // "handleCardClick"
        QT_MOC_LITERAL(40, 13),  // "swappingturns"
        QT_MOC_LITERAL(54, 14),  // "NpcCardHandler"
        QT_MOC_LITERAL(69, 17),  // "DisplayThechoices"
        QT_MOC_LITERAL(87, 17),  // "ChangingDeckValue"
        QT_MOC_LITERAL(105, 15),  // "NpcChoosingSuit"
        QT_MOC_LITERAL(121, 22),  // "ChangingFieldSuitValue"
        QT_MOC_LITERAL(144, 17),  // "CurrentRoundEnded"
        QT_MOC_LITERAL(162, 12),  // "StartnewGame"
        QT_MOC_LITERAL(175, 9),  // "GameEnded"
        QT_MOC_LITERAL(185, 14),  // "ChangeSettings"
        QT_MOC_LITERAL(200, 8),  // "QuitGame"
        QT_MOC_LITERAL(209, 14),  // "createNewScene"
        QT_MOC_LITERAL(224, 11),  // "eventFilter"
        QT_MOC_LITERAL(236, 3),  // "obj"
        QT_MOC_LITERAL(240, 7),  // "QEvent*"
        QT_MOC_LITERAL(248, 5),  // "event"
        QT_MOC_LITERAL(254, 15),  // "drawCardOnClick"
        QT_MOC_LITERAL(270, 14),  // "DeleteUsedCard"
        QT_MOC_LITERAL(285, 17),  // "DeleteNPCUsedCard"
        QT_MOC_LITERAL(303, 15),  // "CardDrawnPlayer"
        QT_MOC_LITERAL(319, 12),  // "CardDrawnNpc"
        QT_MOC_LITERAL(332, 14),  // "CardDrawnField"
        QT_MOC_LITERAL(347, 14),  // "ShowingButtons"
        QT_MOC_LITERAL(362, 14),  // "HiddingButtons"
        QT_MOC_LITERAL(377, 7),  // "setskip"
        QT_MOC_LITERAL(385, 7),  // "getskip"
        QT_MOC_LITERAL(393, 20),  // "SwitchingtoLastScene"
        QT_MOC_LITERAL(414, 19),  // "CallingtheNpcChange"
        QT_MOC_LITERAL(434, 13),  // "CarddropSound"
        QT_MOC_LITERAL(448, 13),  // "CarddrawSound"
        QT_MOC_LITERAL(462, 8)   // "ShowHelp"
    },
    "uiscene",
    "drawCardSignal",
    "",
    "handleCardClick",
    "swappingturns",
    "NpcCardHandler",
    "DisplayThechoices",
    "ChangingDeckValue",
    "NpcChoosingSuit",
    "ChangingFieldSuitValue",
    "CurrentRoundEnded",
    "StartnewGame",
    "GameEnded",
    "ChangeSettings",
    "QuitGame",
    "createNewScene",
    "eventFilter",
    "obj",
    "QEvent*",
    "event",
    "drawCardOnClick",
    "DeleteUsedCard",
    "DeleteNPCUsedCard",
    "CardDrawnPlayer",
    "CardDrawnNpc",
    "CardDrawnField",
    "ShowingButtons",
    "HiddingButtons",
    "setskip",
    "getskip",
    "SwitchingtoLastScene",
    "CallingtheNpcChange",
    "CarddropSound",
    "CarddrawSound",
    "ShowHelp"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSuisceneENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  194,    2, 0x06,    1 /* Public */,
       3,    0,  195,    2, 0x06,    2 /* Public */,
       4,    0,  196,    2, 0x06,    3 /* Public */,
       5,    0,  197,    2, 0x06,    4 /* Public */,
       6,    0,  198,    2, 0x06,    5 /* Public */,
       7,    0,  199,    2, 0x06,    6 /* Public */,
       8,    0,  200,    2, 0x06,    7 /* Public */,
       9,    0,  201,    2, 0x06,    8 /* Public */,
      10,    0,  202,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  203,    2, 0x0a,   10 /* Public */,
      12,    0,  204,    2, 0x0a,   11 /* Public */,
      13,    0,  205,    2, 0x0a,   12 /* Public */,
      14,    0,  206,    2, 0x0a,   13 /* Public */,
      15,    0,  207,    2, 0x0a,   14 /* Public */,
      16,    2,  208,    2, 0x0a,   15 /* Public */,
      20,    0,  213,    2, 0x0a,   18 /* Public */,
      21,    0,  214,    2, 0x0a,   19 /* Public */,
      22,    0,  215,    2, 0x0a,   20 /* Public */,
      23,    0,  216,    2, 0x0a,   21 /* Public */,
      24,    0,  217,    2, 0x0a,   22 /* Public */,
      25,    0,  218,    2, 0x0a,   23 /* Public */,
      26,    0,  219,    2, 0x0a,   24 /* Public */,
      27,    0,  220,    2, 0x0a,   25 /* Public */,
      28,    0,  221,    2, 0x0a,   26 /* Public */,
      29,    0,  222,    2, 0x0a,   27 /* Public */,
      30,    0,  223,    2, 0x0a,   28 /* Public */,
      31,    0,  224,    2, 0x0a,   29 /* Public */,
      32,    0,  225,    2, 0x0a,   30 /* Public */,
      33,    0,  226,    2, 0x0a,   31 /* Public */,
      34,    0,  227,    2, 0x0a,   32 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 18,   17,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject uiscene::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSuisceneENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSuisceneENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSuisceneENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<uiscene, std::true_type>,
        // method 'drawCardSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCardClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'swappingturns'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NpcCardHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DisplayThechoices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangingDeckValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NpcChoosingSuit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangingFieldSuitValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CurrentRoundEnded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'StartnewGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GameEnded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangeSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'QuitGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createNewScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'eventFilter'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>,
        // method 'drawCardOnClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DeleteUsedCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DeleteNPCUsedCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CardDrawnPlayer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CardDrawnNpc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CardDrawnField'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowingButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'HiddingButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setskip'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getskip'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SwitchingtoLastScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CallingtheNpcChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CarddropSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CarddrawSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowHelp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void uiscene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<uiscene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->drawCardSignal(); break;
        case 1: _t->handleCardClick(); break;
        case 2: _t->swappingturns(); break;
        case 3: _t->NpcCardHandler(); break;
        case 4: _t->DisplayThechoices(); break;
        case 5: _t->ChangingDeckValue(); break;
        case 6: _t->NpcChoosingSuit(); break;
        case 7: _t->ChangingFieldSuitValue(); break;
        case 8: _t->CurrentRoundEnded(); break;
        case 9: _t->StartnewGame(); break;
        case 10: _t->GameEnded(); break;
        case 11: _t->ChangeSettings(); break;
        case 12: _t->QuitGame(); break;
        case 13: _t->createNewScene(); break;
        case 14: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->drawCardOnClick(); break;
        case 16: _t->DeleteUsedCard(); break;
        case 17: _t->DeleteNPCUsedCard(); break;
        case 18: _t->CardDrawnPlayer(); break;
        case 19: _t->CardDrawnNpc(); break;
        case 20: _t->CardDrawnField(); break;
        case 21: _t->ShowingButtons(); break;
        case 22: _t->HiddingButtons(); break;
        case 23: { bool _r = _t->setskip();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->getskip();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->SwitchingtoLastScene(); break;
        case 26: _t->CallingtheNpcChange(); break;
        case 27: _t->CarddropSound(); break;
        case 28: _t->CarddrawSound(); break;
        case 29: _t->ShowHelp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::drawCardSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::handleCardClick; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::swappingturns; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::NpcCardHandler; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::DisplayThechoices; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::ChangingDeckValue; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::NpcChoosingSuit; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::ChangingFieldSuitValue; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::CurrentRoundEnded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *uiscene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiscene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSuisceneENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int uiscene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void uiscene::drawCardSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1

// SIGNAL 2
void uiscene::swappingturns()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3


// SIGNAL 4
void uiscene::DisplayThechoices()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void uiscene::ChangingDeckValue()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void uiscene::NpcChoosingSuit()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void uiscene::ChangingFieldSuitValue()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void uiscene::CurrentRoundEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
