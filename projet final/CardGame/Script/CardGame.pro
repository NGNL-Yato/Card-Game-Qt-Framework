QT       += core gui
QT += multimedia
QT += core


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#qmake enables Qt Core and Qt GUI modules by default, even if you don't specify them
#explicitly in the project file. You can opt out of using a default module if you want. For
#example, you can disable Qt GUI by adding QT -= gui to the project file
SOURCES += \
    Deckk.cpp \
    Field.cpp \
    LogicOfgame.cpp \
    Npc.cpp \
    Player.cpp \
    Uiscene.cpp \
    main.cpp

HEADERS += \
    Deckk.h \
    Field.h \
    LogicOfgame.h \
    Npc.h \
    Player.h \
    Uiscene.h


TRANSLATIONS += \
    CardGame_fr_MA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=

DISTFILES +=
