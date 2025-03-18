#pragma once
#include "context.h"
#include <player.h>
#include <field.h>
#include <utility/random.h>



class Game {
public:
   Game(int w, int h)
        :
        field_(w, h)

        {}

    GameContext& GetContext() {
        return context_;
    }

    //добавить пустой этаж с нужным номером
    Floor& AddFloor(int level) {
        field_.AddFloor(level);
        return field_.GetFloor(level);
    }

    // чтобы задать указатель на игрока
    void SetPlayer(Player* player) {
        player_ = player;
    }

    //чтобы получить игровой мир
    Field& GetField() {
        return field_;
 }

    //чтобы получить игрока
    Player& GetPlayer() {
        return *player_;
    }

    //чтобы получить текущий этаж — тот, на котором стоит робот
    Floor& GetCurrentFloor() {
        int level = player_->GetPosition().z_pos;
        return field_.GetFloor(level);
    }

    /*Отрисовка всего этажа
    Чтобы пользователь увидел игровой мир, недостаточно иметь методы рисования у каждого отдельного элемента. Эти методы нужно вызвать, причём в правильном порядке — чтобы игровые элементы не перекрывались.
    Будем делать так:
    Рисуем весь пол методом DrawFloor.
    Ряд за рядом рисуем стены и объекты.
    При рисовании ряда сделаем так:
    Рисуем верхние стены, вызывая DrawHWalls.
    Проходимся по ячейкам ряда слева направо. У каждой ячейки рисуем левую стену и объекты, находящиеся в ячейке.
    Для этих действий создадим метод DrawFrame в классе Game. Он должен получить текущий этаж на основе позиции игрока,
    а затем вызвать методы рисования всех объектов, пола и стен так, как описано выше.

    Отрисовка объектов
    В методе DrawFrame при отрисовке каждой клетки нужно изобразить объекты, которые находятся в этой клетке. Получить их список из object_map_:
    const auto& objects = object_map_.Get(pos);
    Пройдитесь циклом по всем объектам и нарисуйте их. При этом нужно проверить два условия:
    Объект является видимым, то есть его метод IsVisible возвращает true.
    Объект находится на текущей ячейке.
    Второе условие необходимо, так как объект может быть представлен в object_map_ несколько раз, а нарисовать его нужно только там, где он на самом деле расположен.
    */

    void DrawFrame(DrawContext draw_context){
        Floor current_floor = GetCurrentFloor(); //пол где стоит игрок
        current_floor.DrawFloor(draw_context); //рисуем пол

        //Ряд за рядом рисуем стены и объекты.

        for (int i = 0; i < field_.GetHeight()+1; ++i) { // y
            //qInfo() << "DrawHWalls y=" <<  QString::number(i);
            current_floor.DrawHWalls(draw_context, i);


            for (int j = 0; j < field_.GetWidth()+1; ++j) { // x - ряд
                Coordinate pos{i, j, current_floor.GetLevel()}; /* номер этажа */
                //qInfo() << "DrawFrame pos" <<  QString::fromStdString(ToString(pos));
                //Проходимся по ячейкам ряда слева направо.
                //У каждой ячейки рисуем левую стену и объекты, находящиеся в ячейке.
                current_floor.DrawVWall(draw_context, pos);

                //список объектов в клетке pos
                const auto& objects = context_.object_map.Get(pos);
                //qInfo() << "DrawFrame pos" <<  QString::fromStdString(ToString(pos))<< "objects" << QString::number(objects.size());;

                /*Пройдитесь циклом по всем объектам и нарисуйте их.
                 *  При этом нужно проверить два условия:
                 *  Объект является видимым, то есть его метод IsVisible возвращает true.
                 *  Объект находится на текущей ячейке.
                 *  Второе условие необходимо, так как объект может быть представлен в object_map_ несколько раз,
                 *  а нарисовать его нужно только там, где он на самом деле расположен.*/


                for (auto obj : objects){
                   /* qInfo() << "DrawFrame pos" <<  QString::fromStdString(ToString(pos))
                            << "visible" <<obj->IsVisible()
                            <<"obj_pos"<<QString::fromStdString(ToString(obj->GetPosition()));*/

                    if(obj->IsVisible() && obj->GetPosition() == pos){
                        //qInfo() << "DrawFrame pos" <<  QString::fromStdString(ToString(pos)) << "OBJECT EXIST, DRAW";
                        //нарисовать объект
                        obj->Draw(draw_context);
                    }
                }
            }
        }
    }
private:
    Field field_;
    Player* player_;
    ObjectMap<Object> object_map_;
    RandomGen random_;
    AssetLoader asset_loader_;
    GameContext context_{.object_map = object_map_, .field = field_, .random = random_, .asset_loader = asset_loader_};
};
