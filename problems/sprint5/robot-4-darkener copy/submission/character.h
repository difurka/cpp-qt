#pragma once

#include<object.h>
#include<field.h>
#include<context.h>

class Character : public Object {
public:
    Character(GameContext& context, Coordinate position, Direction dir)
    :
    Object(context, position),
    dir_(dir)
    {}

    void Interact(Character&, Direction) override {}

    void SetDirection(Direction dir){
        dir_ = dir;
    }

    Direction GetDirection() {
        return dir_;
    }

    /*Метод CanPassWall должен использовать CanPass стены,
     * чтобы проверить, может ли персонаж пройти в нужном направлении.
     * Перед вызовом CanPass нужно проверить,
     * что указатель на стену — не nullptr.*/
    bool CanPassWall(Direction dir) const {
        Wall* wall = GetWall(dir);
        if(wall) {
            return wall->CanPass(*this, dir);
        }
        return true;
    }

    /*Метод CanGo использует CanCover, чтобы проверить,
     * может ли персонаж встать на желаемую клетку, если пойдёт в выбранном направлении.
     * В этом методе нужно:
     * Определить целевую клетку.
     * Из object_map получить список объектов в этой клетке.
     * Проверить, что для всех объектов CanCover возвращает true.
     * Если для какого-то объекта в целевой клетке CanCover вернул false,
     * то метод CanGo должен возвратить false.*/
    bool CanGo(Direction dir) const {
        Coordinate target_pos = GetPosition() + Coordinate::FromDirection(dir);
        const auto& objects = GetContext().object_map.Get(target_pos);
        for(const auto* i : objects) {
            if(!i->CanCover(*this, dir)){
                return false;
            }
        }
        return true;
    }


    virtual bool IsActive() const {
        return false;
    }

    Wall* GetWall(Direction dir) const {
        //Этот метод получит объект нужного этажа типа Floor,
        //а из него — указатель на стену
        Floor& floor = GetContext().field.GetFloor(GetPosition().z_pos);
        return floor.GetWall(GetPosition(), dir);

    }
    void Draw(DrawContext& draw_context) const override {
        // Получите ассет из sprites_ на основе направления взгляда персонажа и нарисуйте его

        //qInfo() << "Character pos" <<  QString::fromStdString(ToString(GetPosition()))
        //        << "Character Draw  Get(dir_)" <<  QString::number(sprites_->Get(dir_));

        //void Painter::DrawObject(const Asset &object_sprite, CoordinateF pos, double darkness)
        draw_context.painter.DrawObject(sprites_->Get(dir_), GetPosition(), draw_context.darkener.GetDarkness(GetPosition()));
    }

protected:
    void SetSprites(const AssetInDirections& sprites) {
        sprites_ = sprites;
    }

private:
    Direction dir_;
    std::optional<AssetInDirections> sprites_;
};
