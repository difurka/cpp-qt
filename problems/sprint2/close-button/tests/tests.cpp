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

// add necessary includes here

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
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void TestCloseButton();

private:
    MainWindow* window;
    QPushButton *yourButton;
    QLineEdit *textView;
<<<<<<< HEAD
=======
    QApplication *app;
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
};


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
    QVERIFY2(buttons.size() == 1, "В приложении должна быть ровно одна копка QPushButton");
    yourButton = buttons.first();
    
}

void TestYourApp::TestCloseButton()
{

    QTest::mouseClick(yourButton, Qt::LeftButton);
    QVERIFY2(!window->isVisible(), "Окно приложения не было закрыто после нажатия на кнопку");

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