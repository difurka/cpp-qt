#pragma once

#include <QMainWindow>
#include <functional>
#include "setting.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotShowAction(int num, QString action_name, std::function<void()> action);
private slots:

    void on_pb_sett_1_clicked();

    void on_pb_sett_2_clicked();

    void on_pb_sett_3_clicked();

    void on_pb_sett_4_clicked();

<<<<<<< HEAD

    void on_pb_button_1_clicked();
    void on_pb_button_2_clicked();
    void on_pb_button_3_clicked();
    void on_pb_button_4_clicked();

=======
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
private:
    Ui::MainWindow *ui;
    Setting* setting_ = new Setting();
    std::vector<QPushButton*> buttons_;
<<<<<<< HEAD
    std::vector<std::function<void()>> actions_;
=======
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
};
