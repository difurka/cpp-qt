#pragma once
#include "object.h"
#include "field.h"
#include "utility/assets.h"
// Персонаж — объект класса Character — задаётся четырьмя спрайтами,
// которые соответствуют четырём направлениям взгляда.
// Также некоторые предметы могут быть повёрнуты в разные стороны

class Character : public Object {
private:
    Direction dir_;
    std::optional<AssetInDirections> sprites_;
    std::optional<AnimatedAssetInDirections> anim_sprites_;
protected:
    std::shared_ptr<Wall> GetWall(Direction dir) const {
        auto coord = GetPosition();
        auto floor = coord.z_pos;
        return GetContext().field.GetFloor(floor).GetWall(Coordinate2D{coord.x_pos, coord.y_pos} , dir);
    }

    void SetWalkSprites(const AnimatedAssetInDirections& sprites) {
        anim_sprites_ = sprites;
    }

    void SetSprites(const AssetInDirections& sprites) {
        sprites_ = sprites;
    }

public:
    Character(GameContext& context, Coordinate coordinate, Direction dir)
        : Object(context, coordinate)
        , dir_(dir){
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

        // const Asset* asset = nullptr;
        // if (sprites_.has_value()) {
        //     // Сохранить ссылку на нужный ассет.
        //     sprites_->Get(dir_);
        // } else if (anim_sprites_.has_value()){
        //     // Сохранить ссылку на нужный ассет.
        //     auto slide = GetContext().timer.Now() / 40;
        //     asset  = &anim_sprites_->Get(dir_).GetFrame(slide);
        // }

        // if (asset != nullptr) {
        //     // Нарисовать.
        //     context.painter.DrawObject(*asset, GetPosition(),context.darkener.GetDarkness(GetPosition()));
        // }

        const Asset* asset = nullptr;

        if (!(anim_sprites_.has_value()) && sprites_.has_value()) {
            asset =  &sprites_->Get(dir_);

        } else if (anim_sprites_.has_value()) {
            auto slide = GetContext().timer.Now() % 40;
            asset= &anim_sprites_->Get(dir_).GetFrame(slide);
        }

        if (asset != nullptr) {
            context.painter.DrawObject(*asset, GetPosition(),context.darkener.GetDarkness(GetPosition()));
        }




        // auto asset  = &walk_sprites_->Get(dir_).GetFrame(slide); //sprites_->Get(dir_); //sprites_.value().Get(GetDirection());


    }
};
