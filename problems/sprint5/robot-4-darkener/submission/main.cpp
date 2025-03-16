#include "characters.h"
#include "field_elements.h"
#include "mainwindow.h"

#include "objects.h"
#include "player.h"

#include <QApplication>

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game{15, 15};
    Player player{game.GetContext(), {5, 5, 0}, Direction::kRight};
    game.SetPlayer(&player);
    Controller controller{game};
    game.AddFloor(0);
    Victim victim{game.GetContext(), {12, 3, 0}, Direction::kRight};

    MainWindow window{game, controller};
    window.show();
    // QVERIFY(window.isVisible());
    window.paintEvent(nullptr);

    double last_darkness = Painter::GetLastDarkness();


    const auto& [start_point, radius, direction, distance] = FlashlightDarkener::getLastDarkenerParams();
    FlashlightDarkener used_darkener(start_point, radius, direction, distance);

    double expected_darkness = used_darkener.GetDarkness(CoordinateF(12, 3, 0));
    qDebug() << expected_darkness << " -jj- " << last_darkness;
    // QVERIFY(expected_darkness == last_darkness);



    // MainWindow w{game, controller};
    // w.show();
    return a.exec();
}
