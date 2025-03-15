#include "field_elements.h"
#include "mainwindow.h"

#include "objects.h"
#include "player.h"

#include <QApplication>
class ActiveCharacter : public Character {
public:
    ActiveCharacter(GameContext& context, Coordinate position, Direction dir)
        : Character(context, position, dir) {
    }
    [[nodiscard]] bool IsActive() const override {
        return true;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<MainWindow> window;
    std::shared_ptr<Game> game;
    std::shared_ptr<Controller> controller;
    std::shared_ptr<EdgeWall> edge_wall;
    std::shared_ptr<EmptyWall> empty_wall;
    std::shared_ptr<Door> door1, door2;


    game.reset();
    // controller.reset();
    game = std::make_shared<Game>(10, 12);
    controller = std::make_shared<Controller>(*game);

    Floor& floor0 = game->AddFloor(0);
    Floor& floor1 = game->AddFloor(1);

    edge_wall = std::make_shared<EdgeWall>();
    empty_wall = std::make_shared<EmptyWall>();
    door1 = std::make_shared<Door>();
    door2 = std::make_shared<Door>();

    floor0.SetWall({5, 5}, Direction::kLeft, edge_wall.get());
    floor0.SetWall({5, 4}, Direction::kLeft, edge_wall.get());
    floor0.SetWall({5, 3}, Direction::kLeft, edge_wall.get());
    floor0.SetWall({5, 2}, Direction::kLeft, edge_wall.get());
    floor0.SetWall({5, 5}, Direction::kDown, edge_wall.get());
    floor0.SetWall({5, 5}, Direction::kRight, edge_wall.get());
    floor0.SetWall({5, 4}, Direction::kRight, empty_wall.get());
    floor0.SetWall({5, 3}, Direction::kRight, edge_wall.get());
    floor0.SetWall({5, 2}, Direction::kRight, edge_wall.get());
    floor0.SetWall({5, 4}, Direction::kUp, door1.get());
    floor0.SetWall({5, 2}, Direction::kUp, door2.get());
    Character character(game->GetContext(), {5, 4, 0}, Direction::kRight);
    qInfo() << "Placing active character";


    // constexpr Coordinate initial_pose{5, 2, 0};
    // ActiveCharacter active_character(game->GetContext(), initial_pose, Direction::kUp);
    // qDebug() << active_character.GetPosition().GetTextCoord() <<  initial_pose.GetTextCoord();
    // Stairs stairs_up{game->GetContext(), {5, 1, 0}, Direction::kDown, false};
    // Stairs stairs_down{game->GetContext(), {5, 1, 1}, Direction::kUp, true};

    // Interaction in the wrong directions - do nothing
    Coordinate expected_position{3, 3, 0};
    Direction expected_direction = Direction::kRight;
    Player player {game->GetContext(), expected_position, expected_direction};
    game->SetPlayer(&player);
    // qDebug() << player.GetPosition().GetTextCoord() << expected_position.GetTextCoord();
    qDebug() << player.GetDirection() <<  expected_direction;

    expected_direction = Direction::kLeft;
    controller->OnMoveKey(expected_direction);

    qDebug() << player.GetDirection() << expected_direction;



    // Floor& floor0 = game.AddFloor(0);
    // Floor& floor1 = game.AddFloor(1);

    // EdgeWall edge_wall;
    // Door door1;
    // Door door2;

    // floor0.SetWall({5, 5}, Direction::kLeft, &edge_wall);
    // floor0.SetWall({5, 4}, Direction::kLeft, &edge_wall);
    // floor0.SetWall({5, 3}, Direction::kLeft, &edge_wall);
    // floor0.SetWall({5, 2}, Direction::kLeft, &edge_wall);
    // floor0.SetWall({5, 5}, Direction::kDown, &edge_wall);
    // floor0.SetWall({5, 5}, Direction::kRight, &edge_wall);
    // floor0.SetWall({5, 4}, Direction::kRight, &edge_wall);
    // floor0.SetWall({5, 3}, Direction::kRight, &edge_wall);
    // floor0.SetWall({5, 2}, Direction::kRight, &edge_wall);
    // floor0.SetWall({5, 4}, Direction::kUp, &door1);
    // floor0.SetWall({5, 3}, Direction::kUp, &door2);
    // Stairs stair_up{game.GetContext(), {5, 1, 0}, Direction::kDown, false};
    // Stairs stair_down{game.GetContext(), {5, 1, 1}, Direction::kUp, true};

    // Controller controller{game};

    // MainWindow w{game, controller};
    // w.show();
    window = std::make_shared<MainWindow>(*game, *controller);
    window->show();
    // QVERIFY2(window->isVisible(), "Главное окно не активируется");
    return a.exec();
}
