#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_hello_clicked()
{
    auto name = ui->le_name->text();
    QString greet = "Привет из Qt, "+ name+ "!";
    ui->lbl_result->setText(greet);
}

