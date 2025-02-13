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

void MainWindow::on_rb_asc_clicked()
{
    // Ваш код.
    on_le_unsorted_textChanged("");
}

void MainWindow::on_rb_desc_clicked()
{
    // Ваш код.
    on_le_unsorted_textChanged("");
}

void MainWindow::on_cb_case_clicked()
{
    // Ваш код.
    on_le_unsorted_textChanged("");
}

void MainWindow::on_le_unsorted_textChanged(const QString&)
{
    // Ваш код.
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
