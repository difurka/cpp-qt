#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include "controller.h"
#include "utility/painter.h"

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Game& game, Controller& controller, QWidget *parent = nullptr);
    ~MainWindow();

public:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->isAutoRepeat()) {
            return QWidget::keyPressEvent(event);
        }
        switch (event->key()) {
        case Qt::Key_Right :
            controller_.OnMoveKey(Direction::kRight); break;
        case Qt::Key_Left:
            controller_.OnMoveKey(Direction::kLeft); break;
        case Qt::Key_Up :
            controller_.OnMoveKey(Direction::kUp); break;
        case Qt::Key_Down :
            controller_.OnMoveKey(Direction::kDown); break;
        default:
            QWidget::keyPressEvent(event);
        }
    }

public:
    void paintEvent(QPaintEvent*) override {
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
        FlashlightDarkener fl_darkener{player_pos, 7, game_.GetPlayer().GetDirection(), 4};

        /*    struct DarkenerParams {
        CoordinateF start_point;
        int radius;
        Direction direction;
        int distance;
    };*/
        /*static const FlashlightDarkener::DarkenerParams& d_params = fl_darkener.getLastDarkenerParams();
    qInfo() << "DarkenerParams\nstart_point:" <<  QString::fromStdString(ToString(d_params.start_point))
            << "radius:" <<QString::number(d_params.radius)
            << "dir:" <<QString::number(d_params.direction)
            << "distance:" <<QString::number(d_params.distance);*/

        DrawContext draw_context{.painter=painter, .darkener=fl_darkener}; //контекст рисования



        game_.DrawFrame(draw_context);
        // QPainter q_painter{this}; //рисователь
        // Painter painter(q_painter); //графический движок
        // //Инициализировать графический движок
        // Size window_size{width(), height()};
        // CoordinateF player_pos = game_.GetPlayer().GetPosition();
        // auto field_size = game_.GetField().GetRect();
        // painter.PreparePaint(player_pos, field_size, window_size);
        // FlashlightDarkener fl_darkener{player_pos, 7, game_.GetPlayer().GetDirection(), 4};
        // DrawContext draw_context{.painter=painter, .darkener=fl_darkener}; //контекст рисования
        // game_.DrawFrame(draw_context);
    }

private:
    Ui::MainWindow *ui;
    Game& game_;
    Controller& controller_;
};
#endif // MAINWINDOW_H
