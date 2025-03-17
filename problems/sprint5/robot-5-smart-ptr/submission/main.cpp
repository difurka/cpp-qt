#include "characters.h"
#include "field_elements.h"
#include "mainwindow.h"

#include "objects.h"
#include "player.h"

#include <QApplication>
#include <memory>
void MakeRoom(Floor& floor, std::shared_ptr<Wall> wall, std::shared_ptr<Tile> tile, int x1, int x2, int y1, int y2) {


    for(int i = x1; i <= x2; ++i) {
        for(int j = y1; j <= y2; ++j) {
            floor.SetTile({i, j}, tile);
            if (i == x1) {
                floor.SetWall({i, j}, Direction::kLeft, wall);
            }
            if (i == x2) {
                floor.SetWall({i, j}, Direction::kRight, wall);
            }
            if (j == y1) {
                floor.SetWall({i, j}, Direction::kUp, wall);
            }
            if (j == y2) {
                floor.SetWall({i, j}, Direction::kDown, wall);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game{15, 15};
    Player player{game.GetContext(), {5, 5, 0}, Direction::kRight};
    auto ptr_player = std::make_shared<Player>(player);
    game.SetPlayer(ptr_player);
    Floor& floor0 = game.AddFloor(0);
    Floor& floor1 = game.AddFloor(1);

    auto make_edge_wall = [&]{
        return std::make_shared<EdgeWall>(game.GetContext());
    };
    auto make_door = [&]{
        return std::make_shared<Door>();
    };

    auto victim = std::make_shared<Victim>(game.GetContext(), Coordinate{7, 12, 0}, Direction::kLeft);
    auto empty_wall = std::make_shared<EmptyWall>();


    auto make_marble_tile = [&]{return std::make_shared<FloorTile>(game.GetContext(), "floor4");};

    floor0.SetWall({4, 4}, Direction::kUp, make_edge_wall());
    floor0.SetWall({5, 4}, Direction::kUp, make_door());
    floor0.SetWall({6, 4}, Direction::kUp, make_edge_wall());
    floor0.SetWall({4, 3}, Direction::kUp, make_edge_wall());
    floor0.SetWall({5, 3}, Direction::kUp, make_door());
    floor0.SetWall({6, 3}, Direction::kUp, make_edge_wall());

    MakeRoom(floor0, make_edge_wall(), make_marble_tile(), 4, 6, 0, 5);
    MakeRoom(floor1, make_edge_wall(), make_marble_tile(), 4, 6, 0, 2);
    MakeRoom(floor0, make_edge_wall(), make_marble_tile(), 0, 10, 6, 14);
    floor0.SetWall({5, 5}, Direction::kDown, empty_wall);

    Stairs stair_up{game.GetContext(), {5, 1, 0}, Direction::kDown, false};
    Stairs stair_down{game.GetContext(), {5, 1, 1}, Direction::kUp, true};

    Controller controller{game};

    MainWindow w{game, controller};
    w.show();
    return a.exec();
}
