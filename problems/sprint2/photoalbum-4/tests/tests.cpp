#include <QtTest>
<<<<<<< HEAD
=======

#include <QtTest>
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
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
#include <prac/QTimer>
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

#include <mainwindow.h>

#include <string>

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
<<<<<<< HEAD
=======
    void cleanupTestCase();
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
    void init();
    void cleanup();

    void TestMenu0();
    void TestMenu1();
    void TestMenu5();
    void TestMenu10();
    void TestClick();

private:
    void matchFiles(size_t index, string message = "Файл не соответствует ожидаемому"){
        QVERIFY2(
            image_dir.filePath(window->GetCurrentFile()) == image_dir.filePath(images[index]),
            message.c_str());
    };

    MainWindow* window;
    QPushButton* btn_left;
    QPushButton* btn_right;
<<<<<<< HEAD
    QString dir_path = ":/cats/images/";
    QDir image_dir;
    QStringList images;
    const prac::QTimer* timer;
=======
    QLabel* lbl_new_;
    QString dir_path = ":/cats/images/";
    QDir image_dir;
    QStringList images;
<<<<<<< HEAD
    QGuiApplication *app;
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
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
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
    QDir im_dir(dir_path);
    image_dir = im_dir; // Ask me what is going on, I won't tell you the answer...
    images = im_dir.entryList();
    QVERIFY2(images.size() > 1, "В заданной директории из файла ресурсов находится меньше двух файлов");

}

void TestYourApp::init()
{
    int argc = 0;
    static const QApplication static_app(argc, {});

    window = new MainWindow();
    QVERIFY2(window != nullptr, "Окно приложения не создано");
    window->show();
    QVERIFY2(window->isVisible(), "Окно приложения не активируется");

    btn_left = FindElementByName<QPushButton>(window, "btn_left");
    QVERIFY2(btn_left, "Не найден элемент btn_left класса QPushButton");

    btn_right = FindElementByName<QPushButton>(window, "btn_right");
    QVERIFY2(btn_right, "Не найден элемент btn_right класса QPushButton");

<<<<<<< HEAD
    timer = prac::QTimer::getLastCreated();
    QVERIFY2(timer, "Не найден таймер");

    window->SetFolder(dir_path);
=======
    window->SetFolder(dir_path);

    lbl_new_ = FindElementByName<QLabel>(window, "lbl_new_");

>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void TestYourApp::TestMenu0(){
    auto childs = window->children();
    auto action = findElementByText<QAction>(window, "Отключить", "QAction");
    action->trigger();

<<<<<<< HEAD
    QVERIFY(timer->getInterval() == 0);
=======
    QVERIFY(window->getTimer().getState() == 0);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void TestYourApp::TestMenu1(){
    auto childs = window->children();
    auto action = findElementByText<QAction>(window, "1 секунда", "QAction");
    action->trigger();

<<<<<<< HEAD
    QVERIFY(timer->getInterval() == 1000);
=======
    QVERIFY(window->getTimer().getState() == 1000);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void TestYourApp::TestMenu5(){
    auto childs = window->children();
    auto action = findElementByText<QAction>(window, "5 секунд", "QAction");
    action->trigger();

<<<<<<< HEAD
    QVERIFY(timer->getInterval() == 5000);
=======
    QVERIFY(window->getTimer().getState() == 5000);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void TestYourApp::TestMenu10(){
    auto childs = window->children();
    auto action = findElementByText<QAction>(window, "10 секунд", "QAction");
    action->trigger();

<<<<<<< HEAD
    QVERIFY(timer->getInterval() == 10000);
=======
    QVERIFY(window->getTimer().getState() == 10000);
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void TestYourApp::TestClick(){
    matchFiles(0, "Файл по умолчанию не соответствует первому файлу в директории");
    for (auto i = 0; i < images.size() - 2; ++i){

        QTest::mouseClick(btn_right, Qt::LeftButton);
        matchFiles(i + 1);
    }
}

<<<<<<< HEAD
=======
void TestYourApp::cleanupTestCase()
{
}

>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
void TestYourApp::cleanup()
{
    delete window;
}

<<<<<<< HEAD
QTEST_MAIN(TestYourApp)
=======
QTEST_APPLESS_MAIN(TestYourApp)
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

#include "tests.moc"
