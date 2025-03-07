#pragma once
// #include "utility/geometry.h"
#include "object.h"

class Stairs : public Object {
private:
    Direction dir_;
    bool down_;
public:
    Stairs(GameContext& context, Coordinate coordinate, Direction dir, bool down)
        : Object(context, coordinate)
        , dir_(dir)
        , down_(down) {}
    Direction GetDirection() const {return dir_;}
    bool IsDown() const {return down_;}
};
