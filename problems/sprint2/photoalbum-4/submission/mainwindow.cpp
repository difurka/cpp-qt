<<<<<<< HEAD
// Решение предыдущей задачи

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <prac/QFileDialog>

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

    // Прячем основное меню.
    ui->menuBar->hide();
    // Разрешаем вызов контекстного меню на всём окне.
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    // Соединяем сигнал вызова меню со слотом,
    // который напишем далее.
    connect(this, &QMainWindow::customContextMenuRequested,
            this, &MainWindow::slotCustomMenuRequested);

    connect(ui->action_up_windows, &QAction::triggered, this, &MainWindow::slotClickTop);
    connect(ui->action_use_resources , &QAction::triggered, this, &MainWindow::slotClickResources);
    connect(ui->action_choose_dir , &QAction::triggered, this, &MainWindow::slotClickDir);
    connect(ui->action_close , &QAction::triggered, this, &MainWindow::slotClose);


    connect(&timer_, &prac::QTimer::timeout, this, &MainWindow::slotTimeout);
    connect(ui->action_1sec, &QAction::triggered, this, &MainWindow::slotClick1Sec);
    connect(ui->action_5sec, &QAction::triggered, this, &MainWindow::slotClick5Sec);
    connect(ui->action_10sec, &QAction::triggered, this, &MainWindow::slotClick10Sec);

    connect(ui->action_0sec, &QAction::triggered, this, &MainWindow::slotClick0Sec);


}

void MainWindow::UnChecked() {
    ui->action_1sec->setChecked(false);
    ui->action_0sec->setChecked(false);
    ui->action_10sec->setChecked(false);
    ui->action_5sec->setChecked(false);
}

void MainWindow::slotTimeout() {
    right_move_=true;
    cur_file_index_ =(++cur_file_index_)%QDir(current_folder_).entryList().size();
    SetPixmap(GetCurrentFile());
    FitImage();
}


void MainWindow::slotClick1Sec() {
    UnChecked();
    ui->action_1sec->setChecked(true);
    timer_.start(1000);

}

void MainWindow::slotClick5Sec() {
    UnChecked();
    ui->action_5sec->setChecked(true);
    timer_.start(5000);
}

void MainWindow::slotClick0Sec() {
    UnChecked();
    ui->action_0sec->setChecked(true);
    timer_.stop();
}

void MainWindow::slotClick10Sec() {
    UnChecked();
    ui->action_10sec->setChecked(true);
    timer_.start(10000);
}


void MainWindow::slotClose() {
    close();
}

void MainWindow::slotClickDir() {
    QString dir = prac::QFileDialog::getExistingDirectory(this,
                                                    QString("Открыть папку"),
                                                    QDir::currentPath(),
                                                    prac::QFileDialog::ShowDirsOnly
                                                        |prac::QFileDialog::DontResolveSymlinks);
    // qDebug() << "dir" << dir;
    SetFolder(dir);
}

void MainWindow::slotClickResources() {
    SetFolder(":/cats/images/");
}

void MainWindow::slotClickTop(bool checked) {
    // qDebug()<< checked;
    setWindowFlags(windowFlags().setFlag(Qt::WindowStaysOnTopHint, checked));
    show();
}

