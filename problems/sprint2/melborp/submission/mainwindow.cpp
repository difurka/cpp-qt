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

void MainWindow::on_pushButton_clicked()
{
    auto text = ui->le_word->text();

    // reverse(text.begin(), text.end());
    // QString new_text = QString::fromStdString(reverse(text));
    ui->le_word->setText(reverse(text));
}

QString MainWindow::reverse(const QString & s) const {
    QString new_s;
    for (auto el : s) {
        new_s = el+new_s;
    }
    return new_s;
}

=======
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
