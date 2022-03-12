//
// Created by wailer on 10/03/2022.
//

#include "LevelManager.h"

const int SCROLL_TRESHOLD = SCREEN_H/3;
const int PLATFORM_WIDTH = 100;
const double MAX_PLATFORM_DISTANCE = 100;
const double MIN_PLATFORM_DISTANCE = 40;
const double PLATFORM_SPAWN_TRESHOLD = -10;

double randf(double min, double max) {
    double f = std::rand();
    f /= RAND_MAX;
    f *= max-min;
    return f + min;
}

void LevelManager::Update() {
    if (_player->getPosition().y < SCROLL_TRESHOLD) {
        ScreenSaver::Instance().Offset(Vector2(0.0, (double)SCROLL_TRESHOLD-_player->getPosition().y));
        _last_platform+=(double)SCROLL_TRESHOLD - _player->getPosition().y;
    }
    while (_last_platform>PLATFORM_SPAWN_TRESHOLD)
        _getNextPlatform();
}

void LevelManager::_getNextPlatform() {
    _next_distance = randf(MIN_PLATFORM_DISTANCE, MAX_PLATFORM_DISTANCE);
    _last_platform -= _next_distance;
    auto *p = new Platform(Vector2(randf(0, SCREEN_W-PLATFORM_WIDTH), _last_platform));
    ScreenSaver::Instance().Add(p);
    PhysicsServer::Instance().Add(p);
}

LevelManager::LevelManager() {

}
