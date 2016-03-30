#!/bin/bash

if [ -e "2.83.6.zip" ]
then
    echo "Already have archive"
else
    wget "https://github.com/bulletphysics/bullet3/archive/2.83.6.zip"
fi

if [ -d "bullet3-2.83.6" ]
then
    echo "Already built bullet"
else
    unzip 2.83.6.zip
    cd bullet3-2.83.6/build3
    ./premake4_linux64 gmake
    cd gmake
    make
    cd ../../..
fi

if [ -e "./src/bulletLibs.pro" ]
then
    echo "Already have the Bullet Libs qmake file"
else
    cd bullet3-2.83.6/bin
    for elt in $(cat ../../libsForBullet.txt); do
	echo "LIBS += $(pwd)/$(ls $elt*)" >> ../../src/bulletLibs.pro
    done
fi
