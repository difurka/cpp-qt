#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include <QIntValidator>

int DaysPerMonth(int month, int year)
{
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29; // February in a leap year.
        } else {
            return 28; // February in a non-leap year.
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30; // April, June, September, November have 30 days.
    } else {
        return 31; // All other months have 31 days.
    }
}

int CalculateDaysFromStartYear(int day, int month, int year)
{
    if(month == 0) {
        return 0;
    }
    int num_days = 0;
    for(size_t num_month = 1; num_month < static_cast<size_t>(month); ++num_month) {
        num_days += DaysPerMonth(num_month, year);
    }
    num_days += day;
    return num_days;
}

QString MainWindow::GetFormatType1(int day, int month, int year)
{
    // Реализуйте метод форматирования даты.
}

QString MainWindow::GetFormatType2(int day, int month, int year)
{
    // Реализуйте метод форматирования даты.
}

QString MainWindow::GetFormatType3(int day, int month, int year)
{
    // Реализуйте метод форматирования даты.
}

QString MainWindow::GetStrNumDays(int num_days, int year) {
    // Метод должен возвращать текст о номере дня в году.
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установите валидаторы.
    ui->le_day->setValidator(new QIntValidator(1, 31, this));
    ui->le_month->setValidator(new QIntValidator(1, 12, this));
    ui->le_year->setValidator(new QIntValidator(1, 9999, this));

    SetError("Некорректная дата");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowFormattedDate()
{
    if(!ui->le_day->hasAcceptableInput() ||
        !ui->le_month->hasAcceptableInput() ||
        !ui->le_year->hasAcceptableInput() ) {
        SetError("Некорректная дата");

        return;
    }

    // Отобразим результаты.
    // Используйте DaysPerMonth для определения количества дней в месяце.
    // Используйте CalculateDaysFromStartYear для определения номера дня в году.

    // Используйте GetFormatType1, GetFormatType2, GetFormatType3 и GetStrNumDays
    // для определения надписей, которые нужно вывести пользователю.
    // Эти методы реализуйте самостоятельно.
}

void MainWindow::SetError(const QString& err_text)
{
    ui->lbl_format_type1->clear();
    ui->lbl_format_type2->clear();
    ui->lbl_format_type3->clear();
    ui->lbl_message->setText(err_text);
}

void MainWindow::on_le_date_textChanged(const QString&)
{
    if(editing_now_) return;

    editing_now_=true;
    // Пользователь изменил дату. Реализуйте слот.
    // Такой split разбивает строку по точкам.
    // Он возвращает значение типа QStringList,
    // похожее на std::vector<QString>.
    auto arr = ui->le_date->text().split(".");
    if(arr.size() == 3) {
        ui->le_day->setText(arr[0]);
        ui->le_month->setText(arr[1]);
        ui->le_year->setText(arr[2]);
    }

    ShowFormattedDate();
    editing_now_=false;


}

void MainWindow::on_le_day_textChanged(const QString&)
{
    // Пользователь изменил день. Реализуйте слот.
    if(editing_now_) return;
    editing_now_=true;

    QString result = "%1.%2.%3";
    QString formatted = result
                            .arg(ui->le_day->text().toStdString(), 2, 10, QChar('0'))
                            .arg(ui->le_month->text().toStdString(), 2, 10, QChar('0'))
                            .arg(ui->le_year->text());

    ui->le_date->setText(formatted);
    ShowFormattedDate();
    editing_now_=false;
}

void MainWindow::on_le_month_textChanged(const QString&)
{
    // Пользователь изменил месяц. Реализуйте слот.
    if(editing_now_) return;
    editing_now_=true;
    QString result = "%1.%2.%3";
    QString formatted = result
                            .arg(ui->le_day->text().toStdString(), 2, 10, QChar('0'))
                            .arg(ui->le_month->text().toStdString(), 2, 10, QChar('0'))
                            .arg(ui->le_year->text());
    ui->le_date->setText(formatted);
    ShowFormattedDate();
    editing_now_=false;
}

void MainWindow::on_le_year_textChanged(const QString&)
{
    // Пользователь изменил год. Реализуйте слот.
    if(editing_now_) return;
    editing_now_=true;
    QString result = "%1.%2.%3";
    QString formatted = result
                            .arg(ui->le_day->text(), 2, 10, QChar('0'))
                            .arg(ui->le_month->text(), 2, 10, QChar('0'))
                            .arg(ui->le_year->text());
    ui->le_date->setText(formatted);
    ShowFormattedDate();
    editing_now_=false;
}
