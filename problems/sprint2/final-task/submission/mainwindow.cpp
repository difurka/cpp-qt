#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pb_dot_clicked() {
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
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_1_clicked() {
    AddResultNumber(1);
}

void MainWindow::on_pb_0_clicked() {
    AddResultNumber(0);
}

void MainWindow::on_pb_2_clicked() {
    AddResultNumber(2);
}

void MainWindow::on_pb_3_clicked() {
    AddResultNumber(3);
}

void MainWindow::on_pb_4_clicked() {
    AddResultNumber(4);
}

void MainWindow::on_pb_5_clicked() {
    AddResultNumber(5);
}

void MainWindow::on_pb_6_clicked() {
    AddResultNumber(6);
}

void MainWindow::on_pb_7_clicked() {
    AddResultNumber(7);
}

void MainWindow::on_pb_8_clicked() {
    AddResultNumber(8);
}

void MainWindow::on_pb_9_clicked() {
    AddResultNumber(9);
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

void MainWindow::on_pb_c_clicked() {
    input_number_ = "0";
    active_number_ = 0;
    calculator_.Set(0);
    ui->l_result->setText(input_number_);
    ui->l_formula->setText("");
    current_operation_ = Operation::NO_OPERATION;
}

void MainWindow::on_pb_plus_minus_clicked() {
    active_number_*=-1;
    input_number_ = QString::number(active_number_);
    ui->l_result->setText(input_number_);
}

void MainWindow::AddFormulaSymbol(const QString& operation, Operation operation_type) {
    ui->l_formula->setText(QString::number(active_number_));
    if (current_operation_ == Operation::NO_OPERATION) {
        calculator_.Set(active_number_);
    }
    current_operation_ = operation_type;
    QString formula_new = QString::number(active_number_) + " " + operation + " ";
    ui->l_formula->setText(formula_new);
    input_number_ = "";
}

void MainWindow::on_pb_plus_clicked() {
    AddFormulaSymbol("+", Operation::ADDITION);
}

void MainWindow::on_pb_minus_clicked() {
    AddFormulaSymbol("−", Operation::SUBTRACTION);
}

void MainWindow::on_pb_mul_clicked() {
    AddFormulaSymbol("×", Operation::MULTIPLICATION);
}

void MainWindow::on_pb_div_clicked() {
    AddFormulaSymbol("÷", Operation::DIVISION);
}

void MainWindow::on_pb_pow_clicked() {
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
