#-------------------------------------------------
#
# Project created by QtCreator 2015-02-02T15:08:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lazer2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamescene.cpp \
    player.cpp \
    laser.cpp \
    bullet.cpp \
    enemy.cpp \
    youlost.cpp \
    boom.cpp \
    lostlife.cpp \
    oneup.cpp \
    senemy.cpp \
    oneuporb.cpp \
    instruction.cpp \
    stagnantimages.cpp

HEADERS  += mainwindow.h \
    gamescene.h \
    player.h \
    laser.h \
    bullet.h \
    enemy.h \
    youlost.h \
    boom.h \
    lostlife.h \
    oneup.h \
    senemy.h \
    oneuporb.h \
    instruction.h \
    stagnantimages.h

FORMS    += mainwindow.ui

CONFIG += c++11

RESOURCES += \
    lazer.qrc
