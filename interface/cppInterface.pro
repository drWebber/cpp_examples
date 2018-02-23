TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    document.cpp \
    magazine.cpp \
    entity.cpp \
    entitydaoimpl.cpp

HEADERS += \
    printable.h \
    document.h \
    magazine.h \
    dao.h \
    entity.h \
    entitydao.h \
    entitydaoimpl.h

DISTFILES +=
