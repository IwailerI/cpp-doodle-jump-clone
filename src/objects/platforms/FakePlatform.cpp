//
// Created by wailer on 03/04/2022.
//

#include "FakePlatform.h"

FakePlatform::FakePlatform(const Vector2 &position)
    : Platform(position, ResourceManager::Instance().sprite_platform_fake,
               PlayerInteraction::Break) {}

void FakePlatform::_update() {
    Platform::_update();
    if (_broken) {
        _velocity += GRAVITY;
        _position.y += _velocity;
    }
}

void FakePlatform::onCollision(std::shared_ptr<Collider> col) {
    if (col == nullptr) demolish();
}

void FakePlatform::demolish() {
    _broken = true;
    _sprite = ResourceManager::Instance().sprite_platform_fake_broken;
}
