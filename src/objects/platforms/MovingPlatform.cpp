//
// Created by wailer on 03/04/2022.
//

#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(const Vector2 &position)
    : Platform(position, ResourceManager::Instance().sprite_platform_moving,
               PlayerInteraction::Bounce) {
    _velocity = util::randf(MIN_PLATFORM_SPEED, MAX_PLATFORM_SPEED);
    if (std::rand() % 2 == 0) _velocity = -_velocity;

    _width = GetImageSize().x;
}

void MovingPlatform::_update() {
    Platform::_update();

    _position.x += _velocity;

    if (_position.x < 0 || _position.x > SCREEN_W - _width)
        _velocity = -_velocity;

    _position.x = util::clamp(_position.x, 0.0, SCREEN_W - _width);
}
