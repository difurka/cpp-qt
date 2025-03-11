#pragma once
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
