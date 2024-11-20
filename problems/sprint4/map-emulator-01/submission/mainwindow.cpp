#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    // Применить модель.
<<<<<<< HEAD
    if (map_model_.items.empty()) {
        ui->btn_erase->setDisabled(true);
    } else {
        ui->btn_erase->setEnabled(true);
    }
    ui->txt_size->setText(QString::number(map_model_.items.size()));
    // ui->txt_capacity->setText(QString::number(vector_model_.items.capacity()));

    ui->list_widget->clear();

    auto preserve_iter = map_model_.iterator;

    ui->list_widget->clear();

    for (auto [k,v] : map_model_.items) {
        auto el_num = QString::fromStdString(k)+ ": " + QString::fromStdString(v);
        ui->list_widget->addItem(el_num);
    }
    ui->list_widget->addItem("end");

    map_model_.iterator = preserve_iter;
=======
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
}

void MainWindow::ApplyIterator() {
    // Применить итератор.
<<<<<<< HEAD
    auto dist = std::distance(map_model_.items.begin(), map_model_.iterator);
    ui->list_widget->setCurrentRow(dist);
    if (map_model_.iterator == map_model_.items.end()) {
        // ui->btn_edit->setDisabled(true);
        ui->btn_inc_iterator->setDisabled(true);
        ui->btn_erase->setDisabled(true);
    } else {
        // ui->pb_edit->setDisabled(false);
        ui->btn_inc_iterator->setDisabled(false);
        ui->btn_erase->setDisabled(false);
    }

    if (map_model_.iterator == map_model_.items.begin()) {
        ui->btn_dec_iterator->setDisabled(true);
    } else {
        ui->btn_dec_iterator->setDisabled(false);
    }

    if (map_model_.iterator != map_model_.items.end()) {
        ui->txt_elem_key->setText(QString::fromStdString(map_model_.iterator->first));
        ui->txt_elem_value->setText(QString::fromStdString(map_model_.iterator->second));
    } else {
        ui->txt_elem_key->setText("");
        ui->txt_elem_value->setText("");
    }
}

void MainWindow::on_btn_books_clicked()
{
    map_model_.items =         {
                        {"Т. Пратчетт", "Плоский мир"},
                        {"Р. Брэдбери", "Лёд и пламя"},
                        {"Д. Адамс", "В основном безвредна"},
                        {"Ф. Дик", "Солнечная лотерея"},
                        {"А. и Б. Стругацкие", "Жук в муравейнике"},
                        {"Ф. Кафка", "Превращение"},
                        };

    ApplyModel();
    on_btn_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_btn_words_clicked()
{
    map_model_.items ={
                        {"Book", "Книга"},
                        {"Cinnamon", "Корица"},
                        {"Cup", "Чашка"},
                        {"Kettle", "Чайник"},
                        {"Saucer", "Блюдце"},
                        {"Sugar", "Сахар"},
                        {"Tea", "Чай"},
                        {"Teaspoon", "Чайная ложка"},
                        };



    ApplyModel();
    on_btn_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_btn_begin_clicked()
{
    map_model_.iterator = map_model_.items.begin();

    ApplyIterator();
}




void MainWindow::on_btn_inc_iterator_clicked()
{
    if (map_model_.iterator != map_model_.items.end()) ++map_model_.iterator;
    ApplyIterator();
}


void MainWindow::on_btn_dec_iterator_clicked()
{
    if (map_model_.iterator != map_model_.items.begin()) --map_model_.iterator;
    ApplyIterator();
}


void MainWindow::on_btn_end_clicked()
{
    map_model_.iterator = map_model_.items.end();

    ApplyIterator();
}


void MainWindow::on_btn_set_by_key_clicked()
{
    auto name = ui->txt_elem_key->text().toStdString();
    auto val = ui->txt_elem_value->text().toStdString();
    // auto it = map_model_.items.find(name);
    // if (it == map_model_.items.end()) {
        map_model_.items[name] = val;
    // }

        ApplyModel();
        // on_btn_begin_clicked();
        ApplyIterator();


}


void MainWindow::on_btn_erase_clicked()
{
    auto name = ui->txt_elem_key->text().toStdString();

    auto it = map_model_.items.find(name);
    if (it != map_model_.items.end()) {
        map_model_.items.erase(it);
    }

    ApplyModel();
    on_btn_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_btn_clear_clicked()
{
    map_model_.items.clear();

    ApplyModel();
    on_btn_begin_clicked();
    ApplyIterator();
}


void MainWindow::on_btn_find_clicked()
{
    auto name = ui->txt_elem_key->text().toStdString();

    auto it = map_model_.items.find(name);
    // if (it != map_model_.items.end()) {
        map_model_.iterator = it;
    // }

        ApplyIterator();
}


void MainWindow::on_list_widget_currentRowChanged(int n)
{
    if (n >=0 && n <= (int)map_model_.items.size()) {
        map_model_.iterator = map_model_.items.begin();
        std::advance(map_model_.iterator,n);
        ApplyIterator();
    }
}

=======
}
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
