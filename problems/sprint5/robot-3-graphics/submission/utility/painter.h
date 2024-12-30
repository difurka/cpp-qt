#pragma once

#include "geometry.h"
#include "assets.h"

#include <QPixmap>
#include <QPainter>

<<<<<<< HEAD
// Графический движок

=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
class Painter {
public:
    Painter(QPainter& painter) : painter_{painter} {}

    FieldCoordinate Get3dPointWoOffset(CoordinateF pos) const;

    FieldCoordinate Get3dPoint(CoordinateF pos) const {
        return Get3dPointWoOffset(pos) + field_offset_;
    }

<<<<<<< HEAD
    // метод, который определит сдвиг всей сцены
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
    void PreparePaint(CoordinateF player_pos, Size field_size, Size window_size);

    void DrawFloor(const Asset& asset, Coordinate pos, double darkness=0);

<<<<<<< HEAD
    //Стены бывают двух направлений и отрисовываются по-разному.
    // Стены, которые идут вдоль оси X, на плане этажа изображаются горизонтальными линями,
    // при их отрисовке передаётся параметр Orientation::kHorizontal.
    // Стены, расположенные вдоль Y, на плане изображаются вертикальными линиями,
    // для них используйте Orientation::kVertical
    void DrawWall(const Asset& asset, Coordinate pos, Orientation dir, double darkness=0);

    //  метод для рисования спрайтов:
=======
    void DrawWall(const Asset& asset, Coordinate pos, Orientation dir, double darkness=0);

>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
    void DrawObject(const Asset& object_sprite, CoordinateF pos, double darkness=0);

    void DrawRect(CoordinateF p1, CoordinateF p2, CoordinateF p3, QColor fill_color, QColor edge_color, double edge_width=1, double darkness=0);

#ifdef PRAC_TESTS
    static CoordinateF GetPlayerPos();
#endif

private:
    int current_flow_ = 0;
    QPainter& painter_;
    FieldCoordinate field_offset_;
};
