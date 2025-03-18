#pragma once

#include<character.h>
#include "QDebug"

class Stairs : public Object {
public:
    Stairs(GameContext& game_context, Coordinate position, Direction dir, bool down)
        :
        Object(game_context, position),
        dir_(dir),
        down_(down)
    {
        SetSprites(game_context.asset_loader.LoadWithDirection("objects", down ? "dstair" : "stair")); //Загрузка ассетов
    }

    Direction GetDirection() const {
        return dir_;
    }

    bool IsDown() const {
        return down_;
    }

    /*Для класса Stairs определите метод Interact.
     * Он должен работать так:
     * Проверить, что персонаж пришёл с нужной стороны
     *  — противоположной направлению лестницы.
     *  Для его определения можно использовать метод Invert
     *  из файла geometry.h: dir == Invert(dir_).
     *
     *  Если направление верное, то нужно переместить персонажа,
     *  вызвав метод SetPosition.
     *  Персонаж перемещается на один этаж вверх или вниз
     *  (в зависимости от направления лестницы)
     *  и на две клетки в направлении движения.*/

    //Если робот пытается пойти по лестнице в неправильном направлении—
    //qInfo("Trying to go stairs in the wrong dir")


    void Interact(Character& character, Direction dir) override {
        if(dir == Invert(dir_)) {
            qInfo() << (down_ ? "Go stairs down" : "Go stairs up");
            character.SetPosition(character.GetPosition()+Coordinate{.z_pos = down_ ? -1 : 1}
                                  + Coordinate::FromDirection(dir) + Coordinate::FromDirection(dir));
        }
        qInfo() << "Trying to go stairs in the wrong dir";
    }
    void Draw(DrawContext& draw_context) const override {
        // Получите ассет из sprites_ на основе направления взгляда персонажа и нарисуйте его.
        //qInfo() << "Stairs pos" <<  QString::fromStdString(ToString(GetPosition()))
        //        << "Stairs Draw  Get(dir_)" <<  QString::number(sprites_->Get(dir_));
        //void Painter::DrawObject(const Asset &object_sprite, CoordinateF pos, double darkness)
        draw_context.painter.DrawObject(sprites_->Get(dir_), GetPosition(), draw_context.darkener.GetDarkness(GetPosition()));
    }

protected:
    void SetSprites(const AssetInDirections& sprites) {
        sprites_ = sprites;
    }

private:
    Direction dir_;
    bool down_;
    std::optional<AssetInDirections> sprites_;
};
