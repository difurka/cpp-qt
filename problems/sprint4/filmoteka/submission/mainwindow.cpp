#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_add_clicked() {
    // Получите данные о фильме методом GetMovie().
    auto movie = GetMovie();
    if (movie.name.isEmpty()) return;
    auto it = movies_.indexOf(movie);
    if (it != -1) {
        auto iter = movies_.begin();
        std::advance(iter, it);
        iter->rating = movie.rating;
        iter->is_watched = movie.is_watched;
    } else {
        movies_.append(movie);
    }
    ApplyModel(movie);
    ApplyMovie(movie);
    // Если фильм уже есть в списке, то отредактируйте его.
    // Если нет — добавьте в список.
    // После изменения списка вызовите ApplyModel.
    // После этого можно вызвать ApplyMovie, чтобы
    // данные не сбивались.
}

void MainWindow::ApplyModel(const Movie &selection) {
    // Заполните виджеты ui->cb_list_done и ui->cb_list_wait,
    ui->cb_list_done->clear();
    ui->cb_list_wait->clear();
    QList<Movie> done, wait;
    for (const auto& movie: movies_) {
        if (movie.is_watched) done.append(movie);
        else wait.append(movie);
    }


    // используя их методы clear и addItems.

    ui->cb_list_done->addItems(ToString(done));
    ui->cb_list_wait->addItems(ToString(wait));
    // Вам пригодится метод ToString.
    // Также примените выделение, используя метод 
    // setCurrentIndex.
    auto n = done.indexOf(selection);
    if (n == -1) {
        n = wait.indexOf(selection);
        ui->cb_list_wait->setCurrentIndex(n);
    } else {
        ui->cb_list_done->setCurrentIndex(n);
    }
}

QString MainWindow::ToString(const Movie &movie) {
    QString str_genre = "";
    switch(movie.genre) {
    case Genre::kComedy : str_genre = "Комедия"; break;
    case Genre::kAction : str_genre = "Боевик"; break;
    case Genre::kDrama : str_genre = "Драма"; break;
    case Genre::kFairyTale : str_genre = "Сказка"; break;
    case Genre::kAnimation : str_genre = "Мультфильм"; break;
    case Genre::kHorror : str_genre = "Ужасы"; break;
    }
    return str_genre + " '" + movie.name + "' рейтинг: " + QString::number(movie.rating);
}

QStringList MainWindow::ToString(const QList<Movie> &movies) {
    // Напишите этот метод. Используйте ToString.
    QStringList res;
    for (const auto& el: movies) {
        res.append(ToString(el));
    }
    return res;

}

Movie MainWindow::GetMovie() const {
  return Movie{.name = ui->le_name->text(),
    .genre = static_cast<Genre>(ui->cb_genre->currentIndex()),
    .rating = ui->dsb_rating->value(),
    .is_watched = ui->chb_is_done->isChecked()};
}

void MainWindow::ApplyMovie(const Movie &movie) {
    ui->le_name->setText(movie.name);
    ui->cb_genre->setCurrentIndex(static_cast<int>(movie.genre));
    ui->dsb_rating->setValue(movie.rating);
    ui->chb_is_done->setCheckState(movie.is_watched ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
}

void MainWindow::on_cb_list_wait_currentIndexChanged(int index) {
    // Если index неотрицательный, заполните интерфейс,
    // используя ApplyMovie.
    if (index>=0) {
        // auto movies = ui->cb_list_wait->itemText(index);
        // auto iter = movies_.begin();
        // std::advance(iter, index);
        // Movie movie = *iter;

        QList<Movie> wait;
        for (const auto& movie: movies_) {
            if (!movie.is_watched) wait.append(movie);
        }
        ApplyMovie(wait[index]);
    }
}

void MainWindow::on_cb_list_done_currentIndexChanged(int index) {
    // Если index неотрицательный, заполните интерфейс,
    // используя ApplyMovie.
    if (index>=0) {

        QList<Movie> wait;
        for (const auto& movie: movies_) {
            if (movie.is_watched) wait.append(movie);
        }
        ApplyMovie(wait[index]);
    }
}
