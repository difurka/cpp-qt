#pragma once
#include "character.h"

class Victim : public Character {
public:
    using Character::Character;
    Victim(GameContext& context, Coordinate coordinate, Direction dir)
        : Character(context, coordinate, dir) {
        // AssetLoader load;
        // load.LoadWithDirection("characters", "victim");
        SetSprites(context.asset_loader.LoadWithDirection("characters", "victim")); //Загрузка ассетов
    }
};
