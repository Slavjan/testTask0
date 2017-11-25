TEMPLATE = app
CONFIG += console
CONFIG += c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    node.cpp \
    serializer.cpp

HEADERS += \
    node.h \
    serializer.h \
    json.hpp