void MainWindow::slotCustomMenuRequested(QPoint pos) {
    // Метод ui->menu->popup открывает меню в заданном месте.
    // Используем метод mapToGlobal, чтобы преобразовать
    // координаты точки на форме в координаты точки экрана.
    ui->menu->popup(this->mapToGlobal(pos));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    if(active_pixmap.isNull()) return;
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


bool MainWindow::IsDirEmpty() const {
    // auto test_active_pixmap = QPixmap(path);
    // QDir dir(current_folder_);
    // QStringList list_files = dir.entryList();
    // auto file_index_first = cur_file_index_;
    // while(active_pixmap.isNull()) {
    //     file_index_first =(++file_index_first)%QDir(current_folder_).entryList().size();
    //     if (cur_file_index_ == file_index_first) {
    //         return true;
    //     }
    //     active_pixmap = QPixmap(GetCurrentFile());
    // }
        return false;
}

void MainWindow::SetFolder(const QString &d)
{
    current_folder_ = d;
    cur_file_index_ = 0;
    // qDebug() << "current_folder_" << current_folder_;


    // if (IsDirEmpty()) {
    //     qDebug() << "empty" << d;
    //     UpdateEnabled(false);
    // } else {
        // qDebug() << "full";
        UpdateEnabled(true);
        SetPixmap(GetCurrentFile());
        FitImage();

}

QString MainWindow::GetCurrentFile() const
{
    QDir dir(current_folder_);
    QStringList list_files = dir.entryList();

    // Сохраним количество файлов.
    // int total = int(list_files.size());
    // cur_file_index_ % list_files.size();
    int file_index =( cur_file_index_ % list_files.size() +list_files.size())%list_files.size(); //std::min(cur_file_index_, total - 1);
    //file_index = std::max(0, file_index);

    // Используем file_index, а не cur_file_index_.
    return dir.filePath(list_files[file_index]);
}


// void MainWindow::UpdateEnabled() {
//     // Количество изображений в папке.
//     int max_images = QDir(current_folder_).entryList().size();

//     // Устанавливаем активность кнопки «влево».
//     ui->btn_left->setEnabled(cur_file_index_ > 0);

//     // Устанавливаем активность кнопки «вправо».
//     ui->btn_right->setEnabled(cur_file_index_ < max_images - 1);
// }

void MainWindow::UpdateEnabled(bool is_img_exist) {
    // Количество изображений в папке.
    // int max_images = QDir(current_folder_).entryList().size();
    // qDebug() << is_img_exist;
    // Устанавливаем активность кнопки «влево».
    ui->btn_left->setEnabled(is_img_exist);

    // Устанавливаем активность кнопки «вправо».
    ui->btn_right->setEnabled(is_img_exist);
}

void MainWindow::on_btn_left_clicked()
{
    // --cur_file_index_;
    // --cur_file_index_;
    timer_.stop();
    UnChecked();
    ui->action_0sec->setChecked(true);
    right_move_ = false;
    cur_file_index_ = (--cur_file_index_ % QDir(current_folder_).entryList().size() +QDir(current_folder_).entryList().size())%QDir(current_folder_).entryList().size();
    SetPixmap(GetCurrentFile());
    FitImage();
    // qDebug("left");
    //UpdateEnabled();
}


void MainWindow::on_btn_right_clicked()
{
    timer_.stop();
    UnChecked();
    ui->action_0sec->setChecked(true);
    right_move_=true;
    cur_file_index_ =(++cur_file_index_)%QDir(current_folder_).entryList().size();
    SetPixmap(GetCurrentFile());
    FitImage();
    // qDebug("left");
    //UpdateEnabled();
}

void MainWindow::SetPixmap(const QString path) {
    active_pixmap = QPixmap(path);
    // qDebug(path);
    // qDebug() << path;
    if (active_pixmap.isNull()) {
        // qDebug("null");
        // qDebug() << "null" << path;
        // qDebug() << "null" << current_folder_;
        QDir dir(current_folder_);
        QStringList list_files = dir.entryList();
        auto file_index_first = cur_file_index_;
        while(active_pixmap.isNull()) {
            // qDebug() << "cur_file_index_" << cur_file_index_;
            if (right_move_) {
                cur_file_index_ =(++cur_file_index_)%QDir(current_folder_).entryList().size();
            } else {
                 cur_file_index_ = (--cur_file_index_ % QDir(current_folder_).entryList().size() +QDir(current_folder_).entryList().size())%QDir(current_folder_).entryList().size();
            }

            if (cur_file_index_ == file_index_first) {
                UpdateEnabled(false);
                return;
                }
            active_pixmap = QPixmap(GetCurrentFile());
        }
        // qDebug() << "result cur_file_index_" << cur_file_index_;
        // qDebug() << "result path" << GetCurrentFile();
    }
}
=======
решение задачи photoalbum-3
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
