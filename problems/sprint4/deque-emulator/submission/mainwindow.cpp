#include "algo.h"
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

    deque_model_.iterator = deque_model_.items.begin();

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
    if (deque_model_.items.empty()) {
        ui->pb_pop->setDisabled(true);
        ui->pb_erase->setDisabled(true);
        ui->pb_pop_front->setDisabled(true);
    } else {
        ui->pb_pop->setEnabled(true);
        ui->pb_erase->setEnabled(true);
        ui->pb_pop_front->setEnabled(true);
    }
    ui->txt_size->setText(QString::number(deque_model_.items.size()));
    ui->list_widget->clear();
    auto preserve_iter = deque_model_.iterator;
    ui->list_widget->clear();
    for (size_t i = 0;i < deque_model_.items.size(); ++i) {
        auto el_num = QString::number(i) + ": " + QString::fromStdString(deque_model_.items[i]);
        ui->list_widget->addItem(el_num);
    }
    ui->list_widget->addItem("end");
    deque_model_.iterator = preserve_iter;
}

void MainWindow::ApplyIterator() {
    auto dist = std::distance(deque_model_.items.begin(), deque_model_.iterator);
    ui->list_widget->setCurrentRow(dist);
    if (deque_model_.iterator == deque_model_.items.end()) {
        ui->pb_edit->setDisabled(true);
        ui->pb_pp->setDisabled(true);
        ui->pb_erase->setDisabled(true);
    } else {
        ui->pb_edit->setDisabled(false);
        ui->pb_pp->setDisabled(false);
        ui->pb_erase->setDisabled(false);
    }

    if (deque_model_.iterator == deque_model_.items.begin()) {
        ui->pb_mm->setDisabled(true);
    } else {
        ui->pb_mm->setDisabled(false);
    }

    if (deque_model_.iterator != deque_model_.items.end()) {
        ui->txt_elem_content->setText(QString::fromStdString(*(deque_model_.iterator)));
    } else {
        ui->txt_elem_content->setText("");
    }
}

void MainWindow::on_pb_pop_clicked() {
    deque_model_.items.pop_back();
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_push_clicked() {
    QString text = ui->txt_elem_content->text();
    deque_model_.items.push_back(text.toStdString());
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_clear_clicked() {
    deque_model_.items.clear();
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_pp_clicked() {
    if (deque_model_.iterator != deque_model_.items.end()){
        ++deque_model_.iterator;
    }
    ApplyIterator();
}

void MainWindow::on_pb_mm_clicked() {
    if (deque_model_.iterator != deque_model_.items.begin()){
        --deque_model_.iterator;
    }
    ApplyIterator();
}

void MainWindow::on_pb_begin_clicked() {
    deque_model_.iterator = deque_model_.items.begin();
    ApplyIterator();
}

void MainWindow::on_pb_end_clicked() {
    deque_model_.iterator = deque_model_.items.end();
    ApplyIterator();
}

void MainWindow::on_pb_edit_clicked() {
    *(deque_model_.iterator) = ui->txt_elem_content->text().toStdString();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_pb_insert_clicked() {
    deque_model_.items.insert(deque_model_.iterator, ui->txt_elem_content->text().toStdString());
    on_pb_begin_clicked();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_pb_erase_clicked() {
    deque_model_.items.erase(deque_model_.iterator);
    on_pb_begin_clicked();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_list_widget_currentRowChanged(int n) {
    if (n >=0 && n <= (int)deque_model_.items.size()) {
        deque_model_.iterator = deque_model_.items.begin() +n;
        ApplyIterator();
    }
}

void MainWindow::on_btn_resize_clicked() {
    auto new_size = ui->txt_size->text().toInt();
    deque_model_.items.resize(new_size);
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_count_clicked() {
    auto text = ui->le_count->text();
    auto res = std::count_if(
        deque_model_.items.begin(),
        deque_model_.items.end(),
        [&](const std::string& el ){return el == text.toStdString();}
        );
    ui->lbl_count->setText(QString::number(res));
}

void MainWindow::on_pb_find_clicked() {
    auto text = ui->txt_elem_content->text();
    deque_model_.iterator = std::find_if(
        deque_model_.items.begin(),
        deque_model_.items.end(),
        [&](const std::string& el ){return el == text.toStdString();}
        );
    ApplyIterator();
}

void MainWindow::on_pb_min_clicked() {
    deque_model_.iterator = std::min_element(
        deque_model_.items.begin(),
        deque_model_.items.end()
        );
    ApplyIterator();
}


void MainWindow::on_pb_max_clicked() {
    deque_model_.iterator = std::max_element(
        deque_model_.items.begin(),
        deque_model_.items.end()
        );
    ApplyIterator();
}

void MainWindow::on_pb_sort_clicked() {
    deque_model_.items = MergeSort(deque_model_.items, std::less());
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_sOrT_clicked() {
    auto comp = [&](const std::string & s1, const std::string& s2) {
        return QString::compare(
                            QString::fromStdString(s1),
                            QString::fromStdString(s2),
                            Qt::CaseInsensitive
                               ) < 0;};
    deque_model_.items = MergeSort(deque_model_.items, comp);
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_reverse_clicked() {
    std::reverse(
        deque_model_.items.begin(),
        deque_model_.items.end()
        );
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_pb_unique_clicked() {
    if (!std::is_sorted(deque_model_.items.begin(),
                       deque_model_.items.end())) {
        return;
    }

    auto it = std::unique(deque_model_.items.begin(),
                          deque_model_.items.end());
    deque_model_.items.erase(it, deque_model_.items.end());
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_shuffle_clicked() {
    std::shuffle(deque_model_.items.begin(),
                 deque_model_.items.end(), random_gen_);
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_pb_push_front_clicked() {
    QString text = ui->txt_elem_content->text();
    deque_model_.items.push_front(text.toStdString());
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_pop_front_clicked() {
    deque_model_.items.pop_front();
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_lower_bound_clicked() {
    if (!std::is_sorted(deque_model_.items.begin(), deque_model_.items.end())) {
        return;
    }
    auto text = ui->txt_elem_content->text();
    deque_model_.iterator = std::lower_bound(
        deque_model_.items.begin(),
        deque_model_.items.end(),
        text.toStdString()
        );
    ApplyIterator();
}

void MainWindow::on_pb_upper_bound_clicked() {
    if (!std::is_sorted(deque_model_.items.begin(), deque_model_.items.end())) {
        return;
    }
    auto text = ui->txt_elem_content->text();
    deque_model_.iterator = std::upper_bound(
        deque_model_.items.begin(),
        deque_model_.items.end(),
        text.toStdString()
        );
    ApplyIterator();
}

void MainWindow::on_pb_tea_clicked() {
    static std::deque<std::string> tea {
        "Чай Лунцзин",
        "Эрл Грей",
        "Сенча",
        "Пуэр",
        "Дарджилинг",
        "Ассам",
        "Матча",
        "Ганпаудер",
        "Оолонг",
        "Лапсанг Сушонг"
    };
    deque_model_.items = tea;
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}

void MainWindow::on_pb_cakes_clicked() {
    static std::deque<std::string> cakes {
        "Красный бархат",
        "Наполеон",
        "Медовик",
        "Тирамису",
        "Прага",
        "Чизкейк",
        "Захер",
        "Эстерхази",
        "Морковный торт",
        "Чёрный лес",
    };
    deque_model_.items = cakes;
    ApplyModel();
    on_pb_begin_clicked();
    ApplyIterator();
}
