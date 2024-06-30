//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "../LevelManager.h"
#include "../PhysicsServer.h"
#include "../Player.h"
#include "../ScreenSaver.h"
#include "AllegroBase.hpp"

enum class State { TITLE, IN_GAME, END, PAUSE };

class Game : public AllegroBase {
   private:
    Game();
    PhysicsServer &_physics_server;
    ScreenSaver &_screen_saver;
    LevelManager &_level_manager;

    State _state = State::TITLE;

    void _start_game();
    void _update_player_input();

    std::shared_ptr<Player> _player = nullptr;

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

#endif  // PROJECT_GAME_H
