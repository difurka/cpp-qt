
// Core headers
#include <QtTest>
#include <QtWidgets/QApplication>
#include <memory>
#include <prac/QTimer>

#include "field_elements.h"
#include "objects.h"
#include "game.h"
#include "mainwindow.h"
#include "player.h"
#include "utility/timer.h"
#include "characters.h"

class TestYourApp : public QObject
{
    Q_OBJECT
public:
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:

    void init();
    void cleanup();

    void TestDefault();

private:

};

void MakeRoom(Floor& floor, Wall& wall, Tile& tile, int x1, int x2, int y1, int y2) {
    for(int i = x1; i <= x2; ++i) {
        for(int j = y1; j <= y2; ++j) {
            floor.SetTile({i, j}, &tile);
            if (i == x1) {
                floor.SetWall({i, j}, Direction::kLeft, &wall);
            }
            if (i == x2) {
                floor.SetWall({i, j}, Direction::kRight, &wall);
            }
            if (j == y1) {
                floor.SetWall({i, j}, Direction::kUp, &wall);
            }
            if (j == y2) {
                floor.SetWall({i, j}, Direction::kDown, &wall);
            }
        }
    }
}

void TestYourApp::init()
{
    Game game{15, 15};
    Player player{game.GetContext(), {5, 5, 0}, Direction::kRight};
    game.SetPlayer(&player);

    Floor& floor0 = game.AddFloor(0);
    Floor& floor1 = game.AddFloor(1);

    EdgeWall edge_wall{game.GetContext()};
    Victim victim{game.GetContext(), {7, 12, 0}, Direction::kLeft};
    EmptyWall empty_wall;
    Door door1;
    Door door2;

    FloorTile marble_tile{game.GetContext(), "floor4"};

    floor0.SetWall({4, 4}, Direction::kUp, &edge_wall);
    floor0.SetWall({5, 4}, Direction::kUp, &door1);
    floor0.SetWall({6, 4}, Direction::kUp, &edge_wall);
    floor0.SetWall({4, 3}, Direction::kUp, &edge_wall);
    floor0.SetWall({5, 3}, Direction::kUp, &door2);
    floor0.SetWall({6, 3}, Direction::kUp, &edge_wall);

    MakeRoom(floor0, edge_wall, marble_tile, 4, 6, 0, 5);
    MakeRoom(floor1, edge_wall, marble_tile, 4, 6, 0, 2);
    MakeRoom(floor0, edge_wall, marble_tile, 0, 10, 6, 14);
    floor0.SetWall({5, 5}, Direction::kDown, &empty_wall);

    Stairs stair_up{game.GetContext(), {5, 1, 0}, Direction::kDown, false};
    Stairs stair_down{game.GetContext(), {5, 1, 1}, Direction::kUp, true};

    Controller controller{game};

    MainWindow window{game, controller};
    window.show();
    QVERIFY2(window.isVisible(), "Главное окно не активируется");
}

void TestYourApp::TestDefault() {}

void TestYourApp::cleanup()
{
}

QTEST_MAIN(TestYourApp)

#include "tests.moc"
