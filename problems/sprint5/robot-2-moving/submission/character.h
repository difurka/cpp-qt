#pragma once
<<<<<<< HEAD
#include "object.h"
#include "field.h"

class Character : public Object {
private:
    Direction dir_;
protected:
    Wall* GetWall(Direction dir) const {
        auto coord = GetPosition();
        auto floor = coord.z_pos;
        return GetContext().field.GetFloor(floor).GetWall(Coordinate2D{coord.x_pos, coord.y_pos} , dir);
    }
public:
    Character(GameContext& context, Coordinate coordinate, Direction dir)
        : Object(context, coordinate)
        , dir_(dir){}

    void SetDirection(Direction dir) {dir_ = dir;}

    Direction GetDirection() const {return dir_;}

    // проверить, может ли персонаж пройти в нужном направлении
    bool CanPassWall(Direction dir) const {
        auto wall = GetWall(dir);
        if (!wall) return true;
        return wall->CanPass(*this,dir);
    }

    // может ли персонаж встать на желаемую клетку, если пойдёт в выбранном направлении
    bool CanGo(Direction dir) const {
        Coordinate coord = GetPosition() + Coordinate::FromDirection(dir);
        // список объектов в этой клетке
        auto objects = GetContext().object_map.Get(coord);
        auto result = std::all_of(
            objects.begin(),
            objects.end(),
            [&](Object * obj) {return obj->CanCover(*this, dir);}
            );
        return result;
    }

    virtual bool IsActive() const {
        return false;
    }
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
