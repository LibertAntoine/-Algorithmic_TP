#-------------------------------------------------
#
# Project created by QtCreator 2019-02-03T21:14:48
#
#-------------------------------------------------

lessThan(QT_MAJOR_VERSION, 4): error("requires Qt>4")

QT       += core gui widgets

TARGET = Algorithm_TD5_exo2
TEMPLATE = app
CONFIG += c++11

SOURCES += \
                exo2.cpp \
        lib/mainwindow.cpp \
                lib/array.cpp \
    lib/thread.cpp \
    lib/TP5.cpp \
    lib/hashtable.cpp


HEADERS += \
        lib/mainwindow.h \
                lib/array.h \
    lib/thread.h \
    lib/TP5.h \
    lib/hashtable.h


