QT += core
QT -= gui

CONFIG += c++11

TARGET = best_flow
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    max_flow.in \
    max_flow.out
