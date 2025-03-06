#include <QCoreApplication>
#include <QtTest>

#include "mainwindow.h"
#include "ui_mainwindow.h"

// add necessary includes here

class TestMap : public QObject
{
    Q_OBJECT

public:
    TestMap();
    ~TestMap();

private slots:
    void init();

    // Первая группа тестов.
    void TestSizeInit();
    void TestSizeWithBooks();
    void TestSizeWithAddedItem();

    // Вторая группа тестов.
    void TestMainWidgetInit();
    void TestMainWidgetWithBooks();
    void TestMainWidgetWithAddedItem();

    // Третья группа тестов.
    void TestEnableButtonsInit();
    void TestEnableButtonsWithBooks();
    void TestEnableButtonsWithAddedItem();
private:
    MainWindow map_;
};

TestMap::TestMap() {}

TestMap::~TestMap() {}

void TestMap::init(){
    QTest::mouseClick(map_.ui->btn_clear, Qt::LeftButton);
}

// Первая группа тестов.
void TestMap::TestSizeInit(){
    init();
    QVERIFY2(map_.ui->txt_size->text() == "0", "Не найден элемент для ввода километров");
}
void TestMap::TestSizeWithBooks(){
    init();
    QTest::mouseClick(map_.ui->btn_books, Qt::LeftButton);
    QVERIFY2(map_.ui->txt_size->text() == "6", "Не найден элемент для ввода километров");
}
void TestMap::TestSizeWithAddedItem(){
    init();
    QTest::mouseClick(map_.ui->btn_books, Qt::LeftButton);
    QTest::keyClicks(map_.ui->txt_elem_key, "K"); // Ввод.
    QTest::keyClicks(map_.ui->txt_elem_value, "VV"); // Ввод.
    QTest::mouseClick(map_.ui->btn_set_by_key, Qt::LeftButton);
    QVERIFY2(map_.ui->txt_size->text() == "7", "Не найден элемент для ввода километров");
}

// Вторая группа тестов.
void TestMap::TestMainWidgetInit(){
    init();
    QVERIFY2(map_.ui->list_widget->count() == 1, "err");
    QVERIFY2(map_.ui->list_widget->item(0)->text() == "end", "1");
}
void TestMap::TestMainWidgetWithBooks(){
    init();
    QVERIFY2(map_.ui->list_widget->count() == 1, "err");
    QTest::mouseClick(map_.ui->btn_books, Qt::LeftButton);
    QVERIFY2(map_.ui->list_widget->count() == 7, "err");
    QVERIFY2(map_.ui->list_widget->item(0)->text() == "А. и Б. Стругацкие: Жук в муравейнике", "1");
    QVERIFY2(map_.ui->list_widget->item(1)->text() == "Д. Адамс: В основном безвредна", "1");
    QVERIFY2(map_.ui->list_widget->item(2)->text() == "Р. Брэдбери: Лёд и пламя", "1");
    QVERIFY2(map_.ui->list_widget->item(3)->text() == "Т. Пратчетт: Плоский мир", "1");
    QVERIFY2(map_.ui->list_widget->item(4)->text() == "Ф. Дик: Солнечная лотерея", "1");
    QVERIFY2(map_.ui->list_widget->item(5)->text() == "Ф. Кафка: Превращение", "1");
    QVERIFY2(map_.ui->list_widget->item(6)->text() == "end", "1");
}
void TestMap::TestMainWidgetWithAddedItem(){
    init();
    QTest::mouseClick(map_.ui->btn_books, Qt::LeftButton);
     QTest::keyClicks(map_.ui->txt_elem_key, "Key"); // Ввод.

    QTest::mouseClick(map_.ui->btn_set_by_key, Qt::LeftButton);
    QVERIFY2(map_.ui->list_widget->count() == 8, "err");

    QVERIFY2(map_.ui->list_widget->item(0)->text() == "А. и Б. Стругацкие: Жук в муравейнике", "1");
    QVERIFY2(map_.ui->list_widget->item(1)->text() == "А. и Б. СтругацкиеKey: Жук в муравейнике", "1");

    QVERIFY2(map_.ui->list_widget->item(2)->text() == "Д. Адамс: В основном безвредна", "1");
    QVERIFY2(map_.ui->list_widget->item(3)->text() == "Р. Брэдбери: Лёд и пламя", "1");
    QVERIFY2(map_.ui->list_widget->item(4)->text() == "Т. Пратчетт: Плоский мир", "1");
    QVERIFY2(map_.ui->list_widget->item(5)->text() == "Ф. Дик: Солнечная лотерея", "1");
    QVERIFY2(map_.ui->list_widget->item(6)->text() == "Ф. Кафка: Превращение", "1");
    QVERIFY2(map_.ui->list_widget->item(7)->text() == "end", "1");
}

// Третья группа тестов.
void TestMap::TestEnableButtonsInit(){
     init();
    QVERIFY2(
        !map_.ui->btn_dec_iterator->isEnabled(),
        "The button is blocked"
        );
     QVERIFY2(
         !map_.ui->btn_inc_iterator->isEnabled(),
         "The button is blocked"
         );
    QVERIFY2(
        !map_.ui->btn_erase->isEnabled(),
        "The button is blocked"
        );

}
void TestMap::TestEnableButtonsWithBooks(){
    init();
    QTest::mouseClick(map_.ui->btn_books, Qt::LeftButton);
    QVERIFY2(
        !map_.ui->btn_dec_iterator->isEnabled(),
        "The button is blocked"
        );
    QVERIFY2(
        map_.ui->btn_inc_iterator->isEnabled(),
        "The button is blocked"
        );
    QVERIFY2(
        map_.ui->btn_erase->isEnabled(),
        "The button is blocked"
        );
}
void TestMap::TestEnableButtonsWithAddedItem(){
    init();
    QTest::mouseClick(map_.ui->btn_books, Qt::LeftButton);
    QVERIFY2(
        !map_.ui->btn_dec_iterator->isEnabled(),
        "The button is blocked"
        );
    QVERIFY2(
        map_.ui->btn_inc_iterator->isEnabled(),
        "The button is blocked"
        );
    QVERIFY2(
        map_.ui->btn_erase->isEnabled(),
        "The button is blocked"
        );
    QTest::keyClicks(map_.ui->txt_elem_key, "Key"); // Ввод.

    QTest::mouseClick(map_.ui->btn_set_by_key, Qt::LeftButton);
    QVERIFY2(
        !map_.ui->btn_dec_iterator->isEnabled(),
        "The button is blocked"
        );
    QVERIFY2(
        map_.ui->btn_inc_iterator->isEnabled(),
        "The button is blocked"
        );
    QVERIFY2(
        map_.ui->btn_erase->isEnabled(),
        "The button is blocked"
        );
}


QTEST_MAIN(TestMap)

#include "tst_testmap.moc"
