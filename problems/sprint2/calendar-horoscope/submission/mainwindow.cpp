#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include "magic_horoscope.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    ui->le_year->setValidator(new QIntValidator(1, 9999, this));
    static const QStringList months = {
        "январь", "февраль", "март", "апрель", "май", "июнь",
        "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"};
    ui->cb_month->addItems(months);
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD

void MainWindow::on_rb_eastern_clicked()
{
    calendar_ = Calendar::kEastern;
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_calendar->setText("Введите год");
        return;
    }
    MakeMagic();
}

QString MainWindow::ShowHoroscope() {
    QString formatted ="Ввод даты отключён";
    QString result;
    if (!ui->cb_is_date) {
        return formatted;
    } else {
        if (horoscope_==Horoscope::kZodiac) {
            result = GetZodiac(ui->sb_day->value(), ui->cb_month->currentIndex(), year_);
            if (result.isEmpty()) return "Такой даты не существует";
            QString text = "%1.%2 — ваш знак зодиака %3 по зодиакальному гороскопу";
            formatted = text
                            .arg(ui->sb_day->value(), 2, 10, QChar('0'))
                            .arg(ui->cb_month->currentIndex() +1, 2, 10, QChar('0'))
                            .arg(result);
        } else {
            result  = GetTree(ui->sb_day->value(), ui->cb_month->currentIndex(), year_);
            if (result.isEmpty()) return "Такой даты не существует";
            QString text = "%1.%2 — ваше тотемное дерево %3 по гороскопу друидов";
            formatted = text
                            .arg(ui->sb_day->value(), 2, 10, QChar('0'))
                            .arg(ui->cb_month->currentIndex() +1, 2, 10, QChar('0'))
                            .arg(result);
        }
    }
    return formatted;
}

void MainWindow::MakeMagic() {
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_calendar->setText("Введите год");
        return;
    }

    ui->lbl_calendar->setText(ShowCalendar());
    if (!ui->cb_is_date->isChecked()) {
        ui->lbl_horoscope->setText("Ввод даты отключён");
        return;
    }
    ui->lbl_horoscope->setText(ShowHoroscope());
}

QString MainWindow::ShowCalendar() {
    QString formatted;
    if (calendar_ == Calendar::kEastern){
        auto animal = GetAnimalForEasternCalendar(year_);
        auto element = GetElementForEasternCalendar(year_);
        QString text = "%1 — это год %2. Стихия/цвет — %3";
        formatted = text
                                .arg(year_)
                                .arg(animal)
                                .arg(element);
    } else if (calendar_== Calendar::kTibetan) {
        auto animal = GetAnimalForTibetanCalendar(year_);
        QString text = "%1 — это год %2";
        formatted = text
                        .arg(year_)
                        .arg(animal);
    } else if (calendar_== Calendar::kZoroastrian) {
        auto animal = GetAnimalForZoroastrianCalendar(year_);
        QString text = "%1 — это год %2";
        formatted = text
                        .arg(year_)
                        .arg(animal);
    }

    return formatted;
}



void MainWindow::on_le_year_textChanged(const QString &)
{
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_calendar->setText("Введите год");
        return;
    }
    year_ = ui->le_year->text().toInt();
    if (ui->rb_eastern->isChecked()) {
        calendar_ = Calendar::kEastern;
    } else if (ui->rb_tibetan->isChecked()) {
        calendar_ = Calendar::kTibetan;
    } else {
        calendar_=Calendar::kZoroastrian;
    }
    MakeMagic();
}


void MainWindow::on_rb_tibetan_clicked()
{
    calendar_ = Calendar::kTibetan;
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_calendar->setText("Введите год");
        return;
    }
    MakeMagic();
}


void MainWindow::on_rb_zoroastrian_clicked()
{
    calendar_ = Calendar::kZoroastrian;
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_calendar->setText("Введите год");
        return;
    }
    MakeMagic();
}


void MainWindow::on_cb_is_date_clicked(bool checked)
{
    ui->gb_horoscope->setEnabled(checked);
    ui->lbl_day->setEnabled(checked);
    ui->lbl_month->setEnabled(checked);
    ui->cb_month->setEnabled(checked);
    ui->sb_day->setEnabled(checked);
    if (ui->rb_zodiac->isChecked()) {
        horoscope_ = Horoscope::kZodiac;
    } else if (ui->rb_druid->isChecked()) {
        horoscope_ = Horoscope::kDruid;
    }
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_horoscope->setText("Введите год");
        if (!checked) {
            ui->lbl_horoscope->setText("Ввод даты отключён");
        }
        return;
    }

    if (!checked) {
        ui->lbl_horoscope->setText("Ввод даты отключён");
        return;
    }

    MakeMagic();
}


void MainWindow::on_rb_zodiac_clicked()
{
    horoscope_ = Horoscope::kZodiac;
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_horoscope->setText("Введите год");
        return;
    }

    if (!ui->cb_is_date->isChecked()) {
        ui->lbl_horoscope->setText("Ввод даты отключён");
        return;
    }
    MakeMagic();
}


void MainWindow::on_rb_druid_clicked()
{
    horoscope_ = Horoscope::kDruid;
    if (!ui->le_year->hasAcceptableInput()) {
        ui->lbl_horoscope->setText("Введите год");
        return;
    }

    if (!ui->cb_is_date->isChecked()) {
        ui->lbl_horoscope->setText("Ввод даты отключён");
        return;
    }
    MakeMagic();
}


void MainWindow::on_sb_day_valueChanged(int)
{
    MakeMagic();
}


void MainWindow::on_cb_month_currentIndexChanged(int)
{
    MakeMagic();
}

=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
