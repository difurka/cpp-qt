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
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
