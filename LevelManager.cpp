//
// Created by wailer on 10/03/2022.
//

#include "LevelManager.h"

const int SCROLL_TRESHOLD = SCREEN_H/3;
const int PLATFORM_WIDTH = 114;
const double MAX_PLATFORM_DISTANCE = 210;
const double MIN_PLATFORM_DISTANCE = 40;
const double DISTANCE_RAMPUP = SCREEN_H*25;
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
        _total_distance+=(double)SCROLL_TRESHOLD - _player->getPosition().y;
    }
    while (_last_platform>PLATFORM_SPAWN_TRESHOLD)
        _getNextPlatform();
}

double clamp(double n, double min, double max) {
    if (n > max) return max;
    else if (n < min) return min;
    return n;
}

double LevelManager::getMinDistance() {
    return clamp(MIN_PLATFORM_DISTANCE + (MAX_PLATFORM_DISTANCE - MIN_PLATFORM_DISTANCE)*_total_distance/DISTANCE_RAMPUP, 0, MAX_PLATFORM_DISTANCE-10);
}

void LevelManager::_getNextPlatform() {
    _next_distance = randf(getMinDistance(), MAX_PLATFORM_DISTANCE);
    _last_platform -= _next_distance;
    auto *p = new Platform(Vector2(randf(0, SCREEN_W-PLATFORM_WIDTH), _last_platform));
    ScreenSaver::Instance().Add(p);
    PhysicsServer::Instance().Add(p);
}

void LevelManager::Reset() {
    _next_distance = 0.0;
    _last_platform = 700.0;
    _total_distance = 0.0;
}
