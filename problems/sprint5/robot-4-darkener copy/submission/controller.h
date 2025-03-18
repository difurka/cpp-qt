#pragma once

#include "utility/geometry.h"
#include "game.h"
#include "QDebug"

class Controller {
public:
    Controller(Game& game) : game_{game} {}

    void OnMoveKey(Direction dir) {


        /*Если изменяется направление робота — "Changing direction".
         *Если вызывается GoCommand — "Trying to go".
         *В конце метода OnMoveKey — ">>> New player position: <новая позиция робота> dir <направление робота>".*/


        // Напишите реализацию метода.
        /*Метод OnMoveKey будет вызываться,
         * когда пользователь нажал стрелку на клавиатуре,
         * а OnReleaseMoveKey — когда отпустил.
         * В методе OnMoveKey нужно:
         * Получить направление робота.
         * Если оно совпадает с dir, вызвать у робота метод GoCommand.
         * Если не совпадает с dir,
         * вызвать у робота SetDirection и поменять направление.*/

        qInfo() << "<<< Moving in direction" << QString::fromStdString(ToString(dir));
        Player& player = game_.GetPlayer();
        Direction cur_dir = player.GetDirection();
        if(dir == cur_dir) {
            player.GoCommand(dir);
            qInfo() << "Trying to go";
            qInfo() << ">>> New player position:" << QString::fromStdString(ToString(player.GetPosition())) << "dir" << QString::fromStdString(ToString(player.GetDirection()));
            callback_();
            return;
        }
        player.SetDirection(dir);
        qInfo() << "Changing direction";

        callback_();


    }

    void OnReleaseMoveKey(Direction) {
        // Этот метод пока ничего не будет делать.
    }

    /**/


    /*Перерисовка выполняется автоматически, например при изменении размеров окна.
     * Контроллер должен иметь возможность инициировать перерисовку, если в модели что-то изменилось.
     * Для этого добавьте в него метод задания функции отрисовки:
     *
     * void SetRedrawCallback(const std::function<void()>& callback);
     *
     * Этот метод сохранит функцию обратного вызова в контроллер.
     *
     * Вызывать её нужно при перемещении персонажа, чтобы изобразить новое его положение.
     *
     * Метод SetRedrawCallback вызывается из конструктора MainWindow.
     * Для перерисовки вызывайте не paintEvent, а метод repaint класса MainWindow,
     * и Qt сам запустит процесс перерисовки.*/


    /*    controller_.SetRedrawCallback([this, last_draw = std::optional<std::chrono::steady_clock::time_point>{}]() mutable {
        repaint();
    });*/

    void SetRedrawCallback(const std::function<void()>& callback)  {
        callback_ = callback;
    }



private:
    Game& game_;
    std::function<void()> callback_;
};
