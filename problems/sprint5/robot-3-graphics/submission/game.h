#pragma once
<<<<<<< HEAD
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

        Coordinate pos = player_->GetPosition();
        // auto level = pos.z_pos;
        Floor floor = field_.GetFloor(pos.z_pos);
        floor.DrawFloor(draw_context);
        auto h = field_.GetHeight();
        auto w = field_.GetWidth();
        for (auto y = 0; y < h; ++y) {
            floor.DrawHWalls(draw_context, y);
            for (auto x = 0; x < w; ++x) {
                floor.DrawVWall(draw_context, {x,y});
                const auto& objects = object_map_.Get(pos);
                for (auto el : objects) {
                    if (el->IsVisible() && el->GetPosition() == pos) {
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
=======
>>>>>>> 541e3aa (Обновление репы из коммита d47d2edd58e101f1b791602c719e21967478ae5b (#14))
