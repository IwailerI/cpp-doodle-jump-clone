//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_LEVELMANAGER_H
#define PROJECT_LEVELMANAGER_H

#include "objects/platforms/PlatformFactory.h"
#include "objects/enemies/EnemyFactory.h"

#include "ScreenSaver.h"
#include "PhysicsServer.h"
#include <cstdlib>

#include "util/utils.h"

class LevelManager {
private:
    LevelManager() {Reset();}
    double getMinDistance() const;

protected:
    GameObject *_player = nullptr;

    double _next_distance = 0.0;
    double _last_platform = 0.0;
    double _total_distance = 0.0;

    double _last_enemy = 0.0;

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
