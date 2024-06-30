//
// Created by wailer on 03/04/2022.
//

#include "Spring.h"

Spring::Spring() {
    _sprite = ResourceManager::Instance().sprite_spring;
    _player_interaction = PlayerInteraction::Boost;
}

void Spring::onCollision(std::shared_ptr<Collider> col) {
    _sprite = ResourceManager::Instance().sprite_spring_triggered;
    _position.y -= 60;
}
