TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    node.cpp \
    serializer.cpp

HEADERS += \
    node.h \
    serializer.h \
    json.hpp
