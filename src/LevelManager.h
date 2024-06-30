//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_LEVEL_MANAGER_H
#define PROJECT_LEVEL_MANAGER_H

#include "PhysicsServer.h"
#include "ScreenSaver.h"
#include "objects/enemies/EnemyFactory.h"
#include "objects/platforms/PlatformFactory.h"
#include "util/utils.h"

class LevelManager {
   private:
    LevelManager() { Reset(); }
    double getMinDistance() const;

   protected:
    std::shared_ptr<GameObject> _player = nullptr;

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

    void RegisterPlayer(std::shared_ptr<GameObject> player) {
        _player = player;
    }

    void Update();

    void Reset();
};

#endif  // PROJECT_LEVEL_MANAGER_H
