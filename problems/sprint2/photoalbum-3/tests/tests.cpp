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
<<<<<<< HEAD
=======
    void cleanupTestCase();
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
    void init();
    void cleanup();

    void TestInRange();
    void TestGoLeft();
    void TestGoRight();

private:
    void matchFiles(size_t index, string message = "Файл не соответствует ожидаемому"){
        QVERIFY2(
            image_dir.filePath(window->GetCurrentFile()) == image_dir.filePath(images[index]),
            message.c_str());
    };

    MainWindow* window;
    QPushButton* btn_left;
    QPushButton* btn_right;
    QLabel* lbl_new_;
    QString dir_path = ":/cats/images/";
    QDir image_dir;
    QStringList images;
<<<<<<< HEAD
=======
    QGuiApplication *app;
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
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

    window->SetFolder(dir_path);

    lbl_new_ = FindElementByName<QLabel>(window, "lbl_new_");
<<<<<<< HEAD
<<<<<<< HEAD
=======
//    QVERIFY2(lbl_new_, "Не найден элемент lbl_img класса QLabel");
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
}


void TestYourApp::TestInRange(){

    matchFiles(0, "Файл по умолчанию не соответствует первому файлу в директории");
    QVERIFY2(!btn_left->isEnabled(), "Кнопа btn_left должна быть деактивирована при установке директории (установке первого файла в качестве текущего)");
    QVERIFY2(btn_right->isEnabled(), "Кнопа btn_right должна быть активирована при установке директории (установке первого файла в качестве текущего)");

    for (auto i = 0; i < images.size() - 2; ++i){

        QTest::mouseClick(btn_right, Qt::LeftButton);
        matchFiles(i + 1);
        QVERIFY2(btn_left->isEnabled(), "Кнопа btn_left должна быть активна в диапазоне файлов от второго до предпоследнего");
        QVERIFY2(btn_right->isEnabled(), "Кнопа btn_right должна быть активна в диапазоне файлов от второго до предпоследнего");

    }

    QTest::mouseClick(btn_right, Qt::LeftButton);
    matchFiles(images.size() - 1);

    QVERIFY2(btn_left->isEnabled(), "Кнопа btn_left должна быть активна на последнем файле");
    QVERIFY2(!btn_right->isEnabled(), "Кнопа btn_right должна быть неактивна на последнем файле");

    for (auto i = 0; i < images.size() - 2; ++i){

        QTest::mouseClick(btn_left, Qt::LeftButton);
        matchFiles(images.size() - 2 - i);
        QVERIFY2(btn_left->isEnabled(), "Кнопа btn_left должна быть активна в диапазоне файлов от второго до предпоследнего");
        QVERIFY2(btn_right->isEnabled(), "Кнопа btn_right должна быть активна в диапазоне файлов от второго до предпоследнего");

    }

    QTest::mouseClick(btn_left, Qt::LeftButton);
    matchFiles(0);
    QVERIFY2(!btn_left->isEnabled(), "Кнопа btn_left должна быть неактивна на первом файле");
    QVERIFY2(btn_right->isEnabled(), "Кнопа btn_right должна быть активна на первом файле");


}

void TestYourApp::TestGoLeft(){

    matchFiles(0, "Файл по умолчанию не соответствует первому файлу в директории");
    QVERIFY2(!btn_left->isEnabled(), "Кнопа btn_left должна быть деактивирована при установке директории (установке первого файла в качестве текущего)");
    QVERIFY2(btn_right->isEnabled(), "Кнопа btn_right должна быть активирована при установке директории (установке первого файла в качестве текущего)");


    for(int i = 0; i < 5; ++i){
        QTest::mouseClick(btn_left, Qt::LeftButton);
        matchFiles(0, "Кнопка btn_left не должна переключать текущий файл на первом файле");
        QVERIFY2(!btn_left->isEnabled(), "Кнопа btn_left должна быть неактивна на первом файле");
        QVERIFY2(btn_right->isEnabled(), "Кнопа btn_right должна быть активна на первом файле");
    }

}

void TestYourApp::TestGoRight(){

    matchFiles(0, "Файл по умолчанию не соответствует первому файлу в директории");
    QVERIFY2(!btn_left->isEnabled(), "Кнопа btn_left должна быть деактивирована при установке директории (установке первого файла в качестве текущего)");
    QVERIFY2(btn_right->isEnabled(), "Кнопа btn_right должна быть активирована при установке директории (установке первого файла в качестве текущего)");

    for (auto i = 0; i < images.size() - 1; ++i){
        QTest::mouseClick(btn_right, Qt::LeftButton);
    }

    matchFiles(images.size() - 1, "Последний файл не соответствует последнему файлу в директории");
    QVERIFY2(btn_left->isEnabled(), "Кнопа btn_left должна быть активна на последнем файле");
    QVERIFY2(!btn_right->isEnabled(), "Кнопа btn_right должна быть неактивна на последнем файле");

    for(int i = 0; i < 5; ++i){
        QTest::mouseClick(btn_right, Qt::LeftButton);
        matchFiles(images.size() - 1, "Кнопка btn_right не должна переключать текущий файл на последнем файле");
        QVERIFY2(btn_left->isEnabled(), "Кнопа btn_left должна быть активна на последнем файле");
        QVERIFY2(!btn_right->isEnabled(), "Кнопа btn_right должна быть неактивна на последнем файле");
    }

}

<<<<<<< HEAD

<<<<<<< HEAD
=======
=======
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
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
