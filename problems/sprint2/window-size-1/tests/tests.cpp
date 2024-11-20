#include <QtTest>
<<<<<<< HEAD
<<<<<<< HEAD
=======

#include <QtTest>
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
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
#include <QtWidgets/QLabel>



#include <mainwindow.h>
#include <iostream>

using namespace std;



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
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();
    void TestDefault();
    void TestResize1();
    void TestResize2();


private:
    MainWindow* window;
    QLabel* lbl_size;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    QApplication *app;
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
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
    window = new MainWindow();
    QVERIFY2(window != nullptr, "Окно приложения не создано");
    window->show();
    QVERIFY2(window->isVisible(), "Окно приложения не активируется");
    lbl_size = FindElementByName<QLabel>(window, "lbl_size");
    QVERIFY2(lbl_size, "Не найден элемент lbl_size класса QLabel");
}


void check_lbl_alignment(QMainWindow* parent, QLabel* child)
{

    QVERIFY2(child->size() == parent->size(), "Размер виджета не равен размеру окна");
    QVERIFY2(child->pos() == QPoint(0, 0), "Размер виджета не равен размеру окна");

    auto alignment = child->property("alignment");
    QVERIFY2(alignment.isValid(), "Выравнивание текста в lbl_size должно быть задано полем alignement");
    auto value = alignment.value<Qt::AlignmentFlag>();
    QVERIFY2(value == Qt::AlignCenter, "Выравннивание текста в lbl_size должно быть по центру");
}

void TestYourApp::TestDefault()
{
    check_lbl_alignment(window, lbl_size);
}


void TestYourApp::TestResize1()
{
    window->resize(window->size() * 0.57);
    check_lbl_alignment(window, lbl_size);
}

void TestYourApp::TestResize2()
{
    window->resize(window->size() * 1.65);
    check_lbl_alignment(window, lbl_size);
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
    delete window;
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
