<<<<<<< HEAD
#pragma once

#include <QMainWindow>
#include <QStringListModel>
#include <QListWidgetItem>

#include <random>

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
    void SetRandomGen(const std::mt19937 &random_gen);

private slots:

    void on_pb_pop_clicked();

    void on_pb_push_clicked();

    void on_pb_clear_clicked();

    void on_pb_days_clicked();

    void on_p_month_clicked();

    void on_pb_pp_clicked();

    void on_pb_mm_clicked();

    void on_pb_begin_clicked();

    void on_pb_end_clicked();

    void on_pb_edit_clicked();

    void on_pb_insert_clicked();

    void on_pb_erase_clicked();

    void on_list_widget_currentRowChanged(int currentRow);

    void on_btn_resize_clicked();

    void on_btn_reserve_clicked();

    void on_pb_count_clicked();

    void on_pb_find_clicked();

    void on_pb_min_clicked();

    void on_pb_max_clicked();

    void on_pb_sort_clicked();

    void on_pb_sOrT_clicked();

    void on_pb_reverse_clicked();

    void on_pb_unique_clicked();

    void on_pb_shuffle_clicked();

private:
    void ApplyModel();

private:
    Model vector_model_;
    std::mt19937 random_gen_;
    Ui::MainWindow *ui;
    void ApplyIterator();

};
=======
// Используйте предыдущую реализацию.
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
