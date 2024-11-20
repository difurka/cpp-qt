
// Core headers
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QtTest>

#include "prac/QInputDialog"

#include <vector>

#include "mainwindow.h"

#include "utils.h"


extern QString custom_url;
extern QString custom_dir;

class TestYourApp : public QObject
{
    Q_OBJECT
public:
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void TestCustomUrl();
    void TestCustomDir();

    void getAction(int, QString, std::function<void()> new_action)
    {
        action = new_action;
    }

private:

<<<<<<< HEAD
<<<<<<< HEAD
=======
    QGuiApplication *app;
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
    Setting* setting;
    QComboBox* cb_action;
    QPushButton* pb_save;
    std::function<void()> action;

};


void TestYourApp::initTestCase()
{
<<<<<<< HEAD
<<<<<<< HEAD

=======
    int argc = 0;
    char* argv[] = {};
    app = new QApplication(argc, argv);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======

>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
}



void TestYourApp::init()
{
    setting = new Setting();
    QVERIFY2(setting != nullptr, "Окно настроек не создано");

    cb_action = getChild<QComboBox>(setting, "cb_action", "QComboBox");
    pb_save = getChild<QPushButton>(setting, "pb_save", "QPushButton");

    connect(setting, &Setting::signalSetAction, this, &TestYourApp::getAction);

}

void TestYourApp::TestCustomUrl()
{
    QString url = "https://super.duper.custom.url.org";
    prac::QInputDialog::setInput(url);

    cb_action->setCurrentIndex(5);
    clickWidget(pb_save);
    action();

    QVERIFY2(custom_url == url, "Открытый url не соответствует ожидаемому");


}

void TestYourApp::TestCustomDir()
{
    QString dir = "/home/student/practicum/best_project_ever/";
    prac::QInputDialog::setInput(dir);

    cb_action->setCurrentIndex(6);
    clickWidget(pb_save);
    action();

    QVERIFY2(custom_dir == dir, "Открытая директория не соответствует ожидаемой");
}

void TestYourApp::cleanupTestCase()
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
    delete app;
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
}

void TestYourApp::cleanup()
{
    delete setting;
}

<<<<<<< HEAD
<<<<<<< HEAD
QTEST_MAIN(TestYourApp)
=======
QTEST_APPLESS_MAIN(TestYourApp)
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
QTEST_MAIN(TestYourApp)
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))

#include "tests.moc"
