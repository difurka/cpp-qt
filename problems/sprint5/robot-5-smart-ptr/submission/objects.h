#pragma once
// #include "utility/geometry.h"
#include "object.h"
// #include "darkener.h"
// #include"utility/assets.h"


class Character;

class Stairs : public Object {
private:
    Direction dir_;
    bool down_;
    std::optional<AssetInDirections> sprites_;

protected:
    void SetSprites(const AssetInDirections& sprites) {
        sprites_ = sprites;
    }

public:
    Stairs(GameContext& context, Coordinate coordinate, Direction dir, bool down)
        : Object(context, coordinate)
        , dir_(dir)
        , down_(down) {
        SetSprites(context.asset_loader.LoadWithDirection("objects", down ? "dstair" : "stair"));
    }
    Direction GetDirection() const {return dir_;}
    bool IsDown() const {return down_;}

    void Interact(Character& character, Direction dir) override {
        if (dir == Invert(dir_)) {
            Coordinate current_position = character.GetPosition();
            auto new_position = current_position
                                + Coordinate{0, 0, down_ ? -1 : 1}
                                + Coordinate::FromDirection(dir)*2;
            character.SetPosition(new_position);
            if (down_) {
                qInfo() << "Go stairs down";
            } else {
                qInfo() << "Go stairs up";
            }

        } else {
            qInfo() << "Trying to go stairs in the wrong dir";
        }
    }

    void Draw(DrawContext& context) const override {
        // Получите ассет из sprites_ на основе направления
        // взгляда персонажа и нарисуйте его.

        // qDebug() << "draw" << name_;
        auto asset = sprites_.value().Get(GetDirection());
        // qDebug() << "draw_after" << name_;
        // context.painter.DrawObject(
        //     asset,
        //     GetPosition(),
        //     context.darkener.GetDarkness(GetPosition()));
        // qDebug() << "draw_after2" << name_;

        context.painter.DrawObject(
            sprites_->Get(dir_), //asset,
            GetPosition(),
            context.darkener.GetDarkness(GetPosition()));
            }
};
