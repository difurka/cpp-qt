#pragma once

#include "utility/geometry.h"
#include "game.h"

class Controller {
public:
    Controller(Game& game) : game_{game} {}

    void OnMoveKey(Direction dir) {
        // Напишите реализацию метода.
        qInfo() << "<<< Moving in direction <направление>";
        Player robot = game_.GetPlayer();
        if (dir == robot.GetDirection()) {
            robot.GoCommand(dir);
            qDebug() << "Trying to go";
        } else {
            robot.SetDirection(dir);
            qInfo() << "Changing direction";
        }
        qInfo() << ">>> New player position: <новая позиция робота> dir <направление робота>";
    }

    void OnReleaseMoveKey(Direction) {
        // Этот метод пока ничего не будет делать.
    }

private:
    Game& game_;
};
