#pragma once
#include "context.h"
#include "player.h"

/*
Класс Game хранит все игровые объекты в контейнере типа ObjectMap<Object>.
Этот контейнер уже разработан и находится в файле utils/utility.h.
Он позволяет размещать объекты в игровом мире и находить объекты по координатам.
*/
class Field;
class RandomGen;
class AssetLoader;
class Floor;
// class Player;

class Game {
public:
    Game(AssetLoader loader, int w, int h)
        : field_(w,h)
        , asset_loader_(loader) {
    }

    Game(int w, int h)
        : field_(w,h) {
    }

    GameContext& GetContext() {
        return context_;
    }

    Floor& AddFloor(int level) {
        field_.AddFloor(level);
        return field_.GetFloor(level);
    }

    void SetPlayer(Player* player) {
        player_ = player;
    }

    Field& GetField() {
        return field_;
    }

    Player& GetPlayer() {
        return *player_;
    }

    Floor& GetCurrentFloor() {
        return field_.GetFloor(player_->GetPosition().z_pos) ;
    }

    void DrawFrame(DrawContext draw_context) {


        Floor floor = GetCurrentFloor();
        floor.DrawFloor(draw_context);

        auto h = field_.GetHeight();
        auto w = field_.GetWidth();
        // auto darkness = draw_context.darkener.GetDarkness(pos);
        for (auto y = 0; y < h+1; ++y) {
            floor.DrawHWalls(draw_context, y);
            for (auto x = 0; x < w + 1; ++x) {
                Coordinate pos{y, x, floor.GetLevel()};
                floor.DrawVWall(draw_context, {x,y,floor.GetLevel()});
                const auto& objects = object_map_.Get(pos);
                // qInfo() << "In Draw: \n";
                for (auto& el : objects) {
                    if (el!=nullptr && el->IsVisible() && el->GetPosition() == pos) {
                        // qInfo() << el->name_ << QString::fromStdString(ToString(pos));
                        el->Draw(draw_context);
                    }
                }
            }
        }
    }

private:
    ObjectMap<Object> object_map_;
    GameContext context_{.object_map = object_map_, .field=field_, .random=random_, .asset_loader = asset_loader_};
    Player* player_;
    Field field_;
    RandomGen random_;         // Для внесения случайных изменений.
    AssetLoader asset_loader_;
};
