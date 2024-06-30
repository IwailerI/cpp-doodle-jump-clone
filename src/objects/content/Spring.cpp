//
// Created by wailer on 03/04/2022.
//

#include "Spring.h"

Spring::Spring() {
    _sprite = ResourceManager::Instance().sprite_spring;
    _player_interaction = Boost;
}

void Spring::onCollision(Collider *col) {
    _sprite = ResourceManager::Instance().sprite_spring_triggered;
//    _position.y -= 30;
    _position.y -= 60;
}
