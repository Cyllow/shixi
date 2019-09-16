#-------------------------------------------------
#
# Project created by QtCreator 2019-07-14T17:29:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv

DISTFILES += \
    haarcascade_eye_tree_eyeglasses.xml \
    haarcascade_frontalface_alt2.xml
