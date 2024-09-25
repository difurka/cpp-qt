#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class Calendar {
<<<<<<< HEAD
    kEastern,
    kTibetan,
    kZoroastrian
};

enum class Horoscope {
    kZodiac,
=======
    kEast,
    kTibet,
    kZoroastr
};

enum class Horoscope {
    kZodiak,
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
    kDruid
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

<<<<<<< HEAD
    void on_rb_eastern_clicked();


    void on_le_year_textChanged(const QString &);

    void on_rb_tibetan_clicked();

    void on_rb_zoroastrian_clicked();

    void on_cb_is_date_clicked(bool checked);

    void on_rb_zodiac_clicked();

    void on_rb_druid_clicked();

    void on_sb_day_valueChanged(int);

    void on_cb_month_currentIndexChanged(int);

private:
    Ui::MainWindow *ui;
    Calendar calendar_ = Calendar::kEastern;
    Horoscope horoscope_ = Horoscope::kZodiac;
    int year_;
    QString ShowCalendar();
    QString ShowHoroscope();
    void MakeMagic();
=======
private:
    Ui::MainWindow *ui;
    Calendar calendar_ = Calendar::kEast;
    Horoscope horoscope_ = Horoscope::kZodiak;
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
};
#endif // MAINWINDOW_H
