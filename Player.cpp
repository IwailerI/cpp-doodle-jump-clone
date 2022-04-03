//
// Created by wailer on 05/03/2022.
//

#include "Player.h"


void Player::_update() {
    _velocity.y += GRAVITY;

    if (_is_dead) {
        _position += _velocity;

        if (isCompletelyDead()) {
            setVisible(false);
            setSleeping(true);
        }

        return;
    }

    double input = is_right_held - is_left_held;;

    if (input != 0)
        if (input > 0)
            _sprite = ResourceManager::Instance().sprite_player_right;
        else
            _sprite = ResourceManager::Instance().sprite_player_left;


    _velocity.x = input * MOVEMENT_SPEED;

    _position += _velocity;
    if (_position.x < -GetImageSize().x) _position.x += SCREEN_W+GetImageSize().x;
    else if (_position.x > SCREEN_W) _position.x -= SCREEN_W+GetImageSize().x;

    if (_position.y > SCREEN_H) {
        die();
    }
}

void Player::onCollision(Collider *col) {
    if (isDead()) return;
    switch (col->getPlayerInteraction()) {
        case Bounce:
            if (_velocity.y > 0 && isColliding(col, true))
                _velocity.y = -JUMP_VELOCITY;
            break;
        case KillBounce:
            if (_velocity.y > 0 && isColliding(col, true)) {
                _velocity.y = -JUMP_VELOCITY;
                col->onCollision(nullptr); // make enemy kill itself
            } else
                die();
            break;
        case Kill:
            die();
            break;
    }
}

const Vector2 &Player::getVelocity() const {
    return _velocity;
}

void Player::setVelocity(const Vector2 &velocity) {
    _velocity = velocity;
}

Player::Player(Vector2 position) {
    _position = position;
    _velocity = Vector2(0, 0);
    _scale = Vector2(1, 1);
    _sprite = ResourceManager::Instance().sprite_player_right;
    _player_interaction = IsPlayer;

    _sprite_offset.y = -(GetImageSize().y-10);
    _sprite_offset.x = -(GetImageSize().x - getDimensions().x) * .5;
}

void Player::die() {
    std::cout << "Player is ded." << std::endl;
    _is_dead = true;
}

Vector2 Player::getPosition() const {
    return Sprite::getPosition();
}

Vector2 Player::_getDimensions(bool alternative) const {
    //return {58.0, 10.0};
    if (alternative)
        return {70.0, 10.0};
    else
        return GetImageSize();
}
