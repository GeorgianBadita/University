QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14


TARGET = lab10-11
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    cart.cpp \
    export.cpp \
    movie.cpp \
    undo.cpp \
    validator.cpp \
    repository.cpp \
    service.cpp \
    helper.cpp \
    tests.cpp \
    user_interface.cpp \
    gui.cpp \
    observer.cpp \
    mylistmodel.cpp

HEADERS += \
    cart.h \
    export.h \
    movie.h \
    undo.h \
    validator.h \
    repository.h \
    service.h \
    helper.h \
    tests.h \
    user_interface.h \
    gui.h \
    observer.h \
    mylistmodel.h

DISTFILES += \
    text_html.html \
    movies.txt \
    file_html.html \
    text_csv.csv \
    file_csv.csv
