// Решение предыдущей задачи.
#ifndef WINTERWINDOW_H
#define WINTERWINDOW_H

#include <QMainWindow>
#include <prac/QPainter>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui {
class WinterWindow;
}
QT_END_NAMESPACE

struct Vector2D {
    double x;
    double y;
};

struct Point2D {
    double x;
    double y;
};

inline Vector2D RotateVector(Vector2D src, double angle) {
    double a_rad = angle / 180. * M_PI;
    double sin_v = std::sin(a_rad);
    double cos_v = std::cos(a_rad);
    return Vector2D{
        src.x * cos_v + src.y * sin_v, - src.x * sin_v + src.y * cos_v
    };
}

inline Vector2D Add(Vector2D l, Vector2D r) {
    return Vector2D{l.x + r.x, l.y + r.y};
}

inline Point2D Add(Point2D l, Vector2D r) {
    return Point2D{l.x + r.x, l.y + r.y};
}

struct SnowFlakeParams {
    Point2D center;
    QColor color;
    double size;
    double line_width;
    double rotation;
    int depth;
    double scale_factor;
};

class SnowFlake {
public:
    SnowFlake(SnowFlakeParams params) : params_(params) {

    }


    void GetNextLevelFlake(prac::QPainter& painter, Point2D center, int deepth) const {
        static const int num_ray = 6;
        const static int pi2 = 360;

        for (int i=0; i < num_ray; ++i) {
            auto end = DrawRotatedVector(painter, center, params_.rotation + pi2/num_ray * i, params_.size*std::pow(params_.scale_factor,deepth));
            if (deepth < params_.depth) {
                GetNextLevelFlake(painter, end, deepth+1);
            }
        }
    }


    void Draw(prac::QPainter& painter) const {
        // 1. Установите перо в painter. Нужно использовать цвет
        //    снежинки и толщину линии из переменной класса params_.
        QPen pen(QBrush(params_.color), params_.line_width);
        // border_pen.setWidth(params_.line_width);
        painter.setPen(pen);
        GetNextLevelFlake(painter, params_.center, 0);
    }

    QString GetDescription() const {
        return QString("Размер %1\nТолщина линии %2\nПоворот %3\nМножитель %4\nГлубина %5")
            .arg(params_.size)
            .arg(params_.line_width)
            .arg(params_.rotation)
            .arg(params_.scale_factor)
            .arg(params_.depth);
    }

private:
    static Point2D DrawRotatedVector(prac::QPainter& painter, Point2D center, double angle, double length) {
        Vector2D lay = RotateVector(Vector2D{length, 0}, angle);
        Point2D end = Add(center, lay);


        // Нарисуйте линию от точки center до точки end.
        // Используйте метод drawLine класса painter.
        painter.drawLine(QPointF(center.x, center.y), QPointF(end.x, end.y));
        return end;
    }

private:
    SnowFlakeParams params_;
};

class WinterWindow : public QMainWindow
{
    Q_OBJECT

public:
    WinterWindow(QWidget *parent = nullptr);
    ~WinterWindow();

private slots:
    void on_btn_color_clicked();

private:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::WinterWindow *ui;
    QColor color_ = Qt::white;
};
#endif // WINTERWINDOW_H

