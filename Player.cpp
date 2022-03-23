//
// Created by wailer on 05/03/2022.
//

#include "Player.h"


void Player::_update() {
    _velocity.y += GRAVITY;

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
    if (col->getPlayerInteraction() == Bounce) {
        _velocity.y = -JUMP_VELOCITY;
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

    _sprite_offset.y = -(GetImageSize().y-10);
    _sprite_offset.x = -(GetImageSize().x - getDimensions().x) * .5;
}

Vector2 Player::getColliderVelocity() const {
    return _velocity;
}

void Player::die() {
    std::cout << "Player is ded." << std::endl;
    setSleeping(true);
    setVisible(false);
}

Vector2 Player::getPosition() const {
    return Sprite::getPosition();
}

Vector2 Player::getDimensions() const {
    //return {58.0, 10.0};
    return {70.0, 10.0};
}

void Player::_draw() {
    Sprite::_draw();
    al_draw_rectangle(getPosition().x, getPosition().y, getPosition().x+getDimensions().x, getPosition().y+getDimensions().y,
                      al_map_rgb(0, 255, 0), 1);
}
