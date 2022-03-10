//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_ALLEGRO_H
#define PROJECT_ALLEGRO_H

#include "AllegroBase.hpp"
#include "../PhysicsServer.h"
#include "../ScreenSaver.h"

class LevelManager;
LevelManager &Instance();
void Update();

class Allegro: public AllegroBase {
private:
    Allegro();
    PhysicsServer &_physics_server;
    ScreenSaver &_screen_saver;
    LevelManager &_level_manager;

public:
    static Allegro &Instance() {
        static Allegro instance;
        return instance;
    }

    ~Allegro() override = default;

    void Fps() override;
    void Draw() override;
    void Run() override;
};


#endif //PROJECT_ALLEGRO_H
