#pragma once
#include "character.h"
#include "QDebug"

class Tile;

class FloorTile : public Tile {
public:
    FloorTile(const GameContext& game_context, std::string asset_name)
        :
        asset_name_(asset_name),
        game_context_(game_context)
        {
            SetAsset(game_context_.asset_loader.LoadTile("floors", asset_name));
            /*У класса Asset есть метод Rotate. Он поворачивает ассет на угол, кратный 90 градусам.
             *  Можете использовать его, чтобы сделать пол неоднородным.
             *  При определении угла используйте класс Random.*/
        }

private:
    std::string asset_name_;
    GameContext game_context_;
};

class EmptyTile : public Tile {
public:


private:

};

class Door : public Wall {
public:

    /*Переопределите для двери метод Interact,
     * установите флаг открытия в true,
     * если с дверью взаимодействует активный персонаж.*/

    //При открытии двери в логи сохраняется сообщение "Opening door".
    void Interact(Character& character, Direction) override {
        if(character.IsActive()){
            qInfo()<<"Opening door";
            is_opened_ = true;
        }
    }


    /*Также у Door переопределите метод CanPass.
     * Он должен возвратить true, если дверь открыта.*/
    bool CanPass(const Character&, Direction) const override {
        return is_opened_;
    }

    void Draw( DrawContext& draw_context,  Coordinate pos, Orientation dir) const override {
        /*Пустые стены и двери не нуждаются в ассете.
     * Для пустой стены (класс EmptyWall) нужно переопределить метод отрисовки,
     *  который ничего не делает.
     *  Дверь нарисуем из двух прямоугольников.
     *  Графический движок поддерживает их отрисовку.
     *  Прямоугольник в пространстве задаётся тремя вершинами типа CoordinateF.*/

        const QColor door_color{100, 100, 100, 128};
        const QColor edge_color{50, 50, 100, 128};
        const int edge_width = 1;


        /*Код ниже покажет створки двери.
     * Его нужно выполнить, только если дверь закрыта: */

        if(!is_opened_){
            {
                // Первая створка.
                CoordinateF p1 = pos;
                CoordinateF p2 = p1 + CoordinateF{0, 0, 1};
                CoordinateF p3 = p2 + CoordinateF(Coordinate::FromOrientation(dir)) * 0.5;
                //void Painter::DrawRect(CoordinateF pos1, CoordinateF pos2, CoordinateF pos3, QColor fill_color, QColor edge_color, double edge_width, double darkness)
                draw_context.painter.DrawRect(p1, p2, p3, door_color, edge_color, edge_width, draw_context.darkener.GetDarkness(pos));
            }
            {
                // Вторая створка.
                CoordinateF p1 = pos + Coordinate::FromOrientation(dir);
                CoordinateF p2 = p1 + CoordinateF{0, 0, 1};
                CoordinateF p3 = p2 - CoordinateF(Coordinate::FromOrientation(dir)) * 0.5;
                draw_context.painter.DrawRect(p1, p2, p3, door_color, edge_color, edge_width, draw_context.darkener.GetDarkness(pos));
            }
        }
    }

private:
    //Этот флаг показывает, что дверь открыта
    bool is_opened_ = false;

};

class EmptyWall : public Wall {
public:
    bool CanPass(const Character&, Direction) const override {
        return true;
    }


    void Draw( DrawContext&, Coordinate, Orientation) const override {
        /*Пустые стены и двери не нуждаются в ассете.
     *  Для пустой стены (класс EmptyWall) нужно переопределить метод отрисовки,
     *  который ничего не делает.*/
    }


private:

};


//EdgeWall edge_wall{game.GetContext()};
class EdgeWall : public Wall {
public:
    EdgeWall(const GameContext& game_context)
        :
        game_context_(game_context)
        {
            SetAsset(game_context_.asset_loader.LoadTile("walls", "wall-white"));
        }

    /*Для класса EdgeWall переопределите метод CanPass,
     * он всегда должен возвращать false.
     * Через сплошную стену проходить нельзя*/
    bool CanPass(const Character&, Direction) const override {
        return false;
    }
private:
    GameContext game_context_;
};
