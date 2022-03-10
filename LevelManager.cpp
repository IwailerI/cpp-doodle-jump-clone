//
// Created by wailer on 10/03/2022.
//

#include "LevelManager.h"

const int SCROLL_TRESHOLD = SCREEN_H/3;

void LevelManager::Update() {
    if (_player->getPosition().y < SCROLL_TRESHOLD) {
        _screen_saver.Offset(Vector2(0.0, (double)SCROLL_TRESHOLD-_player->getPosition().y));
    }
}
