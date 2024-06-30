//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "AllegroBase.hpp"
#include "../PhysicsServer.h"
#include "../ScreenSaver.h"
#include "../LevelManager.h"
#include "../Player.h"

enum STATE {TITLE, INGAME, END, PAUSE};

class Game: public AllegroBase {
private:
    Game();
    PhysicsServer &_physics_server;
    ScreenSaver &_screen_saver;
    LevelManager &_level_manager;

    STATE _state = TITLE;

    void _start_game();
    void _update_player_input();

    Player *_player = nullptr;

public:
    static Game &Instance() {
        static Game instance;
        return instance;
    }

    ~Game() override = default;

    void Fps() override;
    void Draw() override;
    void Run() override;
};


#endif //PROJECT_GAME_H
