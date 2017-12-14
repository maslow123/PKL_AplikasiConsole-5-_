QT += core network
QT -= gui

CONFIG += c++11

TARGET = AplikasiConsole
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    redis.cpp \
    client.cpp \
    time.cpp

HEADERS += \
    redis.h \
    client.h \
    time.h \
    time2.h
