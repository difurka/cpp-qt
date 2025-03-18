#pragma once

#include<character.h>
#include<darkeners.h>



class Victim : public Character {
public:
    Victim(GameContext& game_context, Coordinate position, Direction dir)
        :
        Character(game_context, position, dir)
    {
        SetSprites(game_context.asset_loader.LoadWithDirection("characters", "victim")); //Загрузка ассетов
    }
private:

};


