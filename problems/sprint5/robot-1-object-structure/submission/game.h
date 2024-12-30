#pragma once
<<<<<<< HEAD
#include "context.h"
#include "player.h"

/*
Класс Game хранит все игровые объекты в контейнере типа ObjectMap<Object>.
Этот контейнер уже разработан и находится в файле utils/utility.h.
Он позволяет размещать объекты в игровом мире и находить объекты по координатам.
*/
class Field;
class Floor;
// class Player;

class Game {
public:
    Game(int w, int h): field_(w,h) {
    }

    GameContext& GetContext() {
        return context_;
    }

    Floor& AddFloor(int level) {
        field_.AddFloor(level);
        return field_.GetFloor(level);
    }

    void SetPlayer(Player* player) {
        player_ = player;
    }

    Field& GetField() {
        return field_;
    }

    Player& GetPlayer() {
        return *player_;
    }

    Floor& GetCurrentFloor() {
        return field_.GetFloor(player_->GetPosition().z_pos) ;
    }

private:
    ObjectMap<Object> object_map_;
    GameContext context_{.object_map = object_map_, .field=field_};
    Player* player_;
    Field field_;
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
