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
    "swappingturns",
    "DisplayThechoices",
    "ChangingDeckValue",
    "NpcChoosingSuit",
    "ChangingFieldSuitValue",
    "CurrentRoundEnded",
    "Choosing_Difficulty",
    "ReadingScores",
    "DeleteAllCards",
    "highScore",
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
    "CallingtheNpcChange",
    "CarddropSound",
    "CarddrawSound",
    "ShowHelp",
    "Difficulty",
    "NpcCardHandler",
    "handleCardClick",
    "ScoreHistorySetting",
    "Home",
    "disconnectAllSignals",
    "disconnectSettings",
    "ResumeGame"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSuisceneENDCLASS_t {
    uint offsetsAndSizes[88];
    char stringdata0[8];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[18];
    char stringdata5[18];
    char stringdata6[16];
    char stringdata7[23];
    char stringdata8[18];
    char stringdata9[20];
    char stringdata10[14];
    char stringdata11[15];
    char stringdata12[10];
    char stringdata13[13];
    char stringdata14[10];
    char stringdata15[15];
    char stringdata16[9];
    char stringdata17[15];
    char stringdata18[12];
    char stringdata19[4];
    char stringdata20[8];
    char stringdata21[6];
    char stringdata22[16];
    char stringdata23[15];
    char stringdata24[18];
    char stringdata25[16];
    char stringdata26[13];
    char stringdata27[15];
    char stringdata28[15];
    char stringdata29[15];
    char stringdata30[8];
    char stringdata31[8];
    char stringdata32[20];
    char stringdata33[14];
    char stringdata34[14];
    char stringdata35[9];
    char stringdata36[11];
    char stringdata37[15];
    char stringdata38[16];
    char stringdata39[20];
    char stringdata40[5];
    char stringdata41[21];
    char stringdata42[19];
    char stringdata43[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSuisceneENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSuisceneENDCLASS_t qt_meta_stringdata_CLASSuisceneENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "uiscene"
        QT_MOC_LITERAL(8, 14),  // "drawCardSignal"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 13),  // "swappingturns"
        QT_MOC_LITERAL(38, 17),  // "DisplayThechoices"
        QT_MOC_LITERAL(56, 17),  // "ChangingDeckValue"
        QT_MOC_LITERAL(74, 15),  // "NpcChoosingSuit"
        QT_MOC_LITERAL(90, 22),  // "ChangingFieldSuitValue"
        QT_MOC_LITERAL(113, 17),  // "CurrentRoundEnded"
        QT_MOC_LITERAL(131, 19),  // "Choosing_Difficulty"
        QT_MOC_LITERAL(151, 13),  // "ReadingScores"
        QT_MOC_LITERAL(165, 14),  // "DeleteAllCards"
        QT_MOC_LITERAL(180, 9),  // "highScore"
        QT_MOC_LITERAL(190, 12),  // "StartnewGame"
        QT_MOC_LITERAL(203, 9),  // "GameEnded"
        QT_MOC_LITERAL(213, 14),  // "ChangeSettings"
        QT_MOC_LITERAL(228, 8),  // "QuitGame"
        QT_MOC_LITERAL(237, 14),  // "createNewScene"
        QT_MOC_LITERAL(252, 11),  // "eventFilter"
        QT_MOC_LITERAL(264, 3),  // "obj"
        QT_MOC_LITERAL(268, 7),  // "QEvent*"
        QT_MOC_LITERAL(276, 5),  // "event"
        QT_MOC_LITERAL(282, 15),  // "drawCardOnClick"
        QT_MOC_LITERAL(298, 14),  // "DeleteUsedCard"
        QT_MOC_LITERAL(313, 17),  // "DeleteNPCUsedCard"
        QT_MOC_LITERAL(331, 15),  // "CardDrawnPlayer"
        QT_MOC_LITERAL(347, 12),  // "CardDrawnNpc"
        QT_MOC_LITERAL(360, 14),  // "CardDrawnField"
        QT_MOC_LITERAL(375, 14),  // "ShowingButtons"
        QT_MOC_LITERAL(390, 14),  // "HiddingButtons"
        QT_MOC_LITERAL(405, 7),  // "setskip"
        QT_MOC_LITERAL(413, 7),  // "getskip"
        QT_MOC_LITERAL(421, 19),  // "CallingtheNpcChange"
        QT_MOC_LITERAL(441, 13),  // "CarddropSound"
        QT_MOC_LITERAL(455, 13),  // "CarddrawSound"
        QT_MOC_LITERAL(469, 8),  // "ShowHelp"
        QT_MOC_LITERAL(478, 10),  // "Difficulty"
        QT_MOC_LITERAL(489, 14),  // "NpcCardHandler"
        QT_MOC_LITERAL(504, 15),  // "handleCardClick"
        QT_MOC_LITERAL(520, 19),  // "ScoreHistorySetting"
        QT_MOC_LITERAL(540, 4),  // "Home"
        QT_MOC_LITERAL(545, 20),  // "disconnectAllSignals"
        QT_MOC_LITERAL(566, 18),  // "disconnectSettings"
        QT_MOC_LITERAL(585, 10)   // "ResumeGame"
    },
    "uiscene",
    "drawCardSignal",
    "",
    "swappingturns",
    "DisplayThechoices",
    "ChangingDeckValue",
    "NpcChoosingSuit",
    "ChangingFieldSuitValue",
    "CurrentRoundEnded",
    "Choosing_Difficulty",
    "ReadingScores",
    "DeleteAllCards",
    "highScore",
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
    "CallingtheNpcChange",
    "CarddropSound",
    "CarddrawSound",
    "ShowHelp",
    "Difficulty",
    "NpcCardHandler",
    "handleCardClick",
    "ScoreHistorySetting",
    "Home",
    "disconnectAllSignals",
    "disconnectSettings",
    "ResumeGame"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSuisceneENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  248,    2, 0x06,    1 /* Public */,
       3,    0,  249,    2, 0x06,    2 /* Public */,
       4,    0,  250,    2, 0x06,    3 /* Public */,
       5,    0,  251,    2, 0x06,    4 /* Public */,
       6,    0,  252,    2, 0x06,    5 /* Public */,
       7,    0,  253,    2, 0x06,    6 /* Public */,
       8,    0,  254,    2, 0x06,    7 /* Public */,
       9,    0,  255,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  256,    2, 0x0a,    9 /* Public */,
      11,    0,  257,    2, 0x0a,   10 /* Public */,
      12,    0,  258,    2, 0x0a,   11 /* Public */,
      13,    0,  259,    2, 0x0a,   12 /* Public */,
      14,    0,  260,    2, 0x0a,   13 /* Public */,
      15,    0,  261,    2, 0x0a,   14 /* Public */,
      16,    0,  262,    2, 0x0a,   15 /* Public */,
      17,    0,  263,    2, 0x0a,   16 /* Public */,
      18,    2,  264,    2, 0x0a,   17 /* Public */,
      22,    0,  269,    2, 0x0a,   20 /* Public */,
      23,    0,  270,    2, 0x0a,   21 /* Public */,
      24,    0,  271,    2, 0x0a,   22 /* Public */,
      25,    0,  272,    2, 0x0a,   23 /* Public */,
      26,    0,  273,    2, 0x0a,   24 /* Public */,
      27,    0,  274,    2, 0x0a,   25 /* Public */,
      28,    0,  275,    2, 0x0a,   26 /* Public */,
      29,    0,  276,    2, 0x0a,   27 /* Public */,
      30,    0,  277,    2, 0x0a,   28 /* Public */,
      31,    0,  278,    2, 0x0a,   29 /* Public */,
      32,    0,  279,    2, 0x0a,   30 /* Public */,
      33,    0,  280,    2, 0x0a,   31 /* Public */,
      34,    0,  281,    2, 0x0a,   32 /* Public */,
      35,    0,  282,    2, 0x0a,   33 /* Public */,
      36,    0,  283,    2, 0x0a,   34 /* Public */,
      37,    0,  284,    2, 0x0a,   35 /* Public */,
      38,    0,  285,    2, 0x0a,   36 /* Public */,
      39,    0,  286,    2, 0x0a,   37 /* Public */,
      40,    0,  287,    2, 0x0a,   38 /* Public */,
      41,    0,  288,    2, 0x0a,   39 /* Public */,
      42,    0,  289,    2, 0x0a,   40 /* Public */,
      43,    0,  290,    2, 0x0a,   41 /* Public */,

 // signals: parameters
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
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 20,   19,   21,
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
    QMetaType::Void,
    QMetaType::Void,
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
        // method 'swappingturns'
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
        // method 'Choosing_Difficulty'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ReadingScores'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DeleteAllCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highScore'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        // method 'CallingtheNpcChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CarddropSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CarddrawSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowHelp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Difficulty'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NpcCardHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCardClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ScoreHistorySetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Home'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectAllSignals'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ResumeGame'
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
        case 1: _t->swappingturns(); break;
        case 2: _t->DisplayThechoices(); break;
        case 3: _t->ChangingDeckValue(); break;
        case 4: _t->NpcChoosingSuit(); break;
        case 5: _t->ChangingFieldSuitValue(); break;
        case 6: _t->CurrentRoundEnded(); break;
        case 7: _t->Choosing_Difficulty(); break;
        case 8: _t->ReadingScores(); break;
        case 9: _t->DeleteAllCards(); break;
        case 10: { int _r = _t->highScore();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->StartnewGame(); break;
        case 12: _t->GameEnded(); break;
        case 13: _t->ChangeSettings(); break;
        case 14: _t->QuitGame(); break;
        case 15: _t->createNewScene(); break;
        case 16: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->drawCardOnClick(); break;
        case 18: _t->DeleteUsedCard(); break;
        case 19: _t->DeleteNPCUsedCard(); break;
        case 20: _t->CardDrawnPlayer(); break;
        case 21: _t->CardDrawnNpc(); break;
        case 22: _t->CardDrawnField(); break;
        case 23: _t->ShowingButtons(); break;
        case 24: _t->HiddingButtons(); break;
        case 25: { bool _r = _t->setskip();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: { bool _r = _t->getskip();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->CallingtheNpcChange(); break;
        case 28: _t->CarddropSound(); break;
        case 29: _t->CarddrawSound(); break;
        case 30: _t->ShowHelp(); break;
        case 31: _t->Difficulty(); break;
        case 32: _t->NpcCardHandler(); break;
        case 33: _t->handleCardClick(); break;
        case 34: _t->ScoreHistorySetting(); break;
        case 35: _t->Home(); break;
        case 36: _t->disconnectAllSignals(); break;
        case 37: _t->disconnectSettings(); break;
        case 38: _t->ResumeGame(); break;
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
            if (_t _q_method = &uiscene::swappingturns; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::DisplayThechoices; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::ChangingDeckValue; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::NpcChoosingSuit; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::ChangingFieldSuitValue; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::CurrentRoundEnded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (uiscene::*)();
            if (_t _q_method = &uiscene::Choosing_Difficulty; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
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
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void uiscene::drawCardSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void uiscene::swappingturns()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void uiscene::DisplayThechoices()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void uiscene::ChangingDeckValue()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void uiscene::NpcChoosingSuit()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void uiscene::ChangingFieldSuitValue()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void uiscene::CurrentRoundEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void uiscene::Choosing_Difficulty()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
