QT += core
QT -= gui

CONFIG += c++11

TARGET = disjoint_set
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    disjoint.in \
    disjoint.out
