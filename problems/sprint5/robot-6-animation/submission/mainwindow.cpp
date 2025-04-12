#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Game& game, Controller& controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game_(game)
    , controller_(controller)
{
    ui->setupUi(this);

    controller_.SetRedrawCallback([this, last_draw = std::optional<std::chrono::steady_clock::time_point>{}]() mutable {
        repaint();
    });
    // timer_.setInterval(40);

    // Подключаем таймер к методу Tick контроллера
    // connect(&timer_, SIGNAL( timeout() ), SLOT( on_timer_timeout() )); // &prac::QTimer::timeout, this, &MainWindow::on_timer_timeout);
    connect(&timer_,  &prac::QTimer::timeout, this, &MainWindow::on_timer_timeout);
    // Устанавливаем интервал таймера на 20 миллисекунд и запускаем его
    timer_.start(40);

}

void MainWindow::on_timer_timeout() {
    controller_.Tick();
}

MainWindow::~MainWindow()
{
    delete ui;
}
