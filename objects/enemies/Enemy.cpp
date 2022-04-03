//
// Created by wailer on 23/03/2022.
//

#include "Enemy.h"

Enemy::Enemy(Vector2 position): Sprite()
{
    _sprite = ResourceManager::Instance().sprite_enemy_simple;
    _victory_sprite = ResourceManager::Instance().sprite_enemy_simple_victory;
    _death_sprite = ResourceManager::Instance().sprite_enemy_simple_dead;
    _position = position;
    _player_interaction = KillBounce;
}

Vector2 Enemy::_getColliderPosition(bool alternative) const {
    return Sprite::getPosition();
}

Vector2 Enemy::_getDimensions(bool alternative) const {
    return GetImageSize();
}

void Enemy::onCollision(Collider *col) {
    if (col == nullptr)  {die(); return;} // suicide on command lol

    if (col->getPlayerInteraction() == IsPlayer)
        // we killed the player
        if (!_is_dead)
            _victory();
}

void Enemy::die() {
    _rotation = 180;
    _sprite = _death_sprite;
    _is_dead = true;
}

void Enemy::_victory() {
    _sprite = _victory_sprite;
}

void Enemy::_delete() {
    if (_marked_for_object_deletion != 0 || _marked_for_physics_deletion != 0) return;

    _visible = false;
    if (_physics_id != -1 && _object_id != -1) {
        markForObjectDeletion(true);
        markForPhysicsDeletion(false);
    } else if (_object_id != -1) {
        markForObjectDeletion(true);
    } else if (_physics_id != -1) {
        markForPhysicsDeletion(true);
    } else
        delete this;
}

void Enemy::_update() {
    if (_is_dead) {
//        _sprite = ResourceManager::Instance().sprite_enemy_simple_dead;

        _death_velocity.y += GRAVITY;
        _position += _death_velocity;
    }
    if (_position.y > OBJECT_DELETE_TRESHOLD) {
        if (GameObject::_position.y >= OBJECT_DELETE_TRESHOLD) {
            _delete();
        }
    }
}