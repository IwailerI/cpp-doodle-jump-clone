//
// Created by wailer on 05/03/2022.
//

#include "Sprite.h"

// i cannot be bothered to include cmath for one constant
const double pi = 3.141592653589793238462643383279502884;

float deg2rad(double degrees) {
    return degrees * (pi / 180);
}

void Sprite::_draw() {
    if (_scale == Vector2(0, 0) && _rotation == 0) {
        al_draw_bitmap(_sprite, _position.x+_sprite_offset.x, _position.y+_sprite_offset.y, 0);
    } else {
        Vector2 size = GetImageSize()*_scale;
        al_draw_scaled_rotated_bitmap(
                _sprite,
                size.x*.5, size.y*.5,
                _position.x + (_sprite_offset.x*_scale.x) + size.x*.5,
                _position.y + (_sprite_offset.y*_scale.y) + size.y*.5,
                _scale.x, _scale.y,
                deg2rad(_rotation),
                0
                );\
    }
//    Vector2 pos2 = _position + _dimensions * _scale;;
//    al_draw_filled_rectangle(_position.x,  _position.y, pos2.x, pos2.y, _color); // NOLINT(cppcoreguidelines-narrowing-conversions)
}

void Sprite::_update() {
    // do nothing, yay
}

Sprite::Sprite(const Vector2 &position, ALLEGRO_BITMAP *sprite) : GameObject(
        position, 0, Vector2(1, 1)), _sprite(sprite) {}

const Vector2 Sprite::GetImageSize() const { // NOLINT(readability-const-return-type)
    return Vector2(al_get_bitmap_width(_sprite), al_get_bitmap_height(_sprite)) * _scale;
}

//Sprite::Sprite(const Vector2 &position, double rotation, const Vector2 &scale, const ALLEGRO_BITMAP &sprite):
//    GameObject(position, rotation, scale), _sprite(sprite)
//    {}

//Sprite::Sprite(const ALLEGRO_BITMAP &sprite) : _sprite(sprite) {}

//const ALLEGRO_BITMAP &Sprite::getSprite() const {return _sprite;}
//void Sprite::setSprite(const ALLEGRO_BITMAP &sprite) {_sprite = sprite;}
