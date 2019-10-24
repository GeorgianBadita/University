QT += core
QT -= gui

CONFIG += c++11

TARGET = Prim
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    apm.out \
    apm.in
