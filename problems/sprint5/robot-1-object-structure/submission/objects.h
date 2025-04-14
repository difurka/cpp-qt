#pragma once
<<<<<<< HEAD
// #include "utility/geometry.h"
// #include "object.h"
#include "character.h"
class Character;
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

    void Interact(Character& character, Direction dir) {
        if (dir == Invert(dir_)) {
            Coordinate current_position = character.GetPosition();
            auto new_position = current_position
                                + Coordinate{0, 0, down_ ? -1 : 1}
                                + Coordinate::FromDirection(dir);
            SetPosition(new_position);
            if (down_) {
                qInfo() << "Go stairs down";
            } else {
                qInfo() << "Go stairs up";
            }

        } else {
            qInfo() << "Trying to go stairs in the wrong dir";
        }
    }
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
