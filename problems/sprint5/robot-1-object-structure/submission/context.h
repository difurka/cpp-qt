#pragma once

#include "utility/utility.h"
#include <QDebug>

class Field;
class Object;

struct GameContext {
    ObjectMap<Object>& object_map;
    Field& field;
};
