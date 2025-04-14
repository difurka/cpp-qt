#include "field_elements.h"
#include "mainwindow.h"

<<<<<<< HEAD
#include "objects.h"
#include "player.h"
#include "controller.h"
#include "game.h"
=======
#include "player.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

<<<<<<< HEAD
    Game game{10, 10};
    Player player{game.GetContext(), {5, 5, 0}, Direction::kRight};
    game.SetPlayer(&player);

    Floor& floor0 = game.AddFloor(0);
    Floor& floor1 = game.AddFloor(1);

    EdgeWall edge_wall;
    Door door1;
    Door door2;

    floor0.SetWall({5, 5}, Direction::kLeft, &edge_wall);
    floor0.SetWall({5, 4}, Direction::kLeft, &edge_wall);
    floor0.SetWall({5, 3}, Direction::kLeft, &edge_wall);
    floor0.SetWall({5, 2}, Direction::kLeft, &edge_wall);
    floor0.SetWall({5, 5}, Direction::kDown, &edge_wall);
    floor0.SetWall({5, 5}, Direction::kRight, &edge_wall);
    floor0.SetWall({5, 4}, Direction::kRight, &edge_wall);
    floor0.SetWall({5, 3}, Direction::kRight, &edge_wall);
    floor0.SetWall({5, 2}, Direction::kRight, &edge_wall);
    floor0.SetWall({5, 4}, Direction::kUp, &door1);
    floor0.SetWall({5, 3}, Direction::kUp, &door2);
    Stairs stair_up{game.GetContext(), {5, 1, 0}, Direction::kDown, false};
    Stairs stair_down{game.GetContext(), {5, 1, 1}, Direction::kUp, true};

    Controller controller{game};

    MainWindow w{game, controller};
    w.show();
    return a.exec();
}


/*
Player spawned on  "5,5,0"  dir  "right"
<<< Moving in direction  "up"
Changing direction
>>> New player position:  "5,5,0"  dir:  "up"
<<< Moving in direction  "up"
Trying to go
Player moves
>>> New player position:  "5,4,0"  dir:  "up"
<<< Moving in direction  "up"
Trying to go
Player stoped on wall
Opening door
>>> New player position:  "5,4,0"  dir:  "up"
<<< Moving in direction  "up"
Trying to go
Player moves
>>> New player position:  "5,3,0"  dir:  "up"
<<< Moving in direction  "up"
Trying to go
Player stoped on wall
Opening door
>>> New player position:  "5,3,0"  dir:  "up"
<<< Moving in direction  "up"
Trying to go
Player moves
>>> New player position:  "5,2,0"  dir:  "up"
<<< Moving in direction  "up"
Trying to go
Player stoped on object
Go stairs up
>>> New player position:  "5,0,1"  dir:  "up"
<<< Moving in direction  "right"
Changing direction
>>> New player position:  "5,0,1"  dir:  "right"
<<< Moving in direction  "right"
Trying to go
Player moves
>>> New player position:  "6,0,1"  dir:  "right"
<<< Moving in direction  "down"
Changing direction
>>> New player position:  "6,0,1"  dir:  "down"
<<< Moving in direction  "down"
Trying to go
Player moves
>>> New player position:  "6,1,1"  dir:  "down"
<<< Moving in direction  "left"
Changing direction
>>> New player position:  "6,1,1"  dir:  "left"
<<< Moving in direction  "left"
Trying to go
Player stoped on object
Trying to go stairs in the wrong dir
>>> New player position:  "6,1,1"  dir:  "left"
<<< Moving in direction  "up"
Changing direction
>>> New player position:  "6,1,1"  dir:  "up"
<<< Moving in direction  "up"
Trying to go
Player moves
>>> New player position:  "6,0,1"  dir:  "up"
<<< Moving in direction  "left"
Changing direction
>>> New player position:  "6,0,1"  dir:  "left"
<<< Moving in direction  "left"
Trying to go
Player moves
>>> New player position:  "5,0,1"  dir:  "left"
<<< Moving in direction  "down"
Changing direction
>>> New player position:  "5,0,1"  dir:  "down"
<<< Moving in direction  "down"
Trying to go
Player stoped on object
Go stairs down
>>> New player position:  "5,2,0"  dir:  "down"
<<< Moving in direction  "down"
Trying to go
Player moves
>>> New player position:  "5,3,0"  dir:  "down"
<<< Moving in direction  "down"
Trying to go
Player moves
>>> New player position:  "5,4,0"  dir:  "down"
<<< Moving in direction  "down"
Trying to go
Player moves
>>> New player position:  "5,5,0"  dir:  "down"
<<< Moving in direction  "down"
Trying to go
Player stoped on wall
>>> New player position:  "5,5,0"  dir:  "down"
<<< Moving in direction  "right"
Changing direction
>>> New player position:  "5,5,0"  dir:  "right"
<<< Moving in direction  "right"
Trying to go
Player stoped on wall
>>> New player position:  "5,5,0"  dir:  "right"
<<< Moving in direction  "left"
Changing direction
>>> New player position:  "5,5,0"  dir:  "left"
<<< Moving in direction  "left"
Trying to go
Player stoped on wall
>>> New player position:  "5,5,0"  dir:  "left"
 */
=======
    Game game{};
    Player player{game.GetContext(), {10, 10, 0}, Direction::kRight};
    FloorTile floor1;
    EdgeWall wall1;

    MainWindow w{game};
    w.show();
    return a.exec();
}
