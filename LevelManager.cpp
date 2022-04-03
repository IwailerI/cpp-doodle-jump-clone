//
// Created by wailer on 10/03/2022.
//

#include "LevelManager.h"

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
    while (_last_platform > OBJECT_SPAWN_TRESHOLD)
        _genNextPlatform();

    while (_last_enemy > OBJECT_SPAWN_TRESHOLD)
        _genNextEnemy();
}

double clamp(double n, double min, double max) {
    if (n > max) return max;
    else if (n < min) return min;
    return n;
}

double LevelManager::getMinDistance() const {
    return clamp(MIN_PLATFORM_DISTANCE + (MAX_PLATFORM_DISTANCE - MIN_PLATFORM_DISTANCE)*_total_distance/DISTANCE_RAMPUP, 0, MAX_PLATFORM_DISTANCE-10);
}

void LevelManager::_genNextPlatform() {
    _next_distance = randf(getMinDistance(), MAX_PLATFORM_DISTANCE);
    // TODO select platform type at random
    _last_platform -= _next_distance;
    auto *p = new Platform(Vector2(randf(0, SCREEN_W - _platform_width), _last_platform));
    ScreenSaver::Instance().Add(p);
    PhysicsServer::Instance().Add(p);
}

void LevelManager::_genNextEnemy() {
    _next_enemy_distance = randf(MIN_ENEMY_DISTANCE, MAX_ENEMY_DISTANCE);
    _last_enemy -= _next_enemy_distance;
    // TODO replace width
    auto *e = new Enemy(Vector2(randf(0, SCREEN_W - _platform_width), _last_enemy));
    ScreenSaver::Instance().Add(e);
    PhysicsServer::Instance().Add(e);
}

void LevelManager::Reset() {
    _next_distance = 0.0;
    _last_platform = 700.0;
    _total_distance = 0.0;

    _next_enemy_distance = 0.0;
    _last_enemy = 0;
}

