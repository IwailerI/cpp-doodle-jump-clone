//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_LEVELMANAGER_H
#define PROJECT_LEVELMANAGER_H

// TODO replace with enemy abd platform factories
#include "objects/platforms/Platform.h"
#include "objects/enemies/Enemy.h"

#include "ScreenSaver.h"
#include "PhysicsServer.h"
#include <cstdlib>

class LevelManager {
private:
    LevelManager() {Reset();}
    double getMinDistance() const;

    double _platform_width = Platform::PlatformDimensions().x;

protected:
    GameObject *_player = nullptr;

    double _next_distance;
    double _last_platform;
    double _total_distance;

    double _next_enemy_distance;
    double _last_enemy;

    void _genNextPlatform();
    void _genNextEnemy();

public:
    static LevelManager &Instance() {
        static LevelManager instance;
        return instance;
    }

    void RegisterPlayer(GameObject *player) {_player = player;}

    void Update();

    void Reset();
};


#endif //PROJECT_LEVELMANAGER_H
