#pragma once
#include "object.h"
#include "field.h"

class Character : public Object {
private:
    Direction dir_;
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

    bool CanPassWall(Direction dir) const {
        auto wall = GetWall(dir);
        if (!wall) return false;
        return wall->CanPass(*this,dir);
    }

    bool CanGo(Direction dir) const {
        // return CanCover(*this, dir);
        Coordinate coord = GetPosition() + Coordinate::FromDirection(dir);
        for (auto el : GetContext().object_map)
            if (!el.CanCover(coord, dir)) return false;
        return true;
    }

    virtual bool IsActive() const {
        return false;
    }
};
