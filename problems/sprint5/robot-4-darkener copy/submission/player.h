#pragma once

#include<character.h>
#include "QDebug"

class Player : public Character {
public:
    //Player player{game.GetContext(), {5, 5, 0}, Direction::kRight};
    Player(GameContext& game_context, Coordinate position, Direction dir)
        :
        Character(game_context, position, dir)
    {
        qInfo() << "Player spawned on" <<  QString::fromStdString(ToString(position)) << "dir" <<  QString::fromStdString((ToString(dir)));
        //AssetInDirections LoadWithDirection(const std::string& category, const std::string& prefix) const
        SetSprites(game_context.asset_loader.LoadWithDirection("characters", "robot")); //Загрузка ассетов

        //AnimatedAssetInDirections LoadAnimatedWithDirection(const std::string& category, const std::string& prefix, int frame) const

    }

    /*Если робот не может пройти стену (то есть CanPassWall вернул false),
     * то нужно вызвать у стены Interact и завершить метод.
     * Если робот не может попасть на целевую клетку (то есть CanGo вернул false),
     * то нужно вызвать Interact для всех объектов, которые находятся в целевой клетке,
     * и завершить метод.
     * Если и CanPassWall, и CanGo вернули true,
     * то нужно изменить положение робота, вызвав SetPosition.*/


    /*Если робот идёт вверх по лестнице — "Go stairs up".
     * Если робот идёт вниз по лестнице — "Go stairs down".
     * Если робот не может пройти стену — "Player stoped on wall".
     * Если робот не может идти из-за объекта — "Player stoped on object".
     * Если робот успешно движется — "Player moves".
     * В конструкторе робота
     * "Player spawned on <позиция> dir <направление>".
     * Используйте функцию ToString: ToString(pos), ToString(dir).*/


    void GoCommand(Direction dir) {
        if(!CanPassWall(dir)) {
            Wall* wall = GetContext().field.GetFloor(GetPosition().z_pos).GetWall(GetPosition(), dir);
            wall->Interact(*this, dir);
            qInfo() << "Player stoped on wall";
            return;
        }
        if(!CanGo(dir)) {
            Coordinate target_pos = GetPosition() + Coordinate::FromDirection(dir);
            const auto& objects = GetContext().object_map.Get(target_pos);
            for(const auto& object : objects) {
                object->Interact(*this, dir);
            }
            qInfo() << "Player stoped on object";
            return;
        }
        SetPosition(GetPosition()+Coordinate::FromDirection(dir));
        qInfo() << "Player moves";
    }

    bool IsActive() const override {
        return true;
    }
};
