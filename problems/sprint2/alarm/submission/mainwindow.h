#pragma once

#include <QMainWindow>
#include <prac/QTimer>
#include <prac/QMediaPlayer>
#include <prac/QTime>
#include <prac/QDateTime>
<<<<<<< HEAD

#if QT_VERSION >= 0x060000
#include <QAudioOutput>
#endif
=======
#include <QAudioOutput>
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


<<<<<<< HEAD
private slots:
    void slotTimeOut();
    void on_pb_start_stop_clicked();

    void slotClose();
    void slotLoadFile();
private:
    Ui::MainWindow *ui;
    prac::QTimer timer_one_sec_{this};
    bool is_alarm_turned{false};
    prac::QDateTime alarm_time_;
    QString path_to_melody_;
    prac::QMediaPlayer player_{this};

    #if QT_VERSION >= 0x060000
    QAudioOutput audio_output_{this};
    #endif
=======
private:
    Ui::MainWindow *ui;
    prac::QTimer timer_one_sec_{this};
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
};
