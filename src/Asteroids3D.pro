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
BULLETDEPEND = $$system(find $$BULLETPATH/bin -iname libBulletDynamics*)
BULLETDEPEND += $$system(find $$BULLETPATH/bin -iname libBullet3Common*)
BULLETDEPEND += $$system(find $$BULLETPATH/bin -iname libBulletCollision*)
BULLETDEPEND += $$system(find $$BULLETPATH/bin -iname libLinearMath*)                

message(The BULLETPATH = ($$BULLETDEPEND))
              
INCLUDEPATH += $$system(find . -type d)
INCLUDEPATH += $$BULLETPATH

DEPENDPATH += BULLETDEPEND

include(Sources.pro)
