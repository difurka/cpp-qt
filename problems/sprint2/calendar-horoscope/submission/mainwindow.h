#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class Calendar {
    kEastern,
    kTibetan,
    kZoroastrian
};

enum class Horoscope {
    kZodiac,
    kDruid
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

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
};
#endif // MAINWINDOW_H
