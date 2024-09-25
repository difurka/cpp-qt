#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UpdateSizeLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD

=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
void MainWindow::UpdateSizeLabel() {
    // Доработайте этот метод.
    auto new_text = std::to_string(width()) + "x" + std::to_string(height());
    ui->lbl_size->setText(QString::fromStdString(new_text));
<<<<<<< HEAD
    ui->lbl_size->resize(width(), height());
    ui->lbl_size->move(0,0);
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}
