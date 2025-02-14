#pragma once

#include "enums.h"
#include <QMainWindow>
#include <functional>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void SetInputText(const std::string& text);
    void SetFormulaText(const std::string& text);
    void SetErrorText(const std::string& text);
    void SetMemText(const std::string& text);
    void SetExtraKey(const std::optional<std::string>& key);

    void SetDigitKeyCallback(std::function<void(int key)> cb);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);

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

    void on_cmb_controller_currentIndexChanged(int index);

    void on_tb_extra_clicked();

 private:
    Ui::MainWindow* ui;

    std::function<void(int key)> cb_digital_key_;
    std::function<void(Operation key)> cb_operation_key_;
    std::function<void(ControlKey key)> cb_control_key_;
    std::function<void(ControllerType controller)> cb_type_numbers_;
};
