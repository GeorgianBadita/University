QT += core
QT -= gui

CONFIG += c++11

TARGET = Kruskal
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    apm.in \
    apm.out
