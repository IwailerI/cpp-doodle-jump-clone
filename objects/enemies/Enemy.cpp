//
// Created by wailer on 23/03/2022.
//

#include "Enemy.h"

Enemy::Enemy(Vector2 position): Sprite()
{
    _sprite = ResourceManager::Instance().sprite_enemy_simple;
    _position = position;
    _player_interaction = Kill;
}

Vector2 Enemy::getPosition() const {
    return Sprite::getPosition();
}

Vector2 Enemy::getDimensions() const {
    return GetImageSize();
}

void Enemy::onCollision(Collider *col) {
    if (col->getPlayerInteraction() == IsPlayer) die();
}

void Enemy::die() {

}
