#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class Operation {
    NO_OPERATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_0_clicked();
    void on_pb_1_clicked();
    void on_pb_2_clicked();
    void on_pb_3_clicked();
    void on_pb_4_clicked();
    void on_pb_5_clicked();
    void on_pb_6_clicked();
    void on_pb_7_clicked();
    void on_pb_8_clicked();
    void on_pb_9_clicked();
    void on_pb_dot_clicked();
    void on_pb_delete_clicked();
    void on_pb_c_clicked();
    void on_pb_plus_minus_clicked();
    void on_pb_plus_clicked();
    void on_pb_minus_clicked();
    void on_pb_mul_clicked();
    void on_pb_div_clicked();
    void on_pb_pow_clicked();
    void on_pb_equal_clicked();
    void on_pb_ms_clicked();
    void on_pb_mr_clicked();
    void on_pb_mc_clicked();

private:
    Ui::MainWindow* ui;
    Operation current_operation_ = Operation::NO_OPERATION;
    QString input_number_{"0"};
    Calculator calculator_;
    Number active_number_{0};
    Number memory_cell_{0};
    bool memory_saved_{false};
    void AddResultNumber(int number);
    void AddFormulaSymbol(const QString& operation, Operation type);
};
