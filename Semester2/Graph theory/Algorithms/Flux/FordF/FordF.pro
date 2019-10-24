QT += core
QT -= gui

CONFIG += c++11

TARGET = FordF
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    maxflow.in \
    maxflow.out
