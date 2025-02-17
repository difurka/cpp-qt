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

    vector_model_.iterator = vector_model_.items.begin();
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
    ui->txt_capacity->setText(QString::number(vector_model_.items.capacity()));

    ui->list_widget->clear();

    auto preserve_iter = vector_model_.iterator;

    ui->list_widget->clear();

    for (size_t i = 0;i < vector_model_.items.size(); ++i) {
        auto el_num = QString::number(i) + ": " + QString::fromStdString(vector_model_.items[i]);
        ui->list_widget->addItem(el_num);
    }
    ui->list_widget->addItem("end");

    vector_model_.iterator = preserve_iter;

    // ApplyIterator();
}

void MainWindow::ApplyIterator() {
    auto dist = std::distance(vector_model_.items.begin(), vector_model_.iterator);
    ui->list_widget->setCurrentRow(dist);
    if (vector_model_.iterator == vector_model_.items.end()) {
        ui->pb_edit->setDisabled(true);
        ui->pb_pp->setDisabled(true);
        ui->pb_erase->setDisabled(true);
    } else {
        ui->pb_edit->setDisabled(false);
        ui->pb_pp->setDisabled(false);
        ui->pb_erase->setDisabled(false);
    }

    if (vector_model_.iterator == vector_model_.items.begin()) {
        ui->pb_mm->setDisabled(true);
    } else {
        ui->pb_mm->setDisabled(false);
    }

    if (vector_model_.iterator != vector_model_.items.end()) {
        ui->txt_elem_content->setText(QString::fromStdString(*(vector_model_.iterator)));
    } else {
        ui->txt_elem_content->setText("");
    }

}

void MainWindow::on_pb_pop_clicked()
{
    vector_model_.items.pop_back();
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_pb_push_clicked()
{
    QString text = ui->txt_elem_content->text();
    vector_model_.items.push_back(text.toStdString());
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_pb_clear_clicked()
{
    vector_model_.items.clear();

    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_pb_days_clicked()
{
    vector_model_.items={"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_p_month_clicked()
{
    vector_model_.items={"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_pb_pp_clicked()
{
    if (vector_model_.iterator != vector_model_.items.end()){
        ++vector_model_.iterator;
    }
    ApplyIterator();
}


void MainWindow::on_pb_mm_clicked()
{
    if (vector_model_.iterator != vector_model_.items.begin()){
        --vector_model_.iterator;
    }
    ApplyIterator();
}


void MainWindow::on_pb_begin_clicked()
{
    vector_model_.iterator = vector_model_.items.begin();
    ApplyIterator();
}


void MainWindow::on_pb_end_clicked()
{
    vector_model_.iterator = vector_model_.items.end();
    ApplyIterator();
}


void MainWindow::on_pb_edit_clicked()
{
    *(vector_model_.iterator) = ui->txt_elem_content->text().toStdString();
    ApplyModel();
    ApplyIterator();
}


void MainWindow::on_pb_insert_clicked()
{
    vector_model_.items.insert(vector_model_.iterator, ui->txt_elem_content->text().toStdString());
    on_pb_begin_clicked();
    ApplyModel();
    ApplyIterator();
}


void MainWindow::on_pb_erase_clicked()
{
    vector_model_.items.erase(vector_model_.iterator);
    on_pb_begin_clicked();
    ApplyModel();
    ApplyIterator();
}


void MainWindow::on_list_widget_currentRowChanged(int n)
{
    if (n >=0 && n <= (int)vector_model_.items.size()) {
        vector_model_.iterator = vector_model_.items.begin() +n;
        ApplyIterator();
    }
}


void MainWindow::on_btn_resize_clicked()
{
    auto new_size = ui->txt_size->text().toInt();
    vector_model_.items.resize(new_size);
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_btn_reserve_clicked()
{
    auto new_capacity = ui->txt_capacity->text().toInt();
    vector_model_.items.reserve(new_capacity);
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

