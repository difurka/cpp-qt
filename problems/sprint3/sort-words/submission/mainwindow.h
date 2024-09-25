#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <functional>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

<<<<<<< HEAD
    void on_rb_desc_clicked();

    void on_rb_asc_clicked();
=======
    void on_rb_greater_clicked();

    void on_rb_less_clicked();
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

    void on_cb_case_clicked();

    void on_le_unsorted_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
