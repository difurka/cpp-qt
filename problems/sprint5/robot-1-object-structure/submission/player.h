#pragma once
#include "character.h"

class Player : public Character {

public:
    using Character::Character;
    void GoCommand(Direction dir) {
        if (!CanPassWall()) {
            // Interact(); // wall
        } else if (!CanGo()) {
            // Interact() // all
        } else {
            // SetPosition();
        }
    }

    bool IsActive() const override {
        return true;
    }
};
