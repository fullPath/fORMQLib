#-------------------------------------------------
#
# Project created by QtCreator 2011-01-31T20:18:45
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = fORMQLib
TEMPLATE = lib

DEFINES += FORMQLIB_LIBRARY

SOURCES += \
    attribute.cpp \
    attributes/integer.cpp \
    modelbase.cpp

HEADERS += fORMQLib_global.h \
    model.h \
    attribute.h \
    form_exceptions.h \
    attributes/integer.h \
    fORMQLib.h \
    modelbase.h
