#include <QtTest>
<<<<<<< HEAD
=======

#include <QtTest>
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include <mainwindow.h>


namespace {

template<class Widget>
Widget* FindElementByName(QMainWindow* window, const QString& name) {
    auto elements = window->findChildren<Widget*>();

    auto iter = std::find_if(elements.begin(), elements.end(), [&](Widget* elem){
        return elem->objectName() == name;
    });

    return iter == elements.end() ? nullptr : *iter;
}

}


class TestYourApp : public QObject
{
    Q_OBJECT

    template<class T>
    T* findElementByText(const QString& label) {
        for (T* button : window->findChildren<T*>())
        {
            if (button->text() == label)
            {
                return button;
            }
        }
        return nullptr;
    }

public:
    TestYourApp();
    ~TestYourApp();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void Test1Plus2();
    void Test20Plus22();
    void Test50Minus50();

private:
    MainWindow* window;
    QPushButton *yourButton;
    QLineEdit *le_q, *le_t, *le_qt;
<<<<<<< HEAD
=======
    QApplication *app;
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
};

TestYourApp::TestYourApp()
{

}

TestYourApp::~TestYourApp()
{

}

void TestYourApp::initTestCase()
{
<<<<<<< HEAD

=======
    int argc = 0;
    char* argv[] = {};
    app = new QApplication(argc, argv);
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)

    window = new MainWindow();

    QVERIFY2(window != nullptr, "Окно приложения не создано");

    window->show();

    QVERIFY2(window->isVisible(), "Окно приложения не активируется");

    auto buttons = window->findChildren<QPushButton*>();
    QVERIFY2(buttons.size() == 1, "Должна быть провно одна кнопка");
    yourButton = buttons.first();

    le_q = FindElementByName<QLineEdit>(window, "le_q");
    le_t = FindElementByName<QLineEdit>(window, "le_t");
    le_qt = FindElementByName<QLineEdit>(window, "le_qt");

    QVERIFY2(le_q, "Не найден элемент le_q типа QLineEdit");
    QVERIFY2(le_t, "Не найден элемент le_t типа QLineEdit");
    QVERIFY2(le_qt, "Не найден элемент le_qt типа QLineEdit");
}

void TestYourApp::Test1Plus2()
{
    le_q->setText("1");
    le_t->setText("2");
    QTest::mouseClick(yourButton, Qt::LeftButton);
    QVERIFY2(le_qt->text() == "3", "Неверный результат");
}

void TestYourApp::Test20Plus22()
{
    le_q->setText("20");
    le_t->setText("22");
    QTest::mouseClick(yourButton, Qt::LeftButton);
    QVERIFY2(le_qt->text() == "42", "Неверный результат");
}

void TestYourApp::Test50Minus50()
{
    le_q->setText("50");
    le_t->setText("-50");
    QTest::mouseClick(yourButton, Qt::LeftButton);
    QVERIFY2(le_qt->text() == "0", "Неверный результат");
}

void TestYourApp::cleanupTestCase()
{
<<<<<<< HEAD
}

QTEST_MAIN(TestYourApp)
=======
    delete app;
}

QTEST_APPLESS_MAIN(TestYourApp)
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)

#include "tests.moc"
