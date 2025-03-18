#pragma once


#include "utility/geometry.h"
#include "utility/utility.h"
#include "utility/assets.h"
#include "utility/painter.h"
#include <context.h>

#include <QDebug>

class Character;

class ElementWithAsset {
public:
    ElementWithAsset(const Asset& asset) : asset_(asset) {}
    ElementWithAsset() = default;
protected:
    const Asset& GetAsset() const {
        return asset_;
    }

    void SetAsset(Asset asset){
        asset_ = asset;
    }

private:
    Asset asset_;
};


class Tile : public ElementWithAsset {
public:
    using ElementWithAsset::ElementWithAsset; // Используем конструктор базового класса.

    virtual void Draw(Coordinate pos, DrawContext& draw_context) const {
        //void Painter::DrawFloor(const Asset &asset, Coordinate pos, double darkness)
        draw_context.painter.DrawFloor(GetAsset(), pos, draw_context.darkener.GetDarkness(pos));
    }
private:
    //Asset asset_;
};

class Wall : public ElementWithAsset {
public:
    using ElementWithAsset::ElementWithAsset; // Используем конструктор базового класса.

    //определит, может ли персонаж пройти через стенку.
    virtual bool CanPass(const Character& character, Direction dir) const = 0;
    virtual void Interact(Character&, Direction) {}

    virtual void Draw( DrawContext& draw_context, Coordinate pos, Orientation dir) const {
        //void Painter::DrawWall(const Asset &asset, Coordinate pos, Orientation dir, double darkness)
        draw_context.painter.DrawWall(GetAsset(), pos, dir, draw_context.darkener.GetDarkness(pos));
    }

private:

};

struct Cell {
    Tile* floor = nullptr;
    Wall* left_wall = nullptr;
    Wall* top_wall = nullptr;
};


//будет описывать один этаж
/* будет хранить экземпляры Cell для каждой клетки поля
 * и по дополнительному ряду клеток снизу и справа,
 * чтобы была возможность установить стену с правого или нижнего края.*/
class Floor {
public:
    Floor(int level, int w, int h)
        :
        w_(w),
        h_(h),
        level_(level),
        cells_(w+1, h+1)
    {
    }

    int GetLevel() const {
        return level_;
    }

    //сохраняет указатель на пол в нужную ячейку поля
    void SetTile(Coordinate2D where, Tile* tile) {
        //tile записать в ячейку поля с координатами where
        cells_.Get(where).floor = tile;
    }

    //сохраняет указатель на стену в нужную ячейку поля.
    /*Методы GetWall и SetWall в классе Floor можно упростить,
     * если написать один вспомогательный метод,
     * который возвращает ссылку на указатель:*/
    void SetWall(Coordinate2D where, Direction dir, Wall* wall) {
        //wall записать в ячейку поля с координатами where
        GetWallPtr(where, dir) = wall;
    }


    //возвращает указатель на стену в требуемом месте
    Wall* GetWall(Coordinate2D where, Direction dir) {
        return GetWallPtr(where, dir);
    }


    Wall*& GetWallPtr(Coordinate2D where, Direction dir){
        /* В методе GetWallPtr используйте оператор switch по направлению.
         * Правая стена — это левая стена у соседней клетки.
         * Нижняя стена — это верхняя стена у другой соседней клетки.
         */

        switch(dir) {
        case Direction::kLeft:{
            Cell& cell = cells_.Get(where);
            return cell.left_wall;
            break;
        }
        case Direction::kRight:{
            Cell& cell = cells_.Get(Coordinate2D{where.x_pos+1, where.y_pos});
            return cell.left_wall;
            break;
        }
        case Direction::kUp:{
            Cell& cell = cells_.Get(where);
            return cell.top_wall;
            break;
        }
        case Direction::kDown:{
            /*if(where.y_pos == 0){
                Cell& cell = cells_.Get(Coordinate2D{where.x_pos, where.y_pos});
                return cell.top_wall;
            }*/
            Cell& cell = cells_.Get(Coordinate2D{where.x_pos, where.y_pos+1});
            return cell.top_wall;
            break;
        }
        }
    }

