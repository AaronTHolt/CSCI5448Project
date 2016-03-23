#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T11:47:37
#
#-------------------------------------------------

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asteroids3D

TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    gamestate.cpp \
    playablestate.cpp \
    welcomestate.cpp \
    gamestatecontext.cpp \
    profileselectstate.cpp \
    optionsstate.cpp \
    levelselectstate.cpp \
    statsstate.cpp

HEADERS  += mainwindow.h \
    gamestate.h \
    playablestate.h \
    welcomestate.h \
    gamestatecontext.h \
    profileselectstate.h \
    optionsstate.h \
    levelselectstate.h \
    statsstate.h
