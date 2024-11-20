#include "winterwindow.h"
#include "ui_winterwindow.h"
#include <QColorDialog>
#include <QPaintEvent>

WinterWindow::WinterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WinterWindow)
{
    ui->setupUi(this);
}

WinterWindow::~WinterWindow()
{
    delete ui;
}

void WinterWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    prac::QPainter painter(this);
    painter.setPen(Qt::black);
    double size = double(ui->sld_size->value());

    SnowFlakeParams flake_params{
        .center = {width() / 2., height() / 2.},
        .color = color_,
        .size = size,
        .line_width = ui->sld_line->value() / 15.,
        .rotation = double(ui->sld_rotation->value())
    };

<<<<<<< HEAD
<<<<<<< HEAD
    // Создайте снежинку (объект класса SnowFlake) и нарисуйте её методом Draw.
    SnowFlake snow(flake_params);
    snow.Draw(painter);
=======
    // Создайте снежинку (объект класса SnowFlake) и нарисуйте её методом draw.
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
    // Создайте снежинку (объект класса SnowFlake) и нарисуйте её методом Draw.
>>>>>>> 47bc733 (Обновление репы из коммита b47b06684c4e76b7854de46134a95c1bfc70a120 (#11))

    QRect rect(10, 10, width() - 20, height() - 20);

    QFont font("Verdana", 12);
    painter.setFont(font);
    painter.setPen(Qt::white);

    // Получите описание снежинки из метода GetDescription,
    // напечатайте этот текст в прямоугольнике rect.
<<<<<<< HEAD
    QString des = snow.GetDescription();
    painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, des);
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

void WinterWindow::on_btn_color_clicked()
{
    QColorDialog dialog{color_};
    dialog.exec();
    color_ = dialog.selectedColor();
    update();
}
<<<<<<< HEAD



=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
