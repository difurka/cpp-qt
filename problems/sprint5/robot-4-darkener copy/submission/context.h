#pragma once

#include "utility/utility.h"
#include "darkener.h"

class Field;
class Object;
class RandomGen;
class AssetLoader;
class Painter;

struct GameContext {
    ObjectMap<Object>& object_map;
    Field& field;
    RandomGen& random;         // Для внесения случайных изменений.
    AssetLoader& asset_loader; // Для загрузки ассетов
};

struct DrawContext {
    Painter& painter;
    const Darkener& darkener;
};
