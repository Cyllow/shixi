#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T23:52:15
#
#-------------------------------------------------

QT       += core gui network

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    camera.h \
    mythread.h

FORMS    += mainwindow.ui
