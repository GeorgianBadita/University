QT += core
QT -= gui

CONFIG += c++11

TARGET = Huffman
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    input_file.txt \
    input_file_huffman.txt
