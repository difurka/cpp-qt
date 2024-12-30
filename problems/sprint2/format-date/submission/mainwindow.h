#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

<<<<<<< HEAD
static const std::vector<QString> months = {
    QStringLiteral("января"), QStringLiteral("февраля"),
    QStringLiteral("марта"), QStringLiteral("апреля"),
    QStringLiteral("мая"), QStringLiteral("июня"),
    QStringLiteral("июля"), QStringLiteral("августа"),
    QStringLiteral("сентября"), QStringLiteral("октября"),
    QStringLiteral("ноября"), QStringLiteral("декабря"),
};

=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

<<<<<<< HEAD

=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
private:
    QString GetFormatType1(int day, int month, int year);
    QString GetFormatType2(int day, int month, int year);
    QString GetFormatType3(int day, int month, int year);
<<<<<<< HEAD
<<<<<<< HEAD
=======
    int CalculateDaysFromStartYear(int day, int month, int year);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))

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
