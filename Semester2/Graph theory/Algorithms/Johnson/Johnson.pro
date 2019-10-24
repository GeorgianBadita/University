QT += core
QT -= gui

CONFIG += c++11

TARGET = Johnson
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    in.txt \
    out.txt
