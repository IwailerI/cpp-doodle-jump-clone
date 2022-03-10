//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_LEVELMANAGER_H
#define PROJECT_LEVELMANAGER_H

#include "ScreenSaver.h"

class LevelManager {
private:
    LevelManager(): _screen_saver(ScreenSaver::Instance()) {};

protected:
    ScreenSaver &_screen_saver;
    GameObject *_player;

public:
    static LevelManager &Instance() {
        static LevelManager instance;
        return instance;
    }

    void RegisterPlayer(GameObject *player) {_player = player;}

    void Update();
};


#endif //PROJECT_LEVELMANAGER_H
