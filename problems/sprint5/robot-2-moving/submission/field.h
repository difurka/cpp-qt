#pragma once
#include "object.h"


class Tile {

};

class Wall {
public:

    //определит, может ли персонаж пройти через стенку
    virtual bool CanPass(const Character& character, Direction dir) const = 0;

    /*Метод Interact будет вызываться,
    когда персонаж character,
    двигаясь в направлении dir, попытается переместиться на клетку, в которой расположен объект.
    */
    virtual void Interact(Character&, Direction) {}
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
        // Wall*& wall_find = GetWallPtr(where, dir);
        GetWallPtr(where, dir) = wall;
    }
    Wall* GetWall(Coordinate2D where, Direction dir) {
        return GetWallPtr(where, dir);
    }

    int Square() const {
        return w_*h_;
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
        // Floor f = Floor(level, w_, h_);
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
