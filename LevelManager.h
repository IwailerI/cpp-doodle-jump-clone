//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_LEVELMANAGER_H
#define PROJECT_LEVELMANAGER_H

#include "objects/platforms/Platform.h"
#include "ScreenSaver.h"
#include "PhysicsServer.h"
#include <cstdlib>

class LevelManager {
private:
    LevelManager();
    double getMinDistance();

protected:
    GameObject *_player = nullptr;

    double _next_distance = 0.0;
    double _last_platform = 700.0;
    double _total_distance = 0.0;

    void _getNextPlatform();

public:
    static LevelManager &Instance() {
        static LevelManager instance;
        return instance;
    }

    void RegisterPlayer(GameObject *player) {_player = player;}

    void Update();
};


#endif //PROJECT_LEVELMANAGER_H
