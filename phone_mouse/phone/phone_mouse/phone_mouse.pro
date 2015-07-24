#-------------------------------------------------
#
# Project created by QtCreator 2013-12-26T14:39:50
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sensors
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = phone_mouse
TEMPLATE = app


SOURCES += main.cpp\
    SetUp.cpp \
    Udpserver.cpp \
    advance_button.cpp

HEADERS  += \
    SetUp.h \
    Udpserver.h \
    advance_button.h

FORMS    += \
    setup.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    src.qrc

OTHER_FILES += \
    advance_button.pri

