#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
<<<<<<< HEAD
=======

>>>>>>> 8abeace (Обновление репы из коммита 0829cb69b09bff8968664b9181a8531fdb0170f5 (#13))
    friend class TestMainWindow;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_convert_to_miles_clicked();
    void on_btn_convert_to_km_clicked();

public:
    double ConvertToMiles(double);
    double ConvertToKm(double);

private:
    double coef = 0.621371;
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
