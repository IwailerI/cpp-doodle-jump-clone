//
// Created by wailer on 05/03/2022.
//

#include "Player.h"

void Player::_update() {
    _velocity.y += GRAVITY;
    double input = 0.0;

//    if (AllegroBase::IsPressed(ALLEGRO_KEY_LEFT)) input--;
//    if

    _position += _velocity;
}

void Player::onCollision(Collider *col) {
    if (col->getPlayerInteraction() == Bounce) {
        _velocity.y = -JUMP_VELOCITY;
    }
}

const Vector2 &Player::getPosition() const {
    return _position;
}

const Vector2 &Player::getDimensions() const {
    return _dimensions;
}

const Vector2 &Player::getVelocity() const {
    return _velocity;
}

void Player::setVelocity(const Vector2 &velocity) {
    _velocity = velocity;
}

Player::Player(Vector2 position) {
    _position = position;
    _color = al_map_rgb(255, 0, 0);
    _dimensions = Vector2(25, 50);

    _velocity = Vector2(0, 0);
}

Vector2 Player::getColliderVelocity() const {
    return _velocity;
}