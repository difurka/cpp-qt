#pragma once

#include<utility/geometry.h>
#include<context.h>

class Character;

class Object {
public:

    /*Конструктор класса Object должен создать новый объект с заданными параметрами
     * и добавить его на карту.
     * Для добавления объекта на карту используйте метод Place класса ObjectMap,
     * который расположен в файле utility/utility.h.
    */
    Object(GameContext& context, Coordinate position)
        :
        context_(context),
        position_(position),
        visibility_(true)

    {
        PlaceToMap();
    }

    ~Object(){
        RemoveFromMap();
    }

    Coordinate GetPosition () const {
        return position_;
    }

    void SetPosition (Coordinate position) {
        context_.object_map.Remove(position_, this);
        context_.object_map.Place(position, this);
        position_ = position;
    }

    void Disappear () {
        visibility_ = false;
    }

    bool IsVisible () const {
        return visibility_;
    }

    GameContext& GetContext() const {
        return context_;
    }

    /*Метод Interact будет вызываться, когда персонаж character,
     * двигаясь в направлении dir, попытается переместиться на клетку,
     * в которой расположен объект.
     * Например, метод Interact у лестницы будет перемещать персонажа на другой этаж,
     * если он подошёл с нужной стороны.*/
    //Версии по умолчанию сделайте такими: Interact ничего не делает.
    virtual void Interact(Character& character, Direction dir) = 0;

    //Метод CanCover определяет, может ли персонаж character встать на клетку с объектом.
    /*Версии по умолчанию сделайте такими:
     * Interact ничего не делает.
     * CanCover возвращает !IsVisible(). То есть можно вставать на клетку с объектом,
     * только если он скрыт.*/
    virtual bool CanCover(const Character&, Direction) const {
        return !IsVisible();
    }

    virtual void Draw(DrawContext& context) const = 0;



private:
    void RemoveFromMap(){
        //удалить объект с карты
        context_.object_map.Remove(position_, this);

    }
    void PlaceToMap() {
        //добавить объект на карту
        context_.object_map.Place(position_, this);

    }

private:
    GameContext& context_;
    Coordinate position_;
    bool visibility_;
};
