#include <QtTest>
<<<<<<< HEAD
<<<<<<< HEAD
=======

#include <QtTest>
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
=======
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
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

    template<class T>
    T* findElementByName(const QString& name) {
        for (auto label : window->findChildren<T*>())
        {   
            if (label->objectName() == name)
            {
                return label;
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
    void TestMelborpButton_1();
    void TestMelborpButton_2();

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
    

    auto line_edits = window->findChildren<QLineEdit*>();
    QVERIFY2(line_edits.size() == 1, "В приложении должно быть ровно одно поле QLineEdit");
    textView = line_edits.first();

}

void TestYourApp::TestMelborpButton_1()
{

<<<<<<< HEAD
<<<<<<< HEAD
    QString q_original_text = "This is my awesome string!";
    QString q_reversed_text = "!gnirts emosewa ym si sihT";
=======
    std::string original_text = "This is my awesome string!";
    std::string reversed_text;
    std::reverse_copy(original_text.begin(), original_text.end(), reversed_text.begin());

    QString q_original_text = original_text.c_str();
    QString q_reversed_text = reversed_text.c_str();
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
=======
    QString q_original_text = "This is my awesome string!";
    QString q_reversed_text = "!gnirts emosewa ym si sihT";
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

    textView->setText(q_original_text);
    QVERIFY2(textView->text() == q_original_text, "Выведенный текст не совпадает с исходным");

    QTest::mouseClick(yourButton, Qt::LeftButton);

    QVERIFY2(textView->text() == q_reversed_text, "Выведенный текст не совпадает с перевёрнутым");

    QTest::mouseClick(yourButton, Qt::LeftButton);
    QVERIFY2(textView->text() == q_original_text, "Повторно перевёрнутый текст не совпадает с исходным");

}

void TestYourApp::TestMelborpButton_2()
{

    QString original_text = "Привет!";
    QString reversed_text = "!тевирП";

    textView->setText(original_text);
    QVERIFY2(textView->text() == original_text, "Выведенный текст не совпадает с исходным");

    QTest::mouseClick(yourButton, Qt::LeftButton);

    QVERIFY2(textView->text() == reversed_text, "Выведенный текст не совпадает с перевёрнутым");

    QTest::mouseClick(yourButton, Qt::LeftButton);
    QVERIFY2(textView->text() == original_text, "Повторно перевёрнутый текст не совпадает с исходным");

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