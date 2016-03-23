#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication asteroids3d(argc, argv);
    MainWindow window;
    window.show();
    return asteroids3d.exec();
}
