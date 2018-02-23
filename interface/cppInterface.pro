TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    document.cpp \
    magazine.cpp

HEADERS += \
    printable.h \
    document.h \
    magazine.h
