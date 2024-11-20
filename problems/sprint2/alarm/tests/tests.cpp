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

<<<<<<< HEAD
#include <QDebug>
#include <mainwindow.h>

// #include <string>
=======
#include <mainwindow.h>

#include <string>
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

using namespace std;

namespace {

const prac::QTime current_time{10, 10, 10, 147};
const prac::QTime current_time2{10, 12, 10, 211};

template<class Widget>
Widget* FindElementByName(QMainWindow* window, const QString& name) {
    auto elements = window->findChildren<Widget*>();

    auto iter = std::find_if(elements.begin(), elements.end(), [&](Widget* elem){
        return elem->objectName() == name;
    });

    return iter == elements.end() ? nullptr : *iter;
}

}

template<typename T>
void getChild(T*& child, QObject* parent, const QString& object_name, const QString& type_name)
{

    child = parent->findChild<T *>(object_name);
    QString message;
    if (type_name != "")
    {
        message = QString("В %3 не найден %1 типа %2").arg(object_name).arg(type_name).arg(parent->objectName());
    }
    else
    {
        message = QString("В %2 не найден %1").arg(object_name).arg(parent->objectName());;
    }

    QVERIFY2(child, qPrintable(message));
}

template<typename T>
T* getChild(QObject* parent, const QString& object_name, const QString& type_name = {})
{
    T* child = nullptr;
    getChild<T>(child, parent, object_name, type_name);

    return child;
}


template<class T>
void findElementByText(T*& child, QObject* parent, const QString& label, const QString& type_name) {
    auto children = parent->findChildren<T*>();

    for (const auto& child_ : children)
    {
        if (child_->text() == label)
        {
            child = child_;
            return;
        }
    }

    QString message = QString("В %3 не найден %2 c текстом %1").arg(label).arg(type_name).arg(parent->objectName());
    QVERIFY2(child, qPrintable(message));
}


template<class T>
T* findElementByText(QObject* parent, const QString& label, const QString& type_name) {

    T* child = nullptr;
    findElementByText<T>(child, parent, label, type_name);
    return child;
}


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

    void TestMenu0();
    void TestQTime();

private:
    MainWindow* window;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    prac::QTimer* timer;
};

void TestYourApp::initTestCase()
{

=======
    QPushButton* btn_left;
    QPushButton* btn_right;
    QLabel* lbl_new_;
    QString dir_path = ":/cats/images/";
    QDir image_dir;
    QStringList images;
=======
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
    QGuiApplication *app;
=======
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
    prac::QTimer* timer;
};

void TestYourApp::initTestCase()
{
<<<<<<< HEAD
    int argc = 0;
    char* argv[] = {};
    app = new QApplication(argc, argv);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======

>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))
    prac::QTime::currentTime() = current_time;
}

void TestYourApp::init()
{
    window = new MainWindow();
    QVERIFY2(window != nullptr, "Окно приложения не создано");
    window->show();
    QVERIFY2(window->isVisible(), "Окно приложения не активируется");
<<<<<<< HEAD
<<<<<<< HEAD
    
    timer = prac::QTimer::getLastCreated();
    QVERIFY2(timer, "Не найден таймер");
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
    
    timer = prac::QTimer::getLastCreated();
    QVERIFY2(timer, "Не найден таймер");
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
}

void TestYourApp::TestMenu0(){
    auto childs = window->children();
<<<<<<< HEAD
<<<<<<< HEAD
    
    QVERIFY(timer->isOn() == true);
    QVERIFY(timer->getInterval() > 0);
=======
    auto action = findElementByText<QAction>(window, "Включить будильник", "QAction");
    action->trigger();

    QVERIFY(window->GetTimer().isOn() == true);
    QVERIFY(window->GetTimer().getInterval() > 0);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
    
    QVERIFY(timer->isOn() == true);
    QVERIFY(timer->getInterval() > 0);
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
}

void TestYourApp::TestQTime(){
    auto childs = window->children();
<<<<<<< HEAD
<<<<<<< HEAD

    QVERIFY(timer->isOn() == true);

    qDebug() <<"f"<< timer->getInterval() << 1000 - current_time.msec();
    QVERIFY(timer->getInterval() == 1000 - current_time.msec());

    prac::QTime::currentTime() = current_time2;

    timer->emitTimeout();

    QVERIFY(timer->isOn() == true);
    qDebug() << timer->getInterval() << 1000 - current_time2.msec();
    QVERIFY(timer->getInterval() == 1000 - current_time2.msec() );
=======
    auto action = findElementByText<QAction>(window, "Включить будильник", "QAction");
    action->trigger();
=======
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))

    QVERIFY(timer->isOn() == true);
    QVERIFY(timer->getInterval() == 1000 - current_time.msec());

    prac::QTime::currentTime() = current_time2;

    timer->emitTimeout();

<<<<<<< HEAD
    QVERIFY(window->GetTimer().isOn() == true);
    QVERIFY(window->GetTimer().getInterval() == 1000 - current_time2.msec());
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
    QVERIFY(timer->isOn() == true);
    QVERIFY(timer->getInterval() == 1000 - current_time2.msec());
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
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
