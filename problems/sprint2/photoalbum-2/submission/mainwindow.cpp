<<<<<<< HEAD
// Решение предыдущей задачи

#include "mainwindow.h"
#include "ui_mainwindow.h"

// Функция подгоняет изображение под нужный размер окна.
QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if ( w_ratio < h_ratio ) {
        return src.scaledToWidth(window_width);
    } else {
        return src.scaledToHeight(window_height);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetPixmap(":/cats/images/cat1.jpg");
    FitImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    Q_ASSERT(!active_pixmap.isNull());

    // Напишите этот метод.
    // 1. Вызовите ResizeImgToFit.
    auto resizeing = ResizeImgToFit(active_pixmap, width(), height());
    // 2. Поместите изображение в lbl_img.
    ui->lbl_img->setPixmap(resizeing);

    // 3. Измените размер lbl_img.
    ui->lbl_img->resize(resizeing.width(), resizeing.height());

    // 4. Переместите lbl_img, пользуясь формулами из условия.
    // win_w, win_h — размеры окна.
    // img_w, img_h — размеры изображения.
    int lbl_x = (width() - ui->lbl_img->width()) / 2; // Координата x.
    int lbl_y = (height()- ui->lbl_img->height()) / 2; // Координата y.
    ui->lbl_img->move(lbl_x, lbl_y);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}
=======
// Решение предыдущей задачи
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