    void DrawFloor(DrawContext& draw_context) const {
        /*для рисования пола. В этом методе пройдитесь по всем клеткам этажа и вызовите у них метод Draw*/
        for (int i = 0; i < h_; ++i) {
            for (int j = 0; j < w_; ++j) {
                Coordinate pos{j, i, level_}; /* номер этажа */
                Tile* current_cell_floor = cells_.Get(pos).floor;
                if(current_cell_floor != nullptr) {
                    //qInfo() << "DrawFloor pos" <<  QString::fromStdString(ToString(pos));
                    current_cell_floor->Draw(pos, draw_context );
                }
            }
        }
    }


    void DrawHWalls(DrawContext& draw_context, int y) const {
        // Нарисует целую линию горизонтальных стен.
        // Пройдитесь по клеткам ряда "y" и для каждой клетки нарисуйте top_wall.

        for (int j = 0; j < w_+1; ++j) {
            Coordinate pos{j, y, level_}; /* номер этажа */

            Wall* current_cell_top_wall = cells_.Get(pos).top_wall;
            if(current_cell_top_wall != nullptr) {
                //qInfo() << "DrawHWalls pos" <<  QString::fromStdString(ToString(pos));
                current_cell_top_wall->Draw(draw_context,  pos, Orientation::kHorizontal);

            }





        }
    }

    /*Стены бывают двух направлений и отрисовываются по-разному.
         * Стены, которые идут вдоль оси X, на плане этажа изображаются горизонтальными линями,
         * при их отрисовке передаётся параметр Orientation::kHorizontal.
         * Стены, расположенные вдоль Y, на плане изображаются вертикальными линиями,
         * для них используйте Orientation::kVertical.*/


    void DrawVWall(DrawContext& draw_context, Coordinate pos) const {
        // Нарисуйте left_wall у клетки в позиции pos.
         Wall* current_cell_left_wall = cells_.Get(pos).left_wall;
        if(current_cell_left_wall != nullptr) {
            //qInfo() << "DrawVWall pos" <<  QString::fromStdString(ToString(pos));
            current_cell_left_wall->Draw( draw_context, pos, Orientation::kVertical);
        }
    }


private:
    /*Клетки храните в контейнере Array2D<Cell>.
     * Этот контейнер описан в файле utility.h.
     * В конструкторе он принимает размеры поля и имеет
     * метод Get для получения элемента поля с нужными координатами.*/

    /*Для инициализации контейнера ячеек используйте размеры w + 1 и h + 1,
     * чтобы можно было установить стены с краю.*/
    int w_;
    int h_;
    int level_;
    /*Клетки храните в контейнере Array2D<Cell>.
     *Этот контейнер описан в файле utility.h.
     *В конструкторе он принимает размеры поля
     *и имеет метод Get для получения элемента поля с нужными координатами.*/
    Array2D<Cell> cells_;


};


//будет описывать все этажи
class Field {
public:
    //принимает размеры игрового мира и сохраняет их в поля класса.
    Field(int w, int h)
        :
        w_(w),
        h_(h)
    {
    }

    int GetWidth() const {
        return w_;
    }

    int GetHeight() const {
        return h_;
    }

    Size GetRect() const {
        return {GetWidth(), GetHeight()};
    }

    //добавляет новый этаж с заданным номером. Сохраняет его в map.
    void AddFloor(int level) {
        floors_.insert({level, Floor(level, w_, h_)});
    }

    Floor& GetFloor(int floor) {
        return floors_.at(floor);
    }

    const Floor& GetFloor(int floor) const {
        return floors_.at(floor);
    }

private:
    std::map<int, Floor> floors_;
    int w_;
    int h_;
};
