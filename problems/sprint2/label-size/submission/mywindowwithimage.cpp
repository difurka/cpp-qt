#include "mywindowwithimage.h"
#include "ui_mywindowwithimage.h"

#include <QFileInfo>
#include <QDir>

#include <QtGlobal>

// Специальная магия для получения пути изображения.
#define MACRO_TO_STR_INNER(x) #x
#define MACRO_TO_STR(x) MACRO_TO_STR_INNER(x)

MyWindowWithImage::MyWindowWithImage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindowWithImage)
{
    ui->setupUi(this);

    // Получим изображение из переменной, которую задали в .pro-файле.
    // Не делайте так в реальных программах.
    QString image_path = MACRO_TO_STR(ILOVEQT_IMAGE_FULL_PATH);
    SetPixmap(ui->lbl_pixmap, image_path);
<<<<<<< HEAD
    FitToImage(ui->lbl_pixmap);
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

MyWindowWithImage::~MyWindowWithImage()
{
    delete ui;
}

void MyWindowWithImage::SetPixmap(QLabel *label_pix, const QString path)
{
    // Тут нужно вызвать FitToImage.
    // Подумайте, в каком месте метода это лучше сделать.
    QPixmap pix(path);
    Q_ASSERT(!pix.isNull());

    label_pix->setPixmap( pix );
    label_pix->show();
}

// Запишите здесь реализацию нового метода.
<<<<<<< HEAD

void MyWindowWithImage::FitToImage(QLabel* lbl) {
    auto hight = lbl->pixmap().height();
    auto weight = lbl->pixmap().width();
    lbl->setFixedSize(weight, hight);
    this->setFixedSize(weight, hight);
    lbl->move(0,0);
}
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
