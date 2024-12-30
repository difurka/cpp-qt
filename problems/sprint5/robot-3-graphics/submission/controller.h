#pragma once
<<<<<<< HEAD

#include "utility/geometry.h"
#include "game.h"

class Controller {
public:
    Controller(Game& game) : game_{game} {}

    void OnMoveKey(Direction dir) {
        // Напишите реализацию метода.
        qInfo() << "<<< Moving in direction " << DirectionText(dir);
        Player& robot = game_.GetPlayer();
        if (dir == robot.GetDirection()) {
            robot.GoCommand(dir);
            qDebug() << "Trying to go";
        } else {
            robot.SetDirection(dir);
            qInfo() << "Changing direction";
        }

        qInfo() << ">>> New player position:" << GetTextCoord(robot.GetPosition()) << " dir " << DirectionText(dir);
    }

    void OnReleaseMoveKey(Direction) {
        // Этот метод пока ничего не будет делать.
    }

    void SetRedrawCallback(const std::function<void()>& callback) {
        // MainWindow::repaint;
        callback();
    }

private:
    Game& game_;
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
