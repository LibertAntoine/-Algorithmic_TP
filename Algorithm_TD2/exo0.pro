#-------------------------------------------------
#
# Project created by QtCreator 2019-02-03T21:14:48
#
#-------------------------------------------------

lessThan(QT_MAJOR_VERSION, 4): error("requires Qt>4")

QT       += core gui widgets

TARGET = Algorithm_TD2_exo0
TEMPLATE = app
CONFIG += c++11

SOURCES += \
		exo0.cpp \
		lib/mainwindow.cpp \
		lib/thread.cpp \
		lib/array.cpp \
		lib/tp2.cpp \

HEADERS += \
		lib/mainwindow.h \
		lib/thread.h \
		lib/array.h \
		lib/tp2.h \
