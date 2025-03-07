#pragma once
#include "object.h"

class Character : public Object {
private:
    Direction dir_;
public:
    Character(GameContext& context, Coordinate coordinate, Direction dir)
        : Object(context, coordinate)
        , dir_(dir){}
    void SetDirection(Direction dir) {dir_ = dir;}
    Direction GetDirection() const {return dir_;}
};
