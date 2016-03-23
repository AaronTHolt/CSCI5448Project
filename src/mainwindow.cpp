#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set window title
    setWindowTitle(tr("Asteroids3D"));

    GameStateContext* gameStateContext = new GameStateContext();
    setCentralWidget(gameStateContext);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
}

MainWindow::~MainWindow()
{

}
