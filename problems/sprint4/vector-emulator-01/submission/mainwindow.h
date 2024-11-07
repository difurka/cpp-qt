#pragma once

#include <QMainWindow>
#include <QStringListModel>
#include <QListWidgetItem>

#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

<<<<<<< HEAD
    void on_pb_pop_clicked();

    void on_pb_push_clicked();

    void on_pb_clear_clicked();

    void on_pb_days_clicked();

    void on_p_month_clicked();

=======
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
private:
    void ApplyModel();

private:
    Model vector_model_;
    Ui::MainWindow *ui;
};
