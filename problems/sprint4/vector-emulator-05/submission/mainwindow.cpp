<<<<<<< HEAD
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    vector_model_.iterator = vector_model_.items.begin();

    std::random_device rd;
    std::mt19937 gen(rd());
    random_gen_ = gen;
    ApplyModel();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetRandomGen(const std::mt19937& random_gen) {
    random_gen_ = random_gen;
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


void MainWindow::on_pb_count_clicked()
{
    auto text = ui->le_count->text();
    auto res = std::count_if(
        vector_model_.items.begin(),
        vector_model_.items.end(),
        [&](const std::string& el ){return el == text.toStdString();}
        );
    ui->lbl_count->setText(QString::number(res));
}


void MainWindow::on_pb_find_clicked()
{
    auto text = ui->txt_elem_content->text();
    vector_model_.iterator = std::find_if(
        vector_model_.items.begin(),
        vector_model_.items.end(),
        [&](const std::string& el ){return el == text.toStdString();}
        );
    ApplyIterator();
}


void MainWindow::on_pb_min_clicked()
{
    vector_model_.iterator = std::min_element(
        vector_model_.items.begin(),
        vector_model_.items.end()
        );

    ApplyIterator();
}


void MainWindow::on_pb_max_clicked()
{
    vector_model_.iterator = std::max_element(
        vector_model_.items.begin(),
        vector_model_.items.end()
        );

    ApplyIterator();
}


void MainWindow::on_pb_sort_clicked()
{
    std::sort(
        vector_model_.items.begin(),
        vector_model_.items.end()
        );
    ApplyModel();
    // on_pb_begin_clicked();
    ApplyIterator();

}


void MainWindow::on_pb_sOrT_clicked()
{

    auto comp = [&](const std::string & s1, const std::string& s2) { return QString::compare(QString::fromStdString(s1), QString::fromStdString(s2), Qt::CaseInsensitive) < 0;};
    std::sort(
    vector_model_.items.begin(),
    vector_model_.items.end(),
    comp
        );

    ApplyModel();
    // on_pb_begin_clicked();
    ApplyIterator();

}


void MainWindow::on_pb_reverse_clicked()
{
    std::reverse(
        vector_model_.items.begin(),
        vector_model_.items.end()

        );
    ApplyModel();
    // on_pb_begin_clicked();
    ApplyIterator();

}


void MainWindow::on_pb_unique_clicked()
{
    // auto comp = [&](const std::string & s1, const std::string& s2) { return QString::compare(QString::fromStdString(s1), QString::fromStdString(s2), Qt::CaseInsensitive) < 0;};
    if (std::is_sorted(vector_model_.items.begin(),
                       vector_model_.items.end())) {
        auto it = std::unique(vector_model_.items.begin(),
                    vector_model_.items.end());
        vector_model_.items.erase(it, vector_model_.items.end());
        ApplyModel();
        on_pb_begin_clicked();
        ApplyIterator();
    }
}


void MainWindow::on_pb_shuffle_clicked()
{
    std::shuffle(vector_model_.items.begin(),
                 vector_model_.items.end(), random_gen_);
    ApplyModel();
    ApplyIterator();

}

=======
// Используйте предыдущую реализацию.
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
