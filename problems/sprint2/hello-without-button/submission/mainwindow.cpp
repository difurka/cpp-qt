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
<<<<<<< HEAD

void MainWindow::on_le_name_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        ui->lbl_result->setText("Введите имя");
    } else {
        // auto name = arg1;
        QString greet = "Привет из Qt, "+ arg1+ "!";
        ui->lbl_result->setText(greet);

    }

}

=======
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
