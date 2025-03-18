#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <darkeners.h>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) {
        return QWidget::keyPressEvent(event);
    }
    switch (event->key()) {
    case Qt::Key_Right:
        controller_.OnMoveKey(Direction::kRight);
        break;
    case Qt::Key_Left:
        controller_.OnMoveKey(Direction::kLeft);
        break;
    case Qt::Key_Up:
        controller_.OnMoveKey(Direction::kUp);
        break;
    case Qt::Key_Down:
        controller_.OnMoveKey(Direction::kDown);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}



/*Перерисовывать игру нужно в событии paintEvent класса MainWindow. Внутри этого метода создайте:
рисователь QPainter,
графический движок Painter,
контекст рисования DrawContext.
Графический движок — достаточно лёгкий объект, его можно создавать каждый раз при рисовании.
 Инициализируйте графический движок методом PreparePaint с нужными аргументами.
В конце вызовите метод DrawFrame класса Game. Он изобразит весь игровой мир.*/

void MainWindow::paintEvent(QPaintEvent*) {
    // Создадим рисователь и графический движок.
    QPainter q_painter{this}; //рисователь
    Painter painter(q_painter); //графический движок


    //Инициализировать графический движок
    Size window_size{width(), height()};
    CoordinateF player_pos = game_.GetPlayer().GetPosition();
    auto field_size = game_.GetField().GetRect();

    painter.PreparePaint(player_pos, field_size, window_size);

    //FlashlightDarkener(CoordinateF start_point, int radius, Direction dir, int distance)
    /*В paintEvent создайте объект типа FlashlightDarkener и сохраните его в контекст рисования. В конструктор этого объекта передайте такие объекты:
    позиция игрока,
    радиус фонарика (число 7),
    направление взгляда игрока,
    длина фонарика (число 4).*/
    FlashlightDarkener fl_darkener{game_.GetPlayer().GetPosition(), 7, game_.GetPlayer().GetDirection(), 4};

    DrawContext draw_context{.painter=painter, .darkener=fl_darkener}; //контекст рисования

    game_.DrawFrame(draw_context);

}

