//
// Created by wailer on 01/03/2022.
//

#include "ColorRect.h"

ColorRect::ColorRect(const Vector2 &position, const ALLEGRO_COLOR &color, const Vector2 &dimensions):
    GameObject(position, 0, Vector2(1,1)), _color(color), _dimensions(dimensions), _thickness(1)
    {}

ColorRect::ColorRect(const Vector2 &position, const Vector2 &dimensions):
    GameObject(position, 0, Vector2(1,1)), _color(al_map_rgb(255,255,255)), _dimensions(dimensions), _thickness(1)
    {}

ColorRect::ColorRect():
    GameObject(), _color(al_map_rgb(255, 255, 255)), _thickness(1)
    {}

const ALLEGRO_COLOR &ColorRect::getColor() const {
    return _color;
}

void ColorRect::setColor(const ALLEGRO_COLOR &color) {
    _color = color;
}

const Vector2 &ColorRect::getDimensions() const {
    return _dimensions;
}

void ColorRect::setDimensions(const Vector2 &dimensions) {
    _dimensions = dimensions;
}

bool ColorRect::isFilled() const {
    return _filled;
}

void ColorRect::setFilled(bool filled) {
    _filled = filled;
}

double ColorRect::getThickness() const {
    return _thickness;
}

void ColorRect::setThickness(float thickness) {
    _thickness = thickness;
}

void ColorRect::_draw() {
    Vector2 pos2 = _position + _dimensions * _scale;
    if (_filled)
        al_draw_filled_rectangle(_position.x,  _position.y, pos2.x, pos2.y, _color); // NOLINT(cppcoreguidelines-narrowing-conversions)
    else
        al_draw_rectangle(_position.x,  _position.y, pos2.x, pos2.y, _color, _thickness); // NOLINT(cppcoreguidelines-narrowing-conversions)
}

void ColorRect::_update() {
    // do nothing ¯\_(ツ)_/¯
    // it just a rectangle, it's enjoying its life, leave it alone
}

double ColorRect::getRotation() const {
    return 0.0;
}

void ColorRect::setRotation(double rotation) {
    // do nothing, can't rotate a simple, axis aligned rect
}
