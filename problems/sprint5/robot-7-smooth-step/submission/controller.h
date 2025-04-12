#pragma once

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
        // callback_();

        qInfo() << ">>> New player position:" << GetTextCoord(robot.GetPosition()) << " dir " << DirectionText(dir);
    }

    void OnReleaseMoveKey(Direction) {
        // Этот метод пока ничего не будет делать.
    }

    void SetRedrawCallback(const std::function<void()>& callback) {
        // MainWindow::repaint;
        callback_ = callback;
    }

    void Tick() {
        // Timer timer = game_.GetContext().timer.UpdateTime();
        game_.timer_.UpdateTime(clock_.GetElapsedTime());
        if (callback_) {
            callback_();
        }
    }

private:
    Game& game_;
    std::function<void()> callback_;
    Clock clock_;
};
