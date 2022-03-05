//
// Created by wailer on 05/03/2022.
//

#include "Sprite.h"

void Sprite::_draw() {
//    if (_scale == Vector2(0, 0) && _rotation == 0) {
//        al_draw_bitmap(_sprite, _position.x, _position.y)
//    } else {
//        al_draw_scaled_rotated_bitmap(_sprite, )
//    }
    Vector2 pos2 = _position + _dimensions * _scale;;
    al_draw_filled_rectangle(_position.x,  _position.y, pos2.x, pos2.y, _color); // NOLINT(cppcoreguidelines-narrowing-conversions)
}

void Sprite::_update() {
    // do nothing, yay
}

Sprite::Sprite(const ALLEGRO_COLOR &color, const Vector2 &dimensions) : _color(color), _dimensions(dimensions) {}

//Sprite::Sprite(const Vector2 &position, double rotation, const Vector2 &scale, const ALLEGRO_BITMAP &sprite):
//    GameObject(position, rotation, scale), _sprite(sprite)
//    {}

//Sprite::Sprite(const ALLEGRO_BITMAP &sprite) : _sprite(sprite) {}

//const ALLEGRO_BITMAP &Sprite::getSprite() const {return _sprite;}
//void Sprite::setSprite(const ALLEGRO_BITMAP &sprite) {_sprite = sprite;}
