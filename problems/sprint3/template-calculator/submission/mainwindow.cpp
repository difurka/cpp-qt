// Реальзуйте класс главного окна.

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");

    const QStringList num_types = {"double",
                                          "float",
                                          "uint8_t",
                                          "int",
                                          "int64_t",
                                          "size_t",
                                          "Rational"};
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
        ui->tb_extra->setEnabled(true);
    } else {
        ui->tb_extra->setDisabled(true);
    }
}


void MainWindow::on_pb_dot_clicked()
{
    if (input_number_.contains(".")) {
        return;
    }
    input_number_ += ".";
    ui->l_result->setText(input_number_);
}

void MainWindow::AddResultNumber(int number) {
    if (input_number_ == "0") {
        input_number_ = QString::number(number);
    } else {
        input_number_ += QString::number(number);
    }
}

void MainWindow::on_pb_1_clicked()
{
    AddResultNumber(1);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_0_clicked() {
    AddResultNumber(0);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_2_clicked() {
    AddResultNumber(2);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_3_clicked() {
    AddResultNumber(3);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_4_clicked() {
    AddResultNumber(4);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_5_clicked() {
    AddResultNumber(5);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_6_clicked() {
    AddResultNumber(6);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_7_clicked() {
    AddResultNumber(7);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_8_clicked() {
    AddResultNumber(8);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_9_clicked() {
    AddResultNumber(9);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}



void MainWindow::on_pb_delete_clicked() {
    if (input_number_.isEmpty())
        return;
    input_number_.chop(1);
    if (input_number_.isEmpty() || input_number_ == "-") {
        input_number_ = "0";
    }
    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_c_clicked()
{
    input_number_ = "0";
    active_number_ = 0;
    calculator_.Set(0);
    ui->l_result->setText(input_number_);
    ui->l_formula->setText("");
    current_operation_ = Operation::NO_OPERATION;
}


void MainWindow::on_pb_plus_minus_clicked()
{
    active_number_*=-1;
    input_number_ = QString::number(active_number_);
    ui->l_result->setText(input_number_);
}

void MainWindow::AddFormulaSymbol(QString operation, Operation operation_type) {
    // auto formula = ui->l_formula->text();
    ui->l_formula->setText(QString::number(active_number_));
    if (current_operation_ == Operation::NO_OPERATION) {
        calculator_.Set(active_number_);
        // formula = input_number_;
    }
    // ui->l_formula->setText(input_number_);

    current_operation_ = operation_type;
    QString formula_new = QString::number(active_number_) + " " + operation + " ";//"%1 %2 ".arg(formula).arg(operation);
    ui->l_formula->setText(formula_new);
    input_number_ = "";
}

void MainWindow::on_pb_plus_clicked()
{
    AddFormulaSymbol("+", Operation::ADDITION);
}

void MainWindow::on_pb_minus_clicked()
{
    AddFormulaSymbol("−", Operation::SUBTRACTION);
}


void MainWindow::on_pb_mul_clicked()
{
    AddFormulaSymbol("×", Operation::MULTIPLICATION);
}


void MainWindow::on_pb_div_clicked()
{
    AddFormulaSymbol("÷", Operation::DIVISION);
}


void MainWindow::on_pb_pow_clicked()
{
    AddFormulaSymbol("^", Operation::POWER);
}


void MainWindow::on_pb_equal_clicked() {
    switch (current_operation_) {
    case Operation::ADDITION:
        calculator_.Add(active_number_);
        break;
    case Operation::SUBTRACTION:
        calculator_.Sub(active_number_);
        break;
    case Operation::MULTIPLICATION:
        calculator_.Mul(active_number_);
        break;
    case Operation::DIVISION:
        calculator_.Div(active_number_);
        break;
    case Operation::POWER:
        calculator_.Pow(active_number_);
        break;
    case Operation::NO_OPERATION:
        break;
    }
    QString formula = ui->l_formula->text() + input_number_ +" " + "=";
    ui->l_formula->setText(formula);
    active_number_ = calculator_.GetNumber();
    input_number_ = QString::number(active_number_);
    ui->l_result->setText(input_number_);
    input_number_ = "";

}


void MainWindow::on_pb_ms_clicked() {
    memory_cell_ = active_number_;
    memory_saved_ = true;
    ui->l_memory->setText("M");
    current_operation_ = Operation::NO_OPERATION;
}

void MainWindow::on_pb_mr_clicked() {
    if (memory_saved_) {
        active_number_ = memory_cell_;
        input_number_ = QString::number(active_number_);
        ui->l_result->setText(input_number_);
    }
}

void MainWindow::on_pb_mc_clicked() {
    memory_saved_ = false;
    ui->l_memory->setText("");
}


