#pragma once
<<<<<<< HEAD
#include "field.h"
#include "character.h"

class FloorTile : public Tile {

};

class EmptyTile : public Tile {

};

class Door : public Wall {
private:
    bool is_opened_{false};
public:
    void Interact(Character& character, Direction) override {
        if (character.IsActive())
            is_opened_ = true;
        qInfo() << "Opening door";
    }

    bool CanPass(const Character&, Direction) const override {
        return is_opened_;
    }
};

class EmptyWall : public Wall {
public:
    bool CanPass(const Character&, Direction) const override {
        return true;
    }
};

class EdgeWall : public Wall {
public:
    bool CanPass(const Character&, Direction) const override {
        return false;
    }
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
