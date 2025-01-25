
// Core headers
#include <QtTest>
#include <QtWidgets/QApplication>
#include <memory>
#include <prac/QTimer>

#include "level_loader.h"

class TestYourApp : public QObject
{
    Q_OBJECT
public:
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:

    void init();
    void cleanup();

    void TestDefault();

private:

};


void TestYourApp::init()
{

}

void TestYourApp::TestDefault() {}

void TestYourApp::cleanup()
{
}

QTEST_MAIN(TestYourApp)

#include "tests.moc"
