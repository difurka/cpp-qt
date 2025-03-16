<<<<<<< HEAD
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

    void paintEvent(QPaintEvent*) override {

        // Создадим рисователь и графический движок.
        QPainter q_painter{this};
        // Painter painter{q_painter};
        // DrawContext draw_context{painter};

        // Size window_size{width(), height()};

        // // Поле размером 2 на 2, персонаж в клетке с координатами 0, 0.
        // Coordinate player_pos{0,0};
        // Size field_size{2,2};

        // // Настроим рисование.
        // painter.PreparePaint(player_pos, field_size, window_size);

        // // Загрузим ассеты.
        // AssetLoader loader;
        // Asset wall1_tile = loader.LoadTile("walls", "wall-white");
        // Asset wall2_tile = loader.LoadTile("walls", "wall-black");
        // Asset floor_tile = loader.LoadTile("floors", "grass");
        // AssetInDirections robot_sprite = loader.LoadWithDirection("characters", "robot");

        // // Нарисуем пол.
        // painter.DrawFloor(floor_tile, {0,0});
        // painter.DrawFloor(floor_tile, {0,1});
        // painter.DrawFloor(floor_tile, {1,0});

        // // Нарисуем стены.
        // painter.DrawWall(wall1_tile, {0,0}, Orientation::kHorizontal);
        // painter.DrawWall(wall1_tile, {1,0}, Orientation::kHorizontal);
        // painter.DrawWall(wall2_tile, {0,0}, Orientation::kVertical);

        // // Нарисуем робота.
        // painter.DrawObject(robot_sprite.Get(Direction::kRight), {0,0}, Orientation::kVertical);

        QPainter qpainter{};
        Painter painter{qpainter};
        DrawContext draw_context{painter};
        FlashlightDarkener darkener;
        Floor floor{5, 12, 17};
        floor.DrawFloor(draw_context);
    }

private:
    Ui::MainWindow *ui;
    Game& game_;
    Controller& controller_;
};
#endif // MAINWINDOW_H
=======
#pragma once
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
