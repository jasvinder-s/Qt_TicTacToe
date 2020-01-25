#-------------------------------------------------
#
# Project created by QtCreator 2010-05-06T18:38:19
#
#-------------------------------------------------

QT       += core gui

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        tictactoe.cpp \
    tictactoescene.cpp \
    gamelogic.cpp \
    testgui.cpp

HEADERS  += tictactoe.h \
    tictactoescene.h \
    gamelogic.h \
    testgui.h

FORMS    += tictactoe.ui

CONFIG += mobility qtestlib
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe18920f9
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
