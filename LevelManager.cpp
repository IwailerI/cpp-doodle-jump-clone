//
// Created by wailer on 10/03/2022.
//

#include "LevelManager.h"

void LevelManager::Update() {
    if (_player->getPosition().y < SCROLL_TRESHOLD) {
        ScreenSaver::Instance().Offset(Vector2(0.0, (double)SCROLL_TRESHOLD-_player->getPosition().y));
        auto scroll = (double)SCROLL_TRESHOLD - _player->getPosition().y;
        _last_platform+=scroll;
        _last_enemy+=scroll;
        _total_distance+=scroll;
    }
    while (_last_platform > OBJECT_SPAWN_TRESHOLD)
        _genNextPlatform();

    while (_last_enemy > OBJECT_SPAWN_TRESHOLD)
        _genNextEnemy();
}

double LevelManager::getMinDistance() const {
    return util::clamp(MIN_PLATFORM_DISTANCE + (MAX_PLATFORM_DISTANCE - MIN_PLATFORM_DISTANCE)*_total_distance/DISTANCE_RAMPUP, 0, MAX_PLATFORM_DISTANCE-10);
}

void LevelManager::_genNextPlatform() {
    Platform *p = nullptr;
    if (util::randf(0, 1) <= FAKE_PLATFORM_CHANCE && 0) { // TODO remove && false and make actual fake platform
        // we are generating a fake platform
        _next_distance = util::clamp(_next_distance, getMinDistance()*2, MAX_PLATFORM_DISTANCE-getMinDistance());

        p = PlatformFactory::GetRandomPlatform(_last_platform+_next_distance, true);

        _next_distance = util::randf(getMinDistance(), MAX_PLATFORM_DISTANCE-_next_distance);

    } else {
        // we are generating a normal platform
        _last_platform -= _next_distance;

        p = PlatformFactory::GetRandomPlatform(_last_platform, false);

        _next_distance = util::randf(getMinDistance(), MAX_PLATFORM_DISTANCE);
    }

    ScreenSaver::Instance().Add(p);
    PhysicsServer::Instance().Add(p);
}

void LevelManager::_genNextEnemy() {
    _last_enemy -= util::randf(MIN_ENEMY_DISTANCE, MAX_ENEMY_DISTANCE);
    // TODO replace width
    auto *e = EnemyFactory::GetRandomEnemy(_last_enemy);
    ScreenSaver::Instance().Add(e);
    PhysicsServer::Instance().Add(e);
}

void LevelManager::Reset() {
    _next_distance = MIN_PLATFORM_DISTANCE+10;
    _last_platform = 700.0;
    _total_distance = 0.0;

    _last_enemy = -1000;
}

