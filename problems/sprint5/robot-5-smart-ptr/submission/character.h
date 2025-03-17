#pragma once
#include "object.h"
#include "field.h"
#include "utility/random.h"
#include "utility/assets.h"
// Персонаж — объект класса Character — задаётся четырьмя спрайтами,
// которые соответствуют четырём направлениям взгляда.
// Также некоторые предметы могут быть повёрнуты в разные стороны

class Character : public Object {
private:
    Direction dir_;
    std::optional<AssetInDirections> sprites_;
protected:
    std::shared_ptr<Wall> GetWall(Direction dir) const {
        auto coord = GetPosition();
        auto floor = coord.z_pos;
        return GetContext().field.GetFloor(floor).GetWall(Coordinate2D{coord.x_pos, coord.y_pos} , dir);
    }

    void SetSprites(const AssetInDirections& sprites) {
        sprites_ = sprites;
    }

public:
    Character(GameContext& context, Coordinate coordinate, Direction dir)
        : Object(context, coordinate)
        , dir_(dir){
        SetSprites(context.asset_loader.LoadWithDirection("characters", "robot"));
    }

    void SetDirection(Direction dir) {dir_ = dir;}

    Direction GetDirection() const {return dir_;}

    // проверить, может ли персонаж пройти в нужном направлении
    bool CanPassWall(Direction dir) const {
        auto wall = GetWall(dir);
        if (!wall) return true;
        return wall->CanPass(*this,dir);
    }

    // может ли персонаж встать на желаемую клетку, если пойдёт в выбранном направлении
    bool CanGo(Direction dir) const {
        Coordinate coord = GetPosition() + Coordinate::FromDirection(dir);
        // список объектов в этой клетке
        auto objects = GetContext().object_map.Get(coord);
        auto result = std::all_of(
            objects.begin(),
            objects.end(),
            [&](Object * obj) {return obj->CanCover(*this, dir);}
            );
        return result;
    }

    virtual bool IsActive() const {
        return false;
    }

    void Draw(DrawContext& context) const override {
        // Получите ассет из sprites_ на основе направления
        // взгляда персонажа и нарисуйте его.
        auto asset = sprites_->Get(dir_); //sprites_.value().Get(GetDirection());
        context.painter.DrawObject(asset, GetPosition(),context.darkener.GetDarkness(GetPosition()));
    }
};
