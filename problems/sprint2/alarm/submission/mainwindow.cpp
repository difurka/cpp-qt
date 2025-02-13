#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <prac/QFileDialog>
#include <QFileInfo>

// #include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_one_sec_.setSingleShot(true);

    // timer_one_sec_.start(1);

    prac::QDateTime now = prac::QDateTime::currentDateTime();
    auto now_time = now.time();
    auto sec = 1000-now_time.msec();
    timer_one_sec_.start(853);



    connect(&timer_one_sec_, &prac::QTimer::timeout, this, &MainWindow::slotTimeOut);


    #if QT_VERSION >= 0x060000
        player_.setAudioOutput(&audio_output_);
        audio_output_.setVolume(100);
    #else
        player_.setVolume(100);
    #endif

    connect(ui->action_close , &QAction::triggered, this, &MainWindow::slotClose);
    connect(ui->action_load_file , &QAction::triggered, this, &MainWindow::slotLoadFile);

    // #if QT_VERSION >= 0x060000
    //     player_.setSource(QUrl::fromLocalFile(path_to_melody_));
    // #else
    //     player_.setMedia(QUrl::fromLocalFile(path_to_melody_));
    // #endif

    // // Воспроизводим песню.
    // player_.play();

}

void MainWindow::slotLoadFile() {
    path_to_melody_ = prac::QFileDialog::getOpenFileName(this,
                                                           QString::fromUtf8("Открыть файл"),
                                                           QDir::currentPath(),
                                                           "*.wav;*.mp3");
    if(path_to_melody_.isEmpty()) {
        return;
    }

    // Если да, то выведем путь к нему в надпись.
    ui->lbl_melody->setText(QFileInfo(path_to_melody_).fileName());
}

void MainWindow::slotClose() {
    close();
}


void MainWindow::slotTimeOut() {
    prac::QDateTime now = prac::QDateTime::currentDateTime();
    auto now_time = now.time();
    ui->lbl_now->setText(QString("%1 : %2 : %3")
                              .arg(now_time.hour(),  2, 10, QChar('0'))
                              .arg(now_time.minute(), 2, 10, QChar('0'))
                              .arg(now_time.second(), 2, 10, QChar('0'))
                      );
    auto sec = 1000-now_time.msec();
    timer_one_sec_.start(789);
    if (is_alarm_turned && now > alarm_time_ ) {
        ui->lbl_timeout->setText("Пора вставать");
        if(path_to_melody_.isEmpty()) {
            return;
        }
        #if QT_VERSION >= 0x060000
                player_.setSource(QUrl::fromLocalFile(path_to_melody_));
        #else
                player_.setMedia(QUrl::fromLocalFile(path_to_melody_));
        #endif

        // Воспроизводим песню.
        player_.play();
    } else if (is_alarm_turned) {
        int seconds = ((alarm_time_ - now).count() + 500) / 1000;
        ui->lbl_timeout->setText(QString("Прошло %1 миллисекунд").arg(seconds));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_start_stop_clicked()
{
    is_alarm_turned = !is_alarm_turned;
    if (!is_alarm_turned) {
        ui->pb_start_stop->setText("Старт");
        ui->lbl_timeout->setText("Установите будильник");
        player_.stop();
        return;
    }

    prac::QTime alarm_t{ui->sb_hour->value(),ui->sb_min->value(), ui->sb_sec->value()};
    auto date_now = prac::QDateTime::currentDateTime();

    alarm_time_ = date_now;
    alarm_time_.setTime(alarm_t);

    if (date_now > alarm_time_) {

        alarm_time_ = alarm_time_.addDays(1);
    }


    ui->pb_start_stop->setText("Стоп");
}

