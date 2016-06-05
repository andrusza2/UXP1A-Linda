TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lindainterface.cpp \
    client.cpp \
    lindapattern.cpp \
    lindatuple.cpp

HEADERS += \
    lindainterface.h \
    lindapattern.h \
    lindatuple.h
