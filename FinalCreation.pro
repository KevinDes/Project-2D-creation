#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T10:23:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FInalCreation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shapes.cpp \
    help.cpp \
    shapewidget.cpp

HEADERS  += mainwindow.h \
    shapes.h \
    help.h \
    shapewidget.h

FORMS    += mainwindow.ui \
    shapes.ui \
    help.ui

RESOURCES += \
    resources.qrc
