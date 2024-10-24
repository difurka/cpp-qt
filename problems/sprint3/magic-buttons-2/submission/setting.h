<<<<<<< HEAD
#pragma once
#include <functional>

#include "functions.h"
#include <QWidget>

namespace Ui {
class Setting;
}

inline void Relax() {
    // Функция ничего не делает.
}

struct Action {
    QString name;
    std::function<void()> action;
};

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

    void SetButtonForSetting(int num) {
        current_button_idx_ = num;
    }

    void Reset();

signals:
    void signalSetAction(int, QString, std::function<void()> action);
    void signalSetURL();
    void signalSetDir();
private slots:
    void on_pb_save_clicked();

private:
    Ui::Setting *ui;
    int current_button_idx_ = 0;
    inline static std::vector<Action> actions_ = {
        {"Действие не назначено", Relax},
        {"Открыть домашнюю папку", OpenHomeDirectory},
        {"Открыть страницу Практикума", OpenPracticum},
        {"Открыть страницу Яндекса", OpenYandex},
        {"Открыть окно консоли", OpenCmd},
    };
};
=======
// Используйте ваше решение.
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
