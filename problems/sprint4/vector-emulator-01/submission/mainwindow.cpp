#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ApplyModel();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ApplyModel() {
    if (vector_model_.items.empty()) {
        ui->pb_pop->setDisabled(true);
    } else {
        ui->pb_pop->setEnabled(true);
    }
    ui->txt_size->setText(QString::number(vector_model_.items.size()));

    ui->list_widget->clear();
    for (size_t i = 0;i < vector_model_.items.size(); ++i) {
        auto el_num = QString::number(i) + ": " + QString::fromStdString(vector_model_.items[i]);
        ui->list_widget->addItem(el_num);
    }
}

void MainWindow::on_pb_pop_clicked()
{
    vector_model_.items.pop_back();
    ApplyModel();
}


void MainWindow::on_pb_push_clicked()
{
    QString text = ui->txt_elem_content->text();
    vector_model_.items.push_back(text.toStdString());
    ApplyModel();
}


void MainWindow::on_pb_clear_clicked()
{
    vector_model_.items.clear();
    ApplyModel();
}


void MainWindow::on_pb_days_clicked()
{
    vector_model_.items={"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    ApplyModel();
}


void MainWindow::on_p_month_clicked()
{
    vector_model_.items={"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    ApplyModel();
}

