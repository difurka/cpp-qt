#pragma once

#include "character.h"

class Player : public Character {

public:
    using Character::Character;
    Player(GameContext& context, Coordinate coordinate, Direction dir)
        : Character(context, coordinate, dir) {
        qInfo() << "Player spawned on " << GetTextCoord(GetPosition()) << " dir " << DirectionText(GetDirection());
    }

    void GoCommand(Direction dir) {
        if (!CanPassWall(dir)) { // Если робот не может пройти стену, то нужно вызвать у стены Interact и завершить метод.
            auto wall = GetWall(dir);
            wall->Interact(*this, dir);
            qInfo() << "Player stoped on wall";
        } else if (!CanGo(dir)) { //  то нужно вызвать Interact для всех объектов, которые находятся в целевой клетке, и завершить метод
            Coordinate coord = GetPosition() + Coordinate::FromDirection(dir);
            // список объектов в этой клетке
            auto objects = GetContext().object_map.Get(coord);
            for (auto &el: objects) {
                el->Interact(*this, dir);
            }
            qInfo() << "Player stoped on object";
        } else {
            Coordinate coord = GetPosition() + Coordinate::FromDirection(dir);
            SetPosition(coord);
            qInfo() << "Player moves";
        }
    }

    bool IsActive() const override {
        return true;
    }
};
