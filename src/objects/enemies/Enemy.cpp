//
// Created by wailer on 23/03/2022.
//

#include "Enemy.h"

Enemy::Enemy(Vector2 position) : Sprite() {
    _sprite = ResourceManager::Instance().sprite_enemy_simple;
    _victory_sprite = ResourceManager::Instance().sprite_enemy_simple_victory;
    _death_sprite = ResourceManager::Instance().sprite_enemy_simple_dead;
    _position = position;
    _player_interaction = PlayerInteraction::KillBounce;
}

Vector2 Enemy::_getColliderPosition(bool alternative) const {
    return Sprite::getPosition();
}

Vector2 Enemy::_getDimensions(bool alternative) const { return GetImageSize(); }

void Enemy::onCollision(std::shared_ptr<Collider> col) {
    if (col == nullptr) {
        die();
        return;
    }

    // we killed the player
    if (col->getPlayerInteraction() == PlayerInteraction::IsPlayer &&
        !_is_dead) {
        _victory();
    }
}

void Enemy::die() {
    //_rotation = 180;
    _sprite = _death_sprite;
    _is_dead = true;
}

void Enemy::_victory() { _sprite = _victory_sprite; }

void Enemy::_delete() {
    if (isMarkedForDeletion() || isMarkedForObjectDeletion()) return;
    _visible = false;
    if (_object_id != -1) {
        markForObjectDeletion();
    }
    if (_physics_id != -1) {
        markForDeletion();
    }
}

void Enemy::_update() {
    if (_is_dead) {
        //        _sprite =
        //        ResourceManager::Instance().sprite_enemy_simple_dead;

        _death_velocity.y += GRAVITY;
        _position += _death_velocity;
    }
    if (_position.y > OBJECT_DELETE_THRESHOLD) {
        if (GameObject::_position.y >= OBJECT_DELETE_THRESHOLD) {
            _delete();
        }
    }
}