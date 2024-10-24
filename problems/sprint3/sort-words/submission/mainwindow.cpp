#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD
<<<<<<< HEAD
void MainWindow::on_rb_asc_clicked()
{
    // Ваш код.
    on_le_unsorted_textChanged("");
}

void MainWindow::on_rb_desc_clicked()
{
    // Ваш код.
    on_le_unsorted_textChanged("");
=======
void MainWindow::on_rb_greater_clicked()
=======
void MainWindow::on_rb_asc_clicked()
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
{
    // Ваш код.
}

void MainWindow::on_rb_desc_clicked()
{
    // Ваш код.
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void MainWindow::on_cb_case_clicked()
{
    // Ваш код.
<<<<<<< HEAD
    on_le_unsorted_textChanged("");
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void MainWindow::on_le_unsorted_textChanged(const QString&)
{
    // Ваш код.
<<<<<<< HEAD
<<<<<<< HEAD
    auto text = ui->le_unsorted->text().trimmed();
    auto text_vec = text.split(' ');
    bool cas = !ui->cb_case->checkState();
    bool abss = ui->rb_asc->isChecked();

    auto comp = [&](const QString& lhs, const QString& rhs){
        if (cas) {
            if (abss) {
                return QString::compare(lhs, rhs, Qt::CaseInsensitive) < 0;
            } else {
                return QString::compare(lhs, rhs, Qt::CaseInsensitive) > 0;
            }

        } else {
            if (abss) {
                return lhs < rhs;
            } else {
                return lhs > rhs;
            }

        }
        return true;
    };

    for (auto el : text_vec) {
        el = el.trimmed();
    }

    std::sort(text_vec.begin(), text_vec.end(),  comp);

    QString res_text ="";
    bool first = true;
    for (auto el : text_vec) {
        if (el == " " || el.isEmpty()) continue;
        if(!first) {
            res_text+=" ";
        }
        first = false;
        res_text+=el;
    }

    ui->le_sorted->setText(res_text);
}
=======
}
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
}
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
