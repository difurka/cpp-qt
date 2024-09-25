<<<<<<< HEAD
// Решение предыдущей задачи

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetPixmap(const QString path) {
        active_pixmap = QPixmap(path);
    }

    void FitImage();

private:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    QPixmap active_pixmap;
};
#endif // MAINWINDOW_H
=======
// Решение предыдущей задачи
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
