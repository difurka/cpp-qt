#pragma once

#ifdef PRAC_TESTS
#include "../tests/model.h"
#include "../tests/view.h"
#else
#include "model.h"
#include "view.h"
#endif

class Controller {
public:

<<<<<<< HEAD
    Controller() {

        auto start_game = [this] (size_t size_x,size_t size_y) {
            model_.Reset(size_x, size_y);
            view_.SetupField(size_x,size_y);
            Rewrite();
        };

        auto move_player = [this](size_t x,size_t y) {
            Symbol symbol = model_.DoMove(x, y);
            if (symbol == Symbol::kEmpty) return;
            view_.UpdateCell(x, y, ToQString(symbol));
            Rewrite();
        };

        view_.SetNewgameCallback(start_game);
        view_.SetMoveCallback(move_player);
        start_game(3,3);
        view_.show();
    }

    void Rewrite() {
        auto winner = model_.GetWinner();
        if (!winner) {
            Symbol symbol = model_.GetNextPlayer();
            QString text = "Ход игрока " + ToQString(symbol);
            view_.SetStatus(text);
            view_.SetStatusStyle("black", false);
        } else if (winner.value() == Symbol::kEmpty) {
            view_.SetStatus("Ничья");
            view_.SetStatusStyle("red", true);
        } else {
            Symbol symbol = winner.value();
            QString text = "Выиграл " + ToQString(symbol);
            view_.SetStatus(text);
            view_.SetStatusStyle("green", true);
            auto win = model_.GetWinnerPath();
            for (auto [x, y] : win) {
                view_.SetCellStyle(x, y, "green", true);
            }
        }
    }
=======
    // Напишите контроллер.
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))

private:
    Model model_;
    View view_;
};
