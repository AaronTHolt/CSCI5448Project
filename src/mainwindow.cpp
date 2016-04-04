#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Asteroids3D"));

    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    GameStateContext* gameStateContext = new GameStateContext();
    gameStateContext->setGeometry(QDesktopWidget().geometry());
    setCentralWidget(gameStateContext);
}

MainWindow::~MainWindow()
{

}
