#pragma once
<<<<<<< HEAD
#include "object.h"
#include "utility/painter.h"
// #include <QString>

class ElementWithAsset {
public:
    ElementWithAsset(const Asset& asset) : asset_(asset) {}
    ElementWithAsset() = default;

protected:
    const Asset& GetAsset() const {
        return asset_;
    }

private:
    Asset asset_;
};


class Tile : public ElementWithAsset {
private :
    GameContext context_;
    std::string asset_name_;
public:
    using ElementWithAsset::ElementWithAsset;
    Tile(const GameContext& context, std::string asset_name)
        : ElementWithAsset()
        , context_(context)
        , asset_name_(asset_name)    {
        AssetLoader load;
        // auto asset_name = asset.Rotate(Random());
        load.LoadTile("floors", asset_name_);
    }

    virtual void Draw(Coordinate pos, DrawContext& context) const {
        context.painter.DrawFloor(GetAsset(), pos);
    }
};

class Wall : public ElementWithAsset  {
private :
    // GameContext context_;
public:
    Wall(
        // const GameContext& context
         )
        : ElementWithAsset()
        // , context_(context)
    {
        // AssetLoader load;
        // load.LoadTile("walls", "wall-white");
    }
    using ElementWithAsset::ElementWithAsset;

    //определит, может ли персонаж пройти через стенку
    virtual bool CanPass(const Character& character, Direction dir) const = 0;

    /*Метод Interact будет вызываться,
    когда персонаж character,
    двигаясь в направлении dir, попытается переместиться на клетку, в которой расположен объект.
    */
    virtual void Interact(Character&, Direction) {}

    virtual void Draw(DrawContext& context, Coordinate pos, Orientation dir) const {
        // Напишите код.
        context.painter.DrawWall(GetAsset(), pos, dir);
    }
};

struct Cell {
    Tile* floor = nullptr;
    Wall* left_wall = nullptr;
    Wall* top_wall = nullptr;
};

// описывает один этаж
class Floor {
public:
    Floor()
        : cells_(Array2D<Cell>(2,2))
        ,level_(0)
        ,w_(0)
        ,h_(0) {

    };
    Floor(int level, int w, int h)
        : cells_(Array2D<Cell>(w+2,h+2))
        ,level_(level)
        ,w_(w)
        ,h_(h)
    { }

    int GetLevel() const {return level_;}

    void SetTile(Coordinate2D where, Tile* tile) {
        cells_.Get(where).floor = tile;
    }
    void SetWall(Coordinate2D where, Direction dir, Wall* wall) {
        GetWallPtr(where, dir) = wall;
    }
    Wall* GetWall(Coordinate2D where, Direction dir) {
        return GetWallPtr(where, dir);
    }

    int Square() const {
        return w_*h_;
    }

    void DrawFloor(DrawContext& context) const {
        for (int i = 0; i < h_; ++i) {
            for (int j = 0; j < w_; ++j) {
                Coordinate pos({.x_pos=j,.y_pos=i, .z_pos=level_});
                auto cell = cells_.Get({j,i});
                cell.floor->Draw(pos, context);
            }
        }
    }

    // Нарисует целую линию горизонтальных стен.
    void DrawHWalls(DrawContext& context, int y) const {
        // Пройдитесь по клеткам ряда "y"
        // и для каждой клетки нарисуйте top_wall.
        for (int j = 0; j < w_; ++j) {
            Coordinate pos({.x_pos=j,.y_pos=y, .z_pos=level_});
            auto cell = cells_.Get({j,y});
            cell.top_wall->Draw(context, pos, Orientation::kHorizontal);
        }
    }

    void DrawVWall(DrawContext& context, Coordinate pos) const {
        // Нарисуйте left_wall у клетки в позиции pos.
            auto cell = cells_.Get({pos.x_pos, pos.y_pos});
            cell.top_wall->Draw(context, pos, Orientation::kVertical);
    }

private:
    Array2D<Cell> cells_;
    int level_;
    int w_;
    int h_;
    Wall*& GetWallPtr(Coordinate2D where, Direction dir) {
        switch (dir) {
        case Direction::kUp :
            return cells_.Get(where).top_wall;
        case Direction::kLeft :
            return cells_.Get(where).left_wall;
        case Direction::kRight :
            return cells_.Get(where.x_pos+1, where.y_pos).left_wall;
        case Direction::kDown :
            return cells_.Get(where.x_pos, where.y_pos+1).top_wall;
        }
    }

};

class Field {
public:
    Field(int w, int h)
        : w_(w)
        , h_(h){}

    int GetWidth() const {return w_;}

    int GetHeight() const {return h_;}

    Size GetRect() const {
        return {GetWidth(), GetHeight()};
    }
    void AddFloor(int level) {
        map_[level] = Floor(level, w_, h_);
    }

    Floor& GetFloor(int floor) {
        return map_.at(floor);
    }

    const Floor& GetFloor(int floor) const {
        return map_.at(floor);
    }

private:
    std::map<int, Floor> map_;
    int w_;
    int h_;
};
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
