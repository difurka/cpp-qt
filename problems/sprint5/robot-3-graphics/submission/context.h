#pragma once
<<<<<<< HEAD

#include "utility/utility.h"
#include <QDebug>

class Field;
class Object;

class RandomGen;
class AssetLoader;

struct GameContext {
    ObjectMap<Object>& object_map;
    Field& field;
    RandomGen& random;         // Для внесения случайных изменений.
    AssetLoader& asset_loader; // Для загрузки ассетов.
};


class Painter;

struct DrawContext {
    Painter& painter;
    // const Darkener& darkener;
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
