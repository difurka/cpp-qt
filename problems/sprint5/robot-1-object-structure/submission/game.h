#pragma once
#include "context.h"

/*
Класс Game хранит все игровые объекты в контейнере типа ObjectMap<Object>.
Этот контейнер уже разработан и находится в файле utils/utility.h.
Он позволяет размещать объекты в игровом мире и находить объекты по координатам.
*/
class Field;
class Floor;
class Player;

class Game {
public:
    Game() {}

    GameContext& GetContext() {
        return context_;
    }

    Floor& AddFloor(int level) {
        field_.AddFloor(level);
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
        return player_->GetPosition().z_poz;
    }

private:
    ObjectMap<Object> object_map_;
    GameContext context_{.object_map = object_map_, .field=field_};
    Player* player_;
    Field field_;
};
