QT += core
QT -= gui

CONFIG += c++11

TARGET = Depth_first_search
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    dfs.in \
    dfs.out
