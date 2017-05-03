#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T11:01:44
#
#-------------------------------------------------

QT       += core gui
#QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimonMagus
TEMPLATE = app



# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    game.h

FORMS    += mainwindow.ui

DISTFILES += \
    graphics/bottom_on.png \
    graphics/bottom_off.png \
    graphics/right_on.png \
    graphics/right_off.png \
    graphics/center.png \
    graphics/top_on.png \
    graphics/top_off.png \
    graphics/left_on.png \
    graphics/left_off.png

RESOURCES += \
    images.qrc
