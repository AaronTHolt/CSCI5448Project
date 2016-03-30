#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T11:47:37
#
#-------------------------------------------------

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asteroids3D
DESTDIR = ..
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

CONFIG += c++11

TEMPLATE = app

BULLETPATH += $$system(ls -d ../bullet*)
LIBS += -L$$BULLETPATH/bin
include(bulletLibs.pro)

message(The BULLETPATH = ($$BULLETDEPEND))
              
INCLUDEPATH += $$system(find . -type d)
INCLUDEPATH += $$BULLETPATH $$BULLETPATH/src

DEPENDPATH += BULLETDEPEND

include(Sources.pro)
