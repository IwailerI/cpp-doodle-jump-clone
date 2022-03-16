//
// Created by wailer on 05/03/2022.
//

#include "Player.h"


void Player::_update() {
    _velocity.y += GRAVITY;
    double input = 0.0;

    if (allegro.IsPressed(ALLEGRO_KEY_LEFT) || allegro.IsPressed(ALLEGRO_KEY_A))
        input--;
    if (allegro.IsPressed(ALLEGRO_KEY_RIGHT) || allegro.IsPressed(ALLEGRO_KEY_D))
        input++;

    _velocity.x = input * MOVEMENT_SPEED;

    _position += _velocity;
    if (_position.x < 0) _position.x += SCREEN_W;
    else if (_position.x > SCREEN_W) _position.x -= SCREEN_W;

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

Player::Player(Vector2 position): allegro(Allegro::Instance()) {
    _position = position;
    _velocity = Vector2(0, 0);
    _scale = Vector2(1, 1);
    _sprite = ResourceManager::Instance().sprite_player;

    _sprite_offset.y = -(GetImageSize().y-20);
    _sprite_offset.x = -32.0;
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
    return {58.0, 10.0};
}

void Player::_draw() {
    Sprite::_draw();
    al_draw_rectangle(getPosition().x, getPosition().y, getPosition().x+getDimensions().x, getPosition().y+getDimensions().y,
                      al_map_rgb(0, 255, 0), 1);
}
