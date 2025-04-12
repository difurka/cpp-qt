#pragma once
#include "context.h"

#include "utility/geometry.h"
#include "utility/utility.h"
#include "utility/assets.h"
#include "darkeners.h"

#include <QDebug>

/*
Класс Object является базовым классом для:
персонажей (Character),
лестниц (Stairs).
Каждый объект обладает характеристиками:
    Местоположение объекта на карте — это позиция, которая задаётся координатами.
               Используется структура Coordinate из файла utility/geometry.h.
    Видимость объекта — bool visibility_.

Структура Coordinate описывает положение объекта в игровом мире.
    x_pos и y_pos — положение по вертикали и горизонтали на плане этажа;
    z_pos — номер этажа.

Структура GameContext будет содержать ссылки на все необходимые данные для функционирования объектов
 */

inline QString DirectionText(Direction dir) {
    switch(dir) {
    case kUp: return "up";
    case kLeft: return "left";
    case kRight: return "right";
    case kDown: return "down";
    }
}

inline QString GetTextCoord(Coordinate coord) {
    return  QString::number(coord.x_pos) +"," + QString::number(coord.y_pos) + "," + QString::number(coord.z_pos);
}

class Character;

class Object {
private:
    GameContext& context_;
    Coordinate coordinate_;
    bool visibility_{true};
    std::optional<Coordinate> target_position_;
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
    void SetTargetPosition(Coordinate position) {
        target_position_ = position;
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

    /*Метод Interact будет вызываться,
    когда персонаж character,
    двигаясь в направлении dir, попытается переместиться на клетку, в которой расположен объект.
    Например, метод Interact у лестницы будет перемещать персонажа на другой этаж, если он подошёл с нужной стороны.
    */
    virtual void Interact(Character&, Direction) {};

    // Метод CanCover определяет, может ли персонаж character встать на клетку с объектом.
    virtual bool CanCover(const Character&, Direction) const {return !IsVisible();};

    virtual void Draw(DrawContext& context) const = 0;
};
