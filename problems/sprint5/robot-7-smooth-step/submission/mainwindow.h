#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include "controller.h"
#include "utility/painter.h"
#include <prac/QTimer>

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

protected:
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
        FlashlightDarkener fl_darkener{player_pos, 7, game_.GetPlayer().GetDirection(), 4};
        DrawContext draw_context{.painter=painter, .darkener=fl_darkener}; //контекст рисования
        game_.DrawFrame(draw_context);
    }

private:
    Ui::MainWindow *ui;
    Game& game_;
    Controller& controller_;
    prac::QTimer timer_;
    void on_timer_timeout();
};
#endif // MAINWINDOW_H
