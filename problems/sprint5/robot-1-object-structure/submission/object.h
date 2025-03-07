#pragma once
#include "context.h"

#include "utility/geometry.h"
#include "utility/utility.h"

class Object {
private:
    GameContext& context_;
    Coordinate coordinate_;
    bool visibility_{true};
    void PlaceToMap() {context_.object_map.Place(coordinate_, this);}
    void RemoveFromMap() {context_.object_map.Remove(coordinate_, this);}
public:
    Object(GameContext& context, Coordinate coordinate)
        :context_(context)
        , coordinate_(coordinate) {
        PlaceToMap();
    }

    ~Object() {
        RemoveFromMap();
    }

    Coordinate GetPosition() const {return coordinate_;}
    void SetPosition(Coordinate position) {
        RemoveFromMap();
        coordinate_ = position;
        PlaceToMap();
    }
    bool IsVisible() const {return visibility_;}
    void Disappear() {
        visibility_ = false;
        RemoveFromMap();
    }
    GameContext& GetContext() const {return context_;}

};
