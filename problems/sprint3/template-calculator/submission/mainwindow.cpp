#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");

    const QStringList num_types = {
                                  "double",
                                  "float",
                                  "uint8_t",
                                  "int",
                                  "int64_t",
                                  "size_t",
                                  "Rational"
                                };
    ui->cmb_controller->addItems(num_types);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetInputText(const std::string& text) {
    ui->l_result->setStyleSheet("");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string& text) {
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string& text) {
    ui->l_result->setStyleSheet("color: red");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text) {
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key) {
    if (key.has_value()) {
        ui->tb_extra->setText(QString::fromStdString(key.value()));
        ui->tb_extra->setVisible(true);
    } else {
        ui->tb_extra->setVisible(false);
    }
}

void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb) {
    if(cb) {
        cb_digital_key_ = cb;
    }
}

void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb) {
    if(cb) {
        cb_operation_key_ = cb;
    }
}

void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb) {
    if(cb){
        cb_control_key_ = cb;
    }
}

void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb) {
    if(cb) {
        cb_type_numbers_ = cb;
    }
}

void MainWindow::on_pb_1_clicked() {
    cb_digital_key_(1);
}

void MainWindow::on_pb_0_clicked() {
    cb_digital_key_(0);
}

void MainWindow::on_pb_2_clicked() {
    cb_digital_key_(2);
}

void MainWindow::on_pb_3_clicked() {
    cb_digital_key_(3);
}

void MainWindow::on_pb_4_clicked() {
    cb_digital_key_(4);
}

void MainWindow::on_pb_5_clicked() {
    cb_digital_key_(5);
}

void MainWindow::on_pb_6_clicked() {
    cb_digital_key_(6);
}

void MainWindow::on_pb_7_clicked() {
    cb_digital_key_(7);
}

void MainWindow::on_pb_8_clicked() {
    cb_digital_key_(8);
}

void MainWindow::on_pb_9_clicked() {
    cb_digital_key_(9);
}

void MainWindow::on_pb_delete_clicked() {
    cb_control_key_(ControlKey::BACKSPACE);
}

void MainWindow::on_pb_c_clicked()
{
    cb_control_key_(ControlKey::CLEAR);
}

void MainWindow::on_pb_plus_minus_clicked()
{
    cb_control_key_(ControlKey::PLUS_MINUS);
}

void MainWindow::on_pb_plus_clicked()
{
    cb_operation_key_(Operation::ADDITION);
}

void MainWindow::on_pb_minus_clicked()
{
    cb_operation_key_(Operation::SUBTRACTION);
}

void MainWindow::on_pb_mul_clicked()
{
    cb_operation_key_(Operation::MULTIPLICATION);
}

void MainWindow::on_pb_div_clicked()
{
    cb_operation_key_(Operation::DIVISION);
}

void MainWindow::on_pb_pow_clicked()
{
    cb_operation_key_(Operation::POWER);
}

void MainWindow::on_pb_equal_clicked() {
    cb_control_key_(ControlKey::EQUALS);
}

void MainWindow::on_pb_ms_clicked() {
    cb_control_key_(ControlKey::MEM_SAVE);
}

void MainWindow::on_pb_mr_clicked() {
    cb_control_key_(ControlKey::MEM_LOAD);
}

void MainWindow::on_pb_mc_clicked() {
    cb_control_key_(ControlKey::MEM_CLEAR);
}

void MainWindow::on_cmb_controller_currentIndexChanged(int) {
    auto type_name = ui->cmb_controller->currentText();
    ControllerType type_controller = ControllerType::DOUBLE;
    if (type_name == "float") {
        type_controller = ControllerType::FLOAT;
    } else if (type_name == "uint8_t") {
            type_controller = ControllerType::UINT8_T;
    } else if (type_name == "int") {
        type_controller = ControllerType::INT;
    } else if (type_name == "int64_t") {
        type_controller = ControllerType::INT64_T;
    } else if (type_name == "size_t") {
        type_controller = ControllerType::SIZE_T;
    } else if (type_name == "Rational") {
        type_controller = ControllerType::RATIONAL;
    }
    if(cb_type_numbers_) {
        cb_type_numbers_(type_controller);
    }
}

void MainWindow::on_tb_extra_clicked()
{
    cb_control_key_(ControlKey::EXTRA_KEY);
}
