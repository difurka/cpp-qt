#pragma once
#include "context.h"

/*
Класс Game хранит все игровые объекты в контейнере типа ObjectMap<Object>.
Этот контейнер уже разработан и находится в файле utils/utility.h.
Он позволяет размещать объекты в игровом мире и находить объекты по координатам.
*/

class Game {
public:
    Game() {}

    GameContext& GetContext() {
        return context_;
    }

private:
    ObjectMap<Object> object_map_;
    GameContext context_{.object_map = object_map_,};
};
