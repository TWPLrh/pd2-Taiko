#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T23:10:28
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    opengui.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    opengui.h \
    about.h

FORMS    += mainwindow.ui \
    opengui.ui \
    about.ui

RESOURCES += \
    main.qrc \
    opengui.qrc \
    about.qrc

DISTFILES +=
