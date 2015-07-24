#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T15:02:33
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sensors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = remote_tool
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    mouse_dialog.cpp \
    advance_button.cpp \
    remote_dialog.cpp \
    netset_dialog.cpp

HEADERS  += \
    mainwindow.h \
    mouse_dialog.h \
    advance_button.h \
    remote_dialog.h \
    netset_dialog.h

FORMS    += \
    mainwindow.ui \
    mouse_dialog.ui \
    remote_dialog.ui \
    netset_dialog.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resource.qrc

