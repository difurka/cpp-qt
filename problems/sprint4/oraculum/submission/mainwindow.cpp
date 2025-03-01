#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <format>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Reset();
    qDebug() << a_ << "; " << b_ << "\n";
    ShowQuestion();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Reset() {
    // Инициализация интервала.
    a_ = 0;
    b_ = 101;
    m_ = (a_+b_)/2;
}

void MainWindow::ShowQuestion() {
    // Показываем вопрос, используя ui->lbl_question->setText.
    // Если b_ - a_ <= 1, то мы угадали. Нужно показать не вопрос,
    // а ответ.
    if (b_ - a_ <= 1) {
        ui->lbl_question->setText(QString::fromStdString(std::format("Ваше число {}!", a_)));
    } else {
        ui->lbl_question->setText(QString::fromStdString(std::format("Ваше число меньше {}?", m_)));
    }

}

void MainWindow::on_btn_yes_clicked() {
    // Ответ "Да".
    // Делаем шаг алгоритма и обновляем вопрос.
    b_ = m_;
    m_ = (b_+a_)/2;
    qDebug() << a_ << "; " <<m_ << "; "  << b_ << "\n";
    ShowQuestion();
}

void MainWindow::on_btn_no_clicked() {
    // Ответ "Нет".
    // Делаем шаг алгоритма и обновляем вопрос.
    qDebug() <<"no" << a_ << "; " <<m_ << "; "  << b_ << "\n";
    a_ = m_;
     qDebug() <<"no" << a_ << "; " <<m_ << "; "  << b_ << "\n";
    m_ = (b_+a_)/2;
    qDebug() << a_ << "; " <<m_ << "; "  << b_ << "\n";
    ShowQuestion();
}
