#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

static const std::vector<QString> months = {
    QStringLiteral("января"), QStringLiteral("февраля"),
    QStringLiteral("марта"), QStringLiteral("апреля"),
    QStringLiteral("мая"), QStringLiteral("июня"),
    QStringLiteral("июля"), QStringLiteral("августа"),
    QStringLiteral("сентября"), QStringLiteral("октября"),
    QStringLiteral("ноября"), QStringLiteral("декабря"),
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QString GetFormatType1(int day, int month, int year);
    QString GetFormatType2(int day, int month, int year);
    QString GetFormatType3(int day, int month, int year);

    QString GetStrNumDays(int num_days, int year);
    void ShowFormattedDate();
    void SetError(const QString& err_text);

private slots:
    void on_le_date_textChanged(const QString&);
    void on_le_day_textChanged(const QString&);
    void on_le_month_textChanged(const QString&);
    void on_le_year_textChanged(const QString&);

private:
    Ui::MainWindow *ui;
    bool editing_now_ = false;
};
#endif // MAINWINDOW_H
