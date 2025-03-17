#pragma once
#include "field.h"
#include "character.h"
#include "utility/random.h"

class FloorTile : public Tile {
public:
    FloorTile(
        const GameContext& context,
        std::string asset_name)
        : Tile()
        , context_(context)
        , asset_name_(asset_name)    {

        auto asset = context_.asset_loader.LoadTile("floors", asset_name);
        auto angle = context_.random.GetInRange(1,44);
        asset.Rotate(angle);
        qInfo() << angle;
        SetAsset(asset);
    }
private :
    GameContext context_;
    std::string asset_name_;
};

class EmptyTile : public Tile {
    using Tile::Tile;
};

const QColor door_color{100, 100, 100, 128};
const QColor edge_color{50, 50, 100, 128};
const int edge_width = 1;

class Door : public Wall {
private:
    bool is_opened_{false};
public:
    using Wall::Wall;
    void Interact(Character& character, Direction) override {
        if (character.IsActive())
            is_opened_ = true;
        qInfo() << "Opening door";
    }

    bool CanPass(const Character&, Direction) const override {
        return is_opened_;
    }

    void Draw(DrawContext& context, Coordinate pos, Orientation dir) const override {
        if (!is_opened_) {
            {
                // Первая створка.
                CoordinateF p1 = pos;
                CoordinateF p2 = p1 + CoordinateF{0, 0, 1};
                CoordinateF p3 = p2 + CoordinateF(Coordinate::FromOrientation(dir)) * 0.5;
                context.painter.DrawRect(p1, p2, p3, door_color, edge_color, edge_width, context.darkener.GetDarkness(pos));
            }
            {
                // Вторая створка.
                CoordinateF p1 = pos + Coordinate::FromOrientation(dir);
                CoordinateF p2 = p1 + CoordinateF{0, 0, 1};
                CoordinateF p3 = p2 - CoordinateF(Coordinate::FromOrientation(dir)) * 0.5;
                context.painter.DrawRect(p1, p2, p3, door_color, edge_color, edge_width, context.darkener.GetDarkness(pos));
            }
        }
    }
};

class EmptyWall : public Wall {
public:
    using Wall::Wall;
    bool CanPass(const Character&, Direction) const override {
        return true;
    }

    void Draw(DrawContext&, Coordinate, Orientation) const override {
    }
};

class EdgeWall : public Wall {
private :
        GameContext context_;
public:
         EdgeWall(
        const GameContext& context
        )
        : Wall()
        , context_(context)
    {
             SetAsset(context_.asset_loader.LoadTile("walls", "wall-white"));
         }

    bool CanPass(const Character&, Direction) const override {
        return false;
    }

};
