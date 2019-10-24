QT += core
QT -= gui

CONFIG += c++11

TARGET = Breadth_first_search
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    bfs.in \
    bfs.out
