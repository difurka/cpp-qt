#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
<<<<<<< HEAD
    qInfo() << "Приложение запущено";
=======
>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
}

MainWindow::~MainWindow() {
    delete ui;
}

double MainWindow::ConvertToMiles(double km) {
<<<<<<< HEAD
    qDebug() << "Вызвана функция ConvertToMiles, km =" << km;
=======
>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
    return km * coef;
}

double MainWindow::ConvertToKm(double miles) {
<<<<<<< HEAD
    qDebug() << "Вызвана функция ConvertToKm, miles =" << miles;
=======
>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
    return miles / coef;
}

void MainWindow::on_btn_convert_to_miles_clicked() {
<<<<<<< HEAD
    qInfo() << "Нажата кнопка для конвертирования в мили";
=======
>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
    bool ok;
    auto input_text = ui->txt_km_input->text();
    double km = input_text.toDouble(&ok);

    if (ok) {
        double miles = ConvertToMiles(km);
<<<<<<< HEAD
        qDebug() << "Преобразование выполнено:" << km << "км ="<< miles << "миль";
        ui->result_label_miles->setText(" = " + QString::number(miles) + " miles");
    } else {
        ui->result_label_miles->setText("Invalid input for km");
        qDebug() << "Не удалось преобразовать ввод в число:" << input_text;
=======
        ui->result_label_miles->setText("  = " + QString::number(miles) + " miles");
    } else {
        ui->result_label_miles->setText("Invalid input for km");
>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
    }
}

void MainWindow::on_btn_convert_to_km_clicked() {
<<<<<<< HEAD
    qInfo() << "Нажата кнопка для конвертирования в километры";
=======
>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
    bool ok;
    auto input_text = ui->txt_miles_input->text();
    double miles = input_text.toDouble(&ok);

    if (ok) {
        double km = ConvertToKm(miles);
<<<<<<< HEAD
        qDebug() << "Преобразование выполнено:" << miles << "миль ="<< km << "км";
        ui->result_label_km->setText(" = " + QString::number(km) + " km");
    } else {
        ui->result_label_km->setText("Invalid input for miles");
        qDebug() << "Не удалось преобразовать ввод в число:" << input_text;
=======
        ui->result_label_km->setText("  = " + QString::number(km) + " km");
    } else {
        ui->result_label_km->setText("Invalid input for miles");
>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
    }
}
