//
// Created by wailer on 05/03/2022.
//

#include "Sprite.h"

void Sprite::_draw() {
    if (_scale == Vector2(0, 0) && _rotation == 0) {
        al_draw_bitmap(_sprite, _position.x, _position.y)
    } else {
        al_draw_scaled_rotated_bitmap(_sprite, )
    }
}

void Sprite::_update() {

}

Sprite::Sprite(const Vector2 &position, double rotation, const Vector2 &scale, const ALLEGRO_BITMAP &sprite):
    GameObject(position, rotation, scale), _sprite(sprite)
    {}

Sprite::Sprite(const ALLEGRO_BITMAP &sprite) : _sprite(sprite) {}

const ALLEGRO_BITMAP &Sprite::getSprite() const {return _sprite;}
void Sprite::setSprite(const ALLEGRO_BITMAP &sprite) {_sprite = sprite;}
