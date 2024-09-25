<<<<<<< HEAD
// Решение предыдущей задачи

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>

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
    SetFolder(":/cats/images/");
    // SetPixmap(GetCurrentFile());

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
    lbl_new_.setPixmap(resizeing);

    // 3. Измените размер lbl_new_.
    lbl_new_.resize(resizeing.width(), resizeing.height());

    // 4. Переместите lbl_new_, пользуясь формулами из условия.
    // win_w, win_h — размеры окна.
    // img_w, img_h — размеры изображения.
    int lbl_x = (width() - lbl_new_.width()) / 2; // Координата x.
    int lbl_y = (height()- lbl_new_.height()) / 2; // Координата y.
    lbl_new_.move(lbl_x, lbl_y);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}

void MainWindow::SetFolder(const QString &d)
{
    current_folder_=d;
    SetPixmap(GetCurrentFile());
    UpdateEnabled();
    FitImage();
}

QString MainWindow::GetCurrentFile() const
{
    QDir dir(current_folder_);
    QStringList list_files = dir.entryList();

    // Сохраним количество файлов.
    int total = int(list_files.size());

    int file_index = std::min(cur_file_index_, total - 1);
    file_index = std::max(0, file_index);

    // Используем file_index, а не cur_file_index_.
    return dir.filePath(list_files[file_index]);
}


void MainWindow::UpdateEnabled() {
    // Количество изображений в папке.
    int max_images = QDir(current_folder_).entryList().size();

    // Устанавливаем активность кнопки «влево».
    ui->btn_left->setEnabled(cur_file_index_ > 0);

    // Устанавливаем активность кнопки «вправо».
    ui->btn_right->setEnabled(cur_file_index_ < max_images - 1);
}

void MainWindow::on_btn_left_clicked()
{
    --cur_file_index_;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}


void MainWindow::on_btn_right_clicked()
{
    ++cur_file_index_;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}

=======
// Возьмите решение предыдущей задачи
// о фотоальбоме в качестве заготовки.
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
