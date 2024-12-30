#pragma once
<<<<<<< HEAD
#include "character.h"

class Victim : public Character {
public:
    using Character::Character;
    Victim(GameContext& context, Coordinate coordinate, Direction dir)
        : Character(context, coordinate, dir) {
        AssetLoader load;
        load.LoadWithDirection("characters", "victim");
    }
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
