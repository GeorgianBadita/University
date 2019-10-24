QT += core
QT -= gui

CONFIG += c++11

TARGET = Dijkstra
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    dijkstra.in \
    dijkstra.out
