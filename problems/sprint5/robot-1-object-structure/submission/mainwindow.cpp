#include "mainwindow.h"
#include "ui_mainwindow.h"

<<<<<<< HEAD
MainWindow::MainWindow(Game& game, Controller& controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game_(game)
    , controller_(controller)
=======
MainWindow::MainWindow(Game& game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game_(game)
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD


=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
