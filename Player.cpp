//
// Created by wailer on 05/03/2022.
//

#include "Player.h"

void Player::_update() {
    Sprite::_update();
}

void Player::onCollision(Collider *col) {
    std::cout << "hit something" << std::endl;
}
