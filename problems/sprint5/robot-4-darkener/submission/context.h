#pragma once

#include "utility/utility.h"
#include <QDebug>

class Field;
class Object;
class Darkener;
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
    const Darkener& darkener;
};
