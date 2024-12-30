<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include "controller.h"

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
    void keyPressEvent(QKeyEvent *event) {
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
private:
    Ui::MainWindow *ui;
    Game& game_;
    Controller& controller_;
};
#endif // MAINWINDOW_H
=======
#pragma once
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
